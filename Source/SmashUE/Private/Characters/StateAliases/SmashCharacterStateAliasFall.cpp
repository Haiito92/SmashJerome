// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/StateAliases/SmashCharacterStateAliasFall.h"

#include "Characters/SmashCharacter.h"
#include "Characters/SmashCharacterState.h"
#include "Characters/SmashCharacterStateMachine.h"
#include "Characters/SmashCharacterStateID.h"


void USmashCharacterStateAliasFall::StateAliasTick(float DeltaTime)
{
	Super::StateAliasTick(DeltaTime);

	if(Character->GetVelocity().Z < 0 && FromStatesID.Contains(StateMachine->GetCurrentStateID()))
	{
		StateMachine->ChangeState(ToStateID);
	}
}
