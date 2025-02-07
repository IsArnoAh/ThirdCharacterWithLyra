// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Player/PlayerValueComponent.h"
#include "GameSaves.generated.h"

/**
 * 
 */
UCLASS()
class MYTPC_API UGameSaves : public USaveGame
{
	GENERATED_BODY()

public:
	// 构造函数
	UGameSaves();
	
	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 SaveIndex=0;
	
	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName=TEXT("save");

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FName GameMap=TEXT("Map_Tutorial");

	UPROPERTY(VisibleAnywhere,Category = Basic)
	FVector PlayerLocation=FVector(0,0,0);

	UPROPERTY(VisibleAnywhere,Category = Basic)
	FString SaveDate;
	
	UPROPERTY(VisibleAnywhere,Category="PlayerValue")
	UPlayerValueComponent* PlayerValue;
	
};
