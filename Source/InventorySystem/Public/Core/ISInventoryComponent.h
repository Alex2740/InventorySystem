// Copyright (c) 2023, Me&Myself. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "ISInventoryComponent.generated.h"


struct FISSlot;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INVENTORYSYSTEM_API UISInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
	int AddToInventory(FName ItemID, int Quantity);
	void RemoveFromInventory();

protected:
	int Size;
	
	UPROPERTY()
	TArray<FISSlot> Content;
	UPROPERTY()
	UDataTable* ItemDataTable;

	int FindSlot(FName ItemID);
	int GetMaxStackSize(FName ItemID);
	void AddToStack(int Index, int Quantity);
	int FindEmptySlot();
	void CreateStack(int Index, FName ItemID, int Quantity);
};
