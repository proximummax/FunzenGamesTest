// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FunzenGameTestGameInstance.h"
#include "Character/BaseCharacter.h"
#include "SquadController.generated.h"

UCLASS()
class FUNZENGAMESTEST_API ASquadController : public APlayerController
{
	GENERATED_BODY()
	
public:	
	ASquadController();

	UPROPERTY()
	TArray<ABaseCharacter*> ControlledUnits;

protected:
	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;
	void EnableTick();

	void SetSquadParametersByIndex(int32 SquadInd);
	void SetActionsTimer();
private:
	FTimerHandle StartActionsTimerHandle;

	int32 TimeToStartActions;

	int32 DistanceToStartAttack;

	FVector EnemyLocation;

	UPROPERTY()
	UFunzenGameTestGameInstance* GameInstance;
};
