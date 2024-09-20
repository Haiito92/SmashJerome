// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/StateAliases/SmashCharacterStateAliasJump.h"

#include "Characters/SmashCharacter.h"
#include "Characters/SmashCharacterStateMachine.h"


void USmashCharacterStateAliasJump::SubscribeToInputEvents()
{
	Super::SubscribeToInputEvents();

	Character->InputJumpEvent.AddDynamic(this, &USmashCharacterStateAliasJump::OnJumpEvent);
}

void USmashCharacterStateAliasJump::OnJumpEvent()
{
	if(FromStatesID.Contains(StateMachine->GetCurrentStateID()))
	{
		StateMachine->ChangeState(ToStateID);
	}
}
