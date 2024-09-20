// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SmashCharacterStateMachine.generated.h"

enum class ESmashCharacterStateID : uint8;
class USmashCharacterState;
class USmashCharacterStateAlias;
class ASmashCharacter;

/**
 * 
 */
UCLASS()
class SMASHUE_API USmashCharacterStateMachine : public UObject
{
	GENERATED_BODY()

public:
	void Init(ASmashCharacter* InCharacter);

	void Tick(float DeltaTime);

	ASmashCharacter* GetCharacter() const;

	UFUNCTION(BlueprintCallable)
	void ChangeState(ESmashCharacterStateID NextStateID);

	USmashCharacterState* GetState(ESmashCharacterStateID StateID);

	ESmashCharacterStateID GetCurrentStateID();
protected:
	UPROPERTY()
	TObjectPtr<ASmashCharacter> Character;

	UPROPERTY()
	TArray<USmashCharacterState*> AllStates;

	UPROPERTY()
	TArray<USmashCharacterStateAlias*> AllStateAliases;

	UPROPERTY(BlueprintReadOnly)
	ESmashCharacterStateID CurrentStateID;

	UPROPERTY()
	TObjectPtr<USmashCharacterState> CurrentState;
	
	void FindStates();

	void InitStates();

	void FindStateAliases();

	void InitStateAliases();
};
