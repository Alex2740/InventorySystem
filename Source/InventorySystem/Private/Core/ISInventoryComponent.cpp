// Copyright (c) 2023, Me&Myself. All Rights Reserved.


#include "Core/ISInventoryComponent.h"

#include "Core/ISItem.h"
#include "Core/ISSlot.h"

void UISInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	Content.SetNum(Size);
}

int UISInventoryComponent::AddToInventory(const FName ItemID, const int Quantity)
{
	int QuantityRemaining = Quantity;
	bool bHasFailed = false;

	while (!bHasFailed && QuantityRemaining > 0)
	{
		const int SlotIndex = FindSlot(ItemID);
		if (SlotIndex >= 0)
		{
			AddToStack(SlotIndex, 1);
			QuantityRemaining--;
		}
		else
		{
			const int EmptySlotIndex = FindEmptySlot();
			if (EmptySlotIndex >= 0)
			{
				CreateStack(EmptySlotIndex, ItemID, 1);
				QuantityRemaining--;
			}
			else
			{
				bHasFailed = true;
			}
		}
	}

	return QuantityRemaining;
}

void UISInventoryComponent::RemoveFromInventory()
{
}

int UISInventoryComponent::FindSlot(const FName ItemID)
{
	for (int i = 0; i < Content.Num(); ++i)
	{
		FISSlot Slot = Content[i];
		if (Slot.ItemID == ItemID)
		{
			if (Slot.Quantity < GetMaxStackSize(ItemID))
			{
				return i;
			}
		}
	}

	return -1;
}

int UISInventoryComponent::GetMaxStackSize(const FName ItemID)
{
	if (const FISItem* ItemInfo = ItemDataTable->FindRow<FISItem>(ItemID, ""))
	{
		return ItemInfo->StackSize;
	}

	return -1;
}

void UISInventoryComponent::AddToStack(const int Index, const int Quantity)
{
	Content[Index].Quantity += Quantity;
}

int UISInventoryComponent::FindEmptySlot()
{
	for (int i = 0; i < Content.Num(); ++i)
	{
		const FISSlot Slot = Content[i];
		if (Slot.Quantity == 0)
		{
			return i;
		}
	}

	return -1;
}

void UISInventoryComponent::CreateStack(const int Index, const FName ItemID, const int Quantity)
{
	Content[Index].ItemID = ItemID;
	Content[Index].Quantity = Quantity;
}
