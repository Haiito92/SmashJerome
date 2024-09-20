// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SmashCharacterStateAlias.generated.h"


class ASmashCharacter;
class USmashCharacterStateMachine;
enum class ESmashCharacterStateID : uint8;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SMASHUE_API USmashCharacterStateAlias : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USmashCharacterStateAlias();

	virtual void StateAliasTick(float DeltaTime);
	
	virtual void StateAliasInit(USmashCharacterStateMachine* InStateMachine);
	
	virtual void SubscribeToInputEvents();
protected:
	UPROPERTY()
	TObjectPtr<ASmashCharacter> Character;
	
	UPROPERTY()
	TObjectPtr<USmashCharacterStateMachine> StateMachine;
	
	UPROPERTY(EditAnywhere)
	TArray<ESmashCharacterStateID> FromStatesID;

	UPROPERTY(EditAnywhere)
	ESmashCharacterStateID ToStateID;
};
