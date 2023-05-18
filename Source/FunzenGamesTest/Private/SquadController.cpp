// Fill out your copyright notice in the Description page of Project Settings.

//ÎÑÒÀÍÎÂÊÀ ÑÈÌÓËßÖÈÈ)

#include "SquadController.h"

#include "FunzenGameTestGameInstance.h"
#include "GameFramework/Character.h"

ASquadController::ASquadController()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.SetTickFunctionEnable(true);
}

void ASquadController::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.SetTickFunctionEnable(false);

	GameInstance = GetWorld()->GetGameInstance<UFunzenGameTestGameInstance>();

	check(GameInstance);
}

void ASquadController::SetActionsTimer()
{
	GetWorldTimerManager().SetTimer(StartActionsTimerHandle, this, &ASquadController::EnableTick, TimeToStartActions, false);
}


void ASquadController::EnableTick()
{
	PrimaryActorTick.SetTickFunctionEnable(true);
}

void ASquadController::Tick(float DeltaTime)
{
	for (const auto Unit : ControlledUnits)
	{
		FVector Direction =  EnemyLocation - Unit->GetActorLocation();

		if (Direction.Size() <= DistanceToStartAttack)
		{
			Unit->NeedAttack = true;
		}
		else
		{
			Direction.Normalize();
			Unit->AddMovementInput(Direction, 1.0f);
		}
	}
}

void ASquadController::SetSquadParametersByIndex(int32 SquadInd)
{
	for (auto SquadData : GameInstance->SquadData)
	{
		if (SquadData.SquadIndex != SquadInd)
			continue;

		TimeToStartActions = SquadData.TimeToStartActions;
		DistanceToStartAttack = SquadData.DistanceToStartAttack;
		EnemyLocation = SquadData.EnemyLocation;

		break;
	}
}

