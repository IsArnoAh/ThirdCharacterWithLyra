// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Player/PlayerValueComponent.h"

// Sets default values for this component's properties
UPlayerValueComponent::UPlayerValueComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	CurrentLevel=1;
	CurrentHealth=100.0f;
	CurrentXP=0;
	CurrentMental=200;
	CurrentDamage=10;
	MaxMental=400;
	MaxHealth=100.0f;
	MaxXP=100.0f;
	// ...
}


// Called when the game starts
void UPlayerValueComponent::BeginPlay()
{
	Super::BeginPlay();
	PrimaryComponentTick.bCanEverTick = false;
}



// Called every frame
void UPlayerValueComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

/**
 * @brief 第一次游戏参数加载
 */
void UPlayerValueComponent::FirstGameValueConfig()
{
	//初级参数设置
	CurrentLevel=1;
	CurrentHealth=100.0f;
	CurrentXP=0;
	CurrentMental=200;
	CurrentDamage=10;
	MaxMental=400;
	MaxHealth=100.0f;
	MaxXP=100.0f;
}

/**
 * @brief 
 * @param currentHealth 血量
 * @param currentXP 经验
 * @param currentMental 精神
 * @param currentDamage 伤害
 * @param currentLevel 等级
 */
void UPlayerValueComponent::LoadGameValueConfig(float currentHealth, float currentXP, float currentMental,
                                                float currentDamage, int currentLevel)
{
	CurrentHealth=currentHealth;
	CurrentXP=currentXP;
	CurrentMental=currentMental;
	CurrentDamage=currentDamage;
	CurrentLevel=currentLevel;
}

// 增加血量上限
void UPlayerValueComponent::IncreaseMaxHealth()
{
	MaxHealth+=50;
}
// 增加基础攻击伤害
void UPlayerValueComponent::IncreaseDamage(float increaseValue)
{
	CurrentDamage+=increaseValue;
}


//血量增减
float UPlayerValueComponent::IncreaseHealth(float IncreaseHealth)
{
	CurrentHealth+=IncreaseHealth;
	if (CurrentHealth>=MaxHealth)
	{
		CurrentHealth=MaxHealth;
	}
	return CurrentHealth/MaxHealth;
}
float UPlayerValueComponent::DecreaseHealth(float DecreaseHealth)
{
	CurrentHealth-=DecreaseHealth;
	if (CurrentHealth<=0)
	{
		CurrentHealth=0;
	}
	return CurrentHealth/MaxHealth;
}

//经验与等级
void UPlayerValueComponent::IncreaseXP(float IncreaseXP)
{
	CurrentXP+=IncreaseXP;
	if (CurrentXP>=MaxXP)
	{
		CurrentXP-=MaxXP;
		IncreaseLevel();
	}
}
void UPlayerValueComponent::IncreaseLevel()
{
	CurrentLevel++;
}

//精神值
float UPlayerValueComponent::IncreaseMental(float IncreaseMental)
{
	CurrentMental+=IncreaseMental;
	return CurrentMental/MaxMental;
}
float UPlayerValueComponent::DecreaseMental(float DecreaseMental)
{
	CurrentMental-=DecreaseMental;
	return CurrentMental/MaxMental;
}

// 获取当前伤害值
float UPlayerValueComponent::GetCurrentDamage()
{
	return CurrentDamage;
}










