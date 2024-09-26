// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/SmashCharacterStateAttack.h"

#include "Characters/SmashCharacterStateID.h"
#include "Characters/SmashCharacterStateMachine.h"

ESmashCharacterStateID USmashCharacterStateAttack::GetStateID()
{
	return ESmashCharacterStateID::Attack;
}

void USmashCharacterStateAttack::StateEnter(ESmashCharacterStateID PreviousState)
{
	Super::StateEnter(PreviousState);
	
	// GEngine->AddOnScreenDebugMessage(
	// 	-1,
	// 	3.0f,
	// 	FColor::Emerald,
	// 	FString::Printf(TEXT("Enter Attack State")));

	float const AnimationLength = StateAnimMontage->CalculateSequenceLength();
	GetWorld()->GetTimerManager().SetTimer(
		AnimationLengthTimerHandle,
		this,
		&USmashCharacterStateAttack::OnAnimationLengthTimerElapsed,
		AnimationLength,
		false
		);
}

void USmashCharacterStateAttack::StateExit(ESmashCharacterStateID NextState)
{
	Super::StateExit(NextState);

	GetWorld()->GetTimerManager().ClearTimer(AnimationLengthTimerHandle);
}

void USmashCharacterStateAttack::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
}

void USmashCharacterStateAttack::OnAnimationLengthTimerElapsed() const
{
	StateMachine->ChangeState(ESmashCharacterStateID::Idle);	
}

#pragma region Overriden Functions
void USmashCharacterStateAttack::OnJumpEvent()
{
	//Do nothing so we override and leave it empty
}

void USmashCharacterStateAttack::CheckIfIsFalling()
{
	//Do nothing so we override and leave it empty
}

void USmashCharacterStateAttack::OnAttackEvent()
{
	//Do nothing so we override and leave it empty
}
#pragma endregion 
