// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "WebConnect.generated.h"


UCLASS()
class WEBSERVICE_API UWebConnect : public UObject
{
	GENERATED_BODY()
	
public:
	
	UWebConnect();

	UPROPERTY()
		FString MyName;

	UPROPERTY()
		FString Host;

	UPROPERTY()
		FString URI;

	// UFUNCTION() 매크로 사용시 언리얼 엔진에서 제공하는 Delegate 사용가능.
	// 그 외에 언리얼 네트워크 사용시에 타클라이언트의 함수 호출시 이 매크로가 붙어있어야 함.
	UFUNCTION()
	FString GetName() { return TEXT("MyName"); }

	UFUNCTION()
		void RequestToken();
};
