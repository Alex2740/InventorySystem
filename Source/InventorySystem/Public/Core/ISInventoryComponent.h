// Copyright (c) 2023, Me&Myself. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ISInventoryComponent.generated.h"


struct FISSlot;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INVENTORYSYSTEM_API UISInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

	void AddToInventory();
	void RemoveFromInventory();

	int Size;

	TArray<FISSlot> Content;
};
