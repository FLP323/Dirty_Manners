// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagContainer.h"
#include <GameplayEffectTypes.h>
#include "AbilitySystemInterface.h"
#include "DirtyMannersCharacter.generated.h"

UCLASS()
class DIRTY_MANNERS_API ADirtyMannersCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
		class UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
		class UDirtyMannersAttributeSet* Attributes;

public:
	// Sets default values for this character's properties
	ADirtyMannersCharacter();

	//Overriden from IAbilitySystemInterface
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int MaxHealth = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int MaxArmor = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int MaxBullets = 240;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int MaxRockets = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int MaxSoap = 240;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Effect that initializes default attributes
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "DirtyManners")
		TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	// Array of starting abilities
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "DirtyManners")
		TArray<TSubclassOf<class UGameplayAbility>> DefaultAbilities;

};
