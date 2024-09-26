// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/SmashCharacterState.h"
#include "SmashCharacterStateAttack.generated.h"

/**
 * 
 */
UCLASS()
class SMASHUE_API USmashCharacterStateAttack : public USmashCharacterState
{
	GENERATED_BODY()

public:
	virtual ESmashCharacterStateID GetStateID() override;

	virtual void StateEnter(ESmashCharacterStateID PreviousState) override;

	virtual void StateExit(ESmashCharacterStateID NextState) override;

	virtual void StateTick(float DeltaTime) override;

private:
	UPROPERTY()
	FTimerHandle AnimationLengthTimerHandle;

	UFUNCTION()
	void OnAnimationLengthTimerElapsed() const;
	
#pragma region Overriden Functions
	virtual void OnJumpEvent() override;

	virtual void CheckIfIsFalling() override;
	
	virtual void OnAttackEvent() override;
#pragma endregion 
};
