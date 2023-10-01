// Copyright (c) 2023, Me&Myself. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ISItem.generated.h"

USTRUCT(BlueprintType)
struct FISItem
{
	GENERATED_BODY()

	FName ItemID;
	int Quantity;
};
