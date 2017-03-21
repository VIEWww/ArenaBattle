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

	// UFUNCTION() ��ũ�� ���� �𸮾� �������� �����ϴ� Delegate ��밡��.
	// �� �ܿ� �𸮾� ��Ʈ��ũ ���ÿ� ŸŬ���̾�Ʈ�� �Լ� ȣ��� �� ��ũ�ΰ� �پ��־�� ��.
	UFUNCTION()
	FString GetName() { return TEXT("MyName"); }

	UFUNCTION()
		void RequestToken();
};
