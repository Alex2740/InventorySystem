// Copyright (c) 2023, Me&Myself. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/Object.h"
#include "ISSlot.generated.h"

USTRUCT(BlueprintType)
struct FISSlot : public FTableRowBase
{
	GENERATED_BODY()

	FText Name;
	FText Description;
	//UTexture2D Thumbnail;
	TSubclassOf<AActor> ItemClass;
	int StackSize;
};
