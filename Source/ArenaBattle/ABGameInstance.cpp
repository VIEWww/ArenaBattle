// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "WebConnect.h"
#include "ABGameInstance.h"

UABGameInstance::UABGameInstance()
{
	// 컴파일(엔진초기화) 시에 호출
	UE_LOG(LogTemp, Warning, TEXT("ABGameInstance Constructor Called!"));

	WebConnect = CreateDefaultSubobject<UWebConnect>(TEXT("WebConnect"));
}

void UABGameInstance::Init()
{
	AB_LOG_CALLONLY(Warning);

	// 게임 플레이 런타임 시에 호출.
	Super::Init();

	// 오브젝트 생성 후 "자기 자신에게 어태치"
	WebConnect2 = NewObject<UWebConnect>(this);

	AB_LOG(Warning, TEXT("Outer of NewObject : %s"), *WebConnect2->GetOuter()->GetClass()->GetFullName());

	UClass* ClassInfo1 = WebConnect->GetClass();
	UClass* ClassInfo2 = UWebConnect::StaticClass();

	/*if (ClassInfo1 == ClassInfo2)
	{
		AB_LOG(Warning, TEXT("ClassInfo1 is same with ClassInfo2"));
	}*/

	for (TFieldIterator<UProperty> It(ClassInfo1); It; ++It)
	{
		AB_LOG(Warning, TEXT("Field : %s, Type : %s"), *It->GetName(), *It->GetClass()->GetName());
		UStrProperty* StrProp = FindField<UStrProperty>(ClassInfo1, *It->GetName());
		if (StrProp)
		{
			AB_LOG(Warning, TEXT("Value = %s"), *StrProp->GetPropertyValue_InContainer(WebConnect));
		}
	}

	for (const auto& Entry : ClassInfo1->NativeFunctionLookupTable)
	{
		AB_LOG(Warning, TEXT("Function = %s"), *Entry.Name.ToString());
		UFunction* Func1 = ClassInfo1->FindFunctionByName(Entry.Name);
		if (Func1->ParmsSize == 0)
		{
			WebConnect->ProcessEvent(Func1, NULL);
		}
	}

	UWorld* CurrentWorld = GetWorld();

	for (const auto& Entry : FActorRange(CurrentWorld))
	{
		AB_LOG(Warning, TEXT("Actor : %s"), *Entry->GetName());

		TArray<UObject*> Components;
		Entry->GetDefaultSubobjects(Components);
		for (const auto& CEntry : Components)
		{
			AB_LOG(Warning, TEXT(" -- Components : %s"), *CEntry->GetName());
		}
	}

	for (TActorIterator<AStaticMeshActor> It(CurrentWorld); It; ++It)
	{
		AB_LOG(Warning, TEXT("StaticMesh Actor : %s"), *It->GetName());
	}
}