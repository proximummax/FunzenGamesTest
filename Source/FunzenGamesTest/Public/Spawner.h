// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FunzenGameTestGameInstance.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"


UCLASS()
class FUNZENGAMESTEST_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawner();

protected:
	virtual void BeginPlay() override;

private:
	
	void SpawnSquad(FSquadSpawnData SquadData);
	void SpawnSquads(TArray<FSquadSpawnData> SquadsData);

	UPROPERTY()
	UFunzenGameTestGameInstance* GameInstance;

	ASquadController* SpawnSquadController() const;
};
