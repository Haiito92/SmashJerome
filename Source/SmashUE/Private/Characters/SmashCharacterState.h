// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SmashCharacterState.generated.h"


class USmashCharacterSettings;
class ASmashCharacter;
class USmashCharacterStateMachine;
enum class ESmashCharacterStateID : uint8;


UCLASS(Abstract, Blueprintable, BlueprintType)
class SMASHUE_API USmashCharacterState : public UObject
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USmashCharacterState();

	virtual ESmashCharacterStateID GetStateID();

	virtual void StateInit(USmashCharacterStateMachine* InStateMachine);
	
	virtual void StateEnter(ESmashCharacterStateID PreviousState);

	virtual void StateExit(ESmashCharacterStateID NextState);

	virtual void StateTick(float DeltaTime);
protected:
	UPROPERTY()
	TObjectPtr<ASmashCharacter> Character;

	UPROPERTY()
	const USmashCharacterSettings* CharacterSettings;
	
	UPROPERTY()
	TObjectPtr<USmashCharacterStateMachine> StateMachine;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAnimMontage> StateAnimMontage;

	UFUNCTION()
	virtual void OnJumpEvent();

	UFUNCTION()
	virtual void CheckIfIsFalling();

	UFUNCTION()
	virtual void OnAttackEvent();
};
