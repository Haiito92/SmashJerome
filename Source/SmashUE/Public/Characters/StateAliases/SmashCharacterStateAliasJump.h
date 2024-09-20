// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/SmashCharacterStateAlias.h"
#include "SmashCharacterStateAliasJump.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SMASHUE_API USmashCharacterStateAliasJump : public USmashCharacterStateAlias
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void SubscribeToInputEvents() override;

	UFUNCTION()
	void OnJumpEvent();
};
