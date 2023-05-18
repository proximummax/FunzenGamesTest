// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FunzenGamesTest/DataStructs.h"
#include "FunzenGameTestGameInstance.generated.h"

class ASquadController;
UCLASS()
class FUNZENGAMESTEST_API UFunzenGameTestGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawn")
	TArray<FSquadSpawnData> SpawnData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Squad")
	TArray<FSquadData> SquadData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Controller")
	TSubclassOf<ASquadController> SquadController;

};
