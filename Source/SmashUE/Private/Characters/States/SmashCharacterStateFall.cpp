// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/SmashCharacterStateFall.h"

#include "Characters/SmashCharacter.h"
#include "Characters/SmashCharacterStateID.h"
#include "Characters/SmashCharacterStateMachine.h"


ESmashCharacterStateID USmashCharacterStateFall::GetStateID()
{
	return ESmashCharacterStateID::Fall;
}

void USmashCharacterStateFall::StateEnter(ESmashCharacterStateID PreviousState)
{
	Super::StateEnter(PreviousState);

	Character->LandedDelegate.AddDynamic(this, &USmashCharacterStateFall::OnLanded);
	
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Orange,
		TEXT("Enter Fall"));
}

void USmashCharacterStateFall::StateExit(ESmashCharacterStateID NextState)
{
	Super::StateExit(NextState);
}

void USmashCharacterStateFall::StateTick(float DeltaTime)
{
	
}

void USmashCharacterStateFall::OnLanded(const FHitResult& Hit)
{
	StateMachine->ChangeState(ESmashCharacterStateID::Idle);
}

void USmashCharacterStateFall::CheckIfIsFalling()
{
	
}
