// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/SmashCharacterStateAlias.h"
#include "SmashCharacterStateAliasFall.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SMASHUE_API USmashCharacterStateAliasFall : public USmashCharacterStateAlias
{
	GENERATED_BODY()

	virtual void StateAliasTick(float DeltaTime) override;
};
