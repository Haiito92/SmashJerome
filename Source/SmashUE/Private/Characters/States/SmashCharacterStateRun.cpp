// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/SmashCharacterStateRun.h"

#include "Characters/SmashCharacter.h"
#include "Characters/SmashCharacterStateID.h"
#include "GameFramework/CharacterMovementComponent.h"

ESmashCharacterStateID USmashCharacterStateRun::GetStateID()
{
	return ESmashCharacterStateID::Run;
}

void USmashCharacterStateRun::StateEnter(ESmashCharacterStateID PreviousState)
{
	Super::StateEnter(PreviousState);

	Character->GetCharacterMovement()->MaxWalkSpeed = RunSpeed;
}

void USmashCharacterStateRun::StateExit(ESmashCharacterStateID NextState)
{
	Super::StateExit(NextState);
}

void USmashCharacterStateRun::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);

	Character->AddMovementInput(FVector::ForwardVector, Character->GetOrientX());
}
