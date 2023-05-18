// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseController.h"

APauseController::APauseController()
{
	PrimaryActorTick.bCanEverTick = false;

}

void APauseController::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(GameTimerHandle, this, &APauseController::EndGame, TimeToEndGame, false);

}

void APauseController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APauseController::EndGame()
{
	if (!GetWorld())
		return;

	APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
	if (MyPlayer != nullptr)
	{
		MyPlayer->SetPause(true);
	}
}
