// Copyright (c) 2023, Me&Myself. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/Object.h"
#include "ISItem.generated.h"

USTRUCT(BlueprintType)
struct FISItem : public FTableRowBase
{
	GENERATED_BODY()
	
	FText Name;
	FText Description;
	//UTexture2D Thumbnail;
	TSubclassOf<AActor> ItemClass;
	int StackSize;
};
