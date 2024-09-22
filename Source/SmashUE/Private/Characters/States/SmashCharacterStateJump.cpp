// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/States/SmashCharacterStateJump.h"

#include "Characters/SmashCharacter.h"
#include "Characters/SmashCharacterStateID.h"
#include "GameFramework/CharacterMovementComponent.h"


ESmashCharacterStateID USmashCharacterStateJump::GetStateID()
{
	return ESmashCharacterStateID::Jump;
}

void USmashCharacterStateJump::StateEnter(ESmashCharacterStateID PreviousState)
{
	Super::StateEnter(PreviousState);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Orange,
		TEXT("Enter Jump"));

	float Gravity = (-2*JumpHeight)/(JumpDuration*JumpDuration);
	float GravityScale = Gravity / GetWorld()->GetGravityZ();

	float JumpVelocity = - Gravity * JumpDuration;

	Character->GetCharacterMovement()->GravityScale = GravityScale;
	Character->GetCharacterMovement()->JumpZVelocity = JumpVelocity;
	
	Character->Jump();
}

void USmashCharacterStateJump::StateExit(ESmashCharacterStateID NextState)
{
	Super::StateExit(NextState);
}

void USmashCharacterStateJump::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);

	
}

void USmashCharacterStateJump::OnJumpEvent()
{
	
}
