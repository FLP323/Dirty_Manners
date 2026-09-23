// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "DirtyMannersAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class DIRTY_MANNERS_API UDirtyMannersAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	UDirtyMannersAttributeSet();

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UDirtyMannersAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UDirtyMannersAttributeSet, Armor);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Bullets;
	ATTRIBUTE_ACCESSORS(UDirtyMannersAttributeSet, Bullets);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Rockets;
	ATTRIBUTE_ACCESSORS(UDirtyMannersAttributeSet, Rockets);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Soap;
	ATTRIBUTE_ACCESSORS(UDirtyMannersAttributeSet, Soap);

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual bool PreGameplayEffectExecute(struct FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
};
