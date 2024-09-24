// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/SmashCharacterStateAttack.h"

#include "Characters/SmashCharacterStateID.h"

ESmashCharacterStateID USmashCharacterStateAttack::GetStateID()
{
	return ESmashCharacterStateID::Attack;
}

void USmashCharacterStateAttack::StateEnter(ESmashCharacterStateID PreviousState)
{
	Super::StateEnter(PreviousState);
}

void USmashCharacterStateAttack::StateExit(ESmashCharacterStateID NextState)
{
	Super::StateExit(NextState);
}

void USmashCharacterStateAttack::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
}

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

