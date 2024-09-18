// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/SmashCharacterStateIdle.h"

#include "Characters/SmashCharacter.h"
#include "Characters/SmashCharacterSettings.h"
#include "Characters/SmashCharacterStateID.h"
#include "Characters/SmashCharacterStateMachine.h"

ESmashCharacterStateID USmashCharacterStateIdle::GetStateID()
{
	return ESmashCharacterStateID::Idle;
}

void USmashCharacterStateIdle::StateEnter(ESmashCharacterStateID PreviousState)
{
	Super::StateEnter(PreviousState);

	// GEngine->AddOnScreenDebugMessage(
	// 	-1,
	// 	3.f,
	// 	FColor::Cyan,
	// 	TEXT("Enter StateIdle")
	// 	);

	
}

void USmashCharacterStateIdle::StateExit(ESmashCharacterStateID NextState)
{
	Super::StateExit(NextState);

	// GEngine->AddOnScreenDebugMessage(
	// 	-1,
	// 	3.f,
	// 	FColor::Red,
	// 	TEXT("Exit StateIdle")
	// 	);
}

void USmashCharacterStateIdle::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);

	// GEngine->AddOnScreenDebugMessage(
	// 	-1,
	// 	3.f,
	// 	FColor::Green,
	// 	TEXT("Tick StateIdle")
	// 	);

	if(FMath::Abs(Character->GetInputMoveX()) > GetDefault<USmashCharacterSettings>()->InputMoveXThreshold)
	{
		StateMachine->ChangeState(ESmashCharacterStateID::Walk);
	}
}
