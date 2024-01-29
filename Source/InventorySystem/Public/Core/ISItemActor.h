// Copyright (c) 2023, Me&Myself. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/ISInteractiveActor.h"
#include "Engine/DataTable.h"
#include "ISItemActor.generated.h"

UCLASS()
class INVENTORYSYSTEM_API AISItemActor : public AISInteractiveActor
{
	GENERATED_BODY()

protected:
	virtual void DoInteract(AActor* InstigatorIn) override;

	FDataTableRowHandle ItemID;
	int Quantity;
};
