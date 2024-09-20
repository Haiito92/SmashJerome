// Fill out your copyright notice in the Description page of Project Settings.


#include "SmashCharacterStateAlias.h"

#include "Characters/SmashCharacterStateID.h"
#include "Characters/SmashCharacterStateMachine.h"


// Sets default values for this component's properties
USmashCharacterStateAlias::USmashCharacterStateAlias()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void USmashCharacterStateAlias::StateAliasTick(float DeltaTime)
{
	
}

void USmashCharacterStateAlias::StateAliasInit(USmashCharacterStateMachine* InStateMachine)
{
	if(InStateMachine == nullptr) return;

	StateMachine = InStateMachine;
	Character = InStateMachine->GetCharacter();

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Orange,
		TEXT("StateAliasInit"));

	SubscribeToInputEvents();
}

void USmashCharacterStateAlias::SubscribeToInputEvents()
{
}

