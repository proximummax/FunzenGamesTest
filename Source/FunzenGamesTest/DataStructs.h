#pragma once
#include "Engine/TriggerBox.h"

#include "DataStructs.generated.h"

class ABaseCharacter;

USTRUCT(BlueprintType)
struct FSquadSpawnData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	int32 SquadIndex;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	TSubclassOf<ABaseCharacter> UnitType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	int32 OffsetBetweenRows;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	int32 OffsetBetweenColumns;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	int32 UnitsInRow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	int32 UnitsInColumn;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Spawn")
	FTransform InitTransform;
	
};

USTRUCT(BlueprintType)
struct FSquadData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Squad")
	int32 SquadIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Squad")
	int32 TimeToStartActions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Squad")
	int32 DistanceToStartAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Squad")
	FVector EnemyLocation;
};