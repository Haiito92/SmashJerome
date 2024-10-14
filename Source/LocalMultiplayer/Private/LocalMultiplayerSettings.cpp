// Fill out your copyright notice in the Description page of Project Settings.

#include "LocalMultiplayerSettings.h"
#include "InputMappingContext.h"

bool FLocalMultiplayerProfileData::ContainsKey(const FKey& Key, ELocalMultiplayerInputMappingType MappingType) const
{
	
	switch (MappingType)
	{
	case ELocalMultiplayerInputMappingType::InGame:

		if(IMCInGame == nullptr) return false;

		for (auto Element : IMCInGame->GetMappings())
		{
			if(Element.Key == Key) return true;
		}
		
		return false;
		
	case ELocalMultiplayerInputMappingType::Menu:

		if(IMCMenu == nullptr) return false;

		for (auto Element : IMCMenu->GetMappings())
		{
			if(Element.Key == Key) return true;
		}
		
		return false;
		
	default:
		return false;
	}
}

UInputMappingContext* FLocalMultiplayerProfileData::GetIMCFromType(ELocalMultiplayerInputMappingType MappingType) const
{
	switch (MappingType)
	{
	case ELocalMultiplayerInputMappingType::InGame:
		return IMCInGame;
	case ELocalMultiplayerInputMappingType::Menu:
		return IMCMenu;
	default: return nullptr;
	}
}

int ULocalMultiplayerSettings::GetNbKeyboardProfiles() const
{
	return KeyboardProfilesData.Num();
}

int ULocalMultiplayerSettings::FindKeyboardProfileIndexFromKey(const FKey& Key,
	ELocalMultiplayerInputMappingType MappingType) const
{
	
	return -1;
}
