// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "ABGameInstance.generated.h"


class FHouse
{
public:
	int32 Size = 10;
	TSharedPtr<FHouse> OthersDeed;
};

UCLASS()
class ARENABATTLE_API UABGameInstance : public UGameInstance
{
	GENERATED_BODY()
		
public:
	UABGameInstance();
	
	void Init() override;

	UPROPERTY()
	class UWebConnect* WebConnect;

	UPROPERTY()
	class UWebConnect* WebConnect2;

	// ini config
	UPROPERTY()
		FStreamableManager AssetLoader;
};
