// Copyright (c) 2023, Me&Myself. All Rights Reserved.

#include "Core/ISInventoryComponent.h"
#include "Core/ISItemActor.h"

void AISItemActor::DoInteract(AActor* InstigatorIn)
{
	if (UISInventoryComponent* InventoryComponent = Cast<UISInventoryComponent>(InstigatorIn->GetComponentByClass(UISInventoryComponent::StaticClass())))
	{
		const int QuantityRemaining = InventoryComponent->AddToInventory(ItemID.RowName, Quantity);

		if (QuantityRemaining > 0)
		{
			Quantity = QuantityRemaining;
		}

		if (QuantityRemaining == 0)
		{
			Destroy();
		}
	}
}