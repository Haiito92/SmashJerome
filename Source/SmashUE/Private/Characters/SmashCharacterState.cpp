// Fill out your copyright notice in the Description page of Project Settings.


#include "SmashCharacterState.h"

#include "Characters/SmashCharacter.h"
#include "Characters/SmashCharacterStateID.h"
#include "Characters/SmashCharacterStateMachine.h"
#include "Characters/SmashCharacterSettings.h"


// Sets default values for this component's properties
USmashCharacterState::USmashCharacterState()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = false;

	// ...
}

ESmashCharacterStateID USmashCharacterState::GetStateID()
{
	return  ESmashCharacterStateID::None;
}

void USmashCharacterState::StateInit(USmashCharacterStateMachine* InStateMachine)
{
	StateMachine = InStateMachine;
	Character = InStateMachine->GetCharacter();
	CharacterSettings = GetDefault<USmashCharacterSettings>();	

	
	// GEngine->AddOnScreenDebugMessage(
	// 	-1,
	// 	3.f,
	// 	FColor::Magenta,
	// 	FString::Printf(TEXT("Init State %d"), GetStateID())
	// 	);
}

void USmashCharacterState::StateEnter(ESmashCharacterStateID PreviousState)
{
	if(Character==nullptr) return;
	
	if(StateAnimMontage != nullptr) Character->PlayAnimMontage(StateAnimMontage);
	
	Character->InputJumpEvent.AddDynamic(this, &USmashCharacterState::OnJumpEvent);

	Character->InputAttackEvent.AddDynamic(this, &USmashCharacterState::OnAttackEvent);
}

void USmashCharacterState::StateExit(ESmashCharacterStateID NextState)
{
	if(Character==nullptr) return;
	
	Character->InputJumpEvent.RemoveDynamic(this, &USmashCharacterState::OnJumpEvent);

	Character->InputAttackEvent.RemoveDynamic(this, &USmashCharacterState::OnAttackEvent);
}

void USmashCharacterState::StateTick(float DeltaTime)
{
	CheckIfIsFalling();
}

void USmashCharacterState::OnJumpEvent()
{
	StateMachine->ChangeState(ESmashCharacterStateID::Jump);
}

void USmashCharacterState::CheckIfIsFalling()
{
	if(Character->GetVelocity().Z < 0)
	{
		StateMachine->ChangeState(ESmashCharacterStateID::Fall);
	}
}

void USmashCharacterState::OnAttackEvent()
{
	StateMachine->ChangeState(ESmashCharacterStateID::Attack);
}
