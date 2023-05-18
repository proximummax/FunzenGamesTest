// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"

#include "SquadController.h"
#include "Character/BaseCharacter.h"
#include "Components/CapsuleComponent.h"



ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	GameInstance = GetWorld()->GetGameInstance<UFunzenGameTestGameInstance>();
	check(GameInstance);

	SpawnSquads(GameInstance->SpawnData);
}

void ASpawner::SpawnSquad(FSquadSpawnData SpawnData)
{
	const auto World = GetWorld();
	if (!World) 
		return;

	const auto Character = NewObject<ABaseCharacter>(SpawnData.UnitType);
	if (!Character) 
		return;

	ASquadController* SquadController = SpawnSquadController();
	if (!SquadController)
		return;

	SquadController->SetSquadParametersByIndex(SpawnData.SquadIndex);

	const FVector InitLocation = SpawnData.InitTransform.GetLocation();
	float CurrentOffsetBetweenRows = 0.0f;
	for (int i = 0; i < SpawnData.UnitsInRow; i++)
	{
		float CurrentOffsetBetweenColumns = 0.0f;

		CurrentOffsetBetweenRows += Character->GetCapsuleComponent()->GetCollisionShape().Capsule.Radius + SpawnData.OffsetBetweenRows;

		for (int j = 0; j < SpawnData.UnitsInColumn; j++)
		{
			CurrentOffsetBetweenColumns += Character->GetCapsuleComponent()->GetCollisionShape().Capsule.Radius + SpawnData.OffsetBetweenColumns;

			FVector SpawnLocation = FVector(InitLocation.X + CurrentOffsetBetweenRows, InitLocation.Y + CurrentOffsetBetweenColumns, InitLocation.Z);

			ABaseCharacter* SpawnedCharacter = World->SpawnActor<ABaseCharacter>(SpawnData.UnitType, SpawnLocation, SpawnData.InitTransform.Rotator());
			if (!SpawnedCharacter)
				return;
			SpawnedCharacter->SpawnDefaultController();

			SquadController->ControlledUnits.Add(SpawnedCharacter);
		}
	}

	SquadController->SetActionsTimer();
}

void ASpawner::SpawnSquads(TArray<FSquadSpawnData> SpawnData)
{
	for (const auto SquadData : SpawnData)
	{
		SpawnSquad(SquadData);
	}
}

ASquadController* ASpawner::SpawnSquadController() const
{
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Instigator = GetInstigator();
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnInfo.OverrideLevel = GetLevel();

	ASquadController* SquadController = GetWorld()->SpawnActor<ASquadController>(GameInstance->SquadController, GetActorLocation(), GetActorRotation(), SpawnInfo);
	return SquadController;
}




