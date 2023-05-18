// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PauseController.generated.h"

UCLASS()
class FUNZENGAMESTEST_API APauseController : public AActor
{
	GENERATED_BODY()
	
public:	
	APauseController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EndGame")
	int32 TimeToEndGame = 120;
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle GameTimerHandle;

	void EndGame();
};
