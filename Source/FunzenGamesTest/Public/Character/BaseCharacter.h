// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class FUNZENGAMESTEST_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	ABaseCharacter();

	UFUNCTION(BlueprintCallable)
	bool IsNeedAttack() { return NeedAttack; }

	bool NeedAttack = false;
protected:

	virtual void BeginPlay() override;

private:
	
};

