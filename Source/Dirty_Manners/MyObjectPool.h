// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PooledObject.h"
#include "MyObjectPool.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIRTY_MANNERS_API UMyObjectPool : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyObjectPool();

	UFUNCTION(BlueprintCallable, Category = "My Object Pool")
		APooledObject* SpawnPooledObject();

	UPROPERTY(EditAnywhere, Category = "My Object Pool")
		TSubclassOf<class APooledObject> PooledObjectSubclass;

	UPROPERTY(EditAnywhere, Category = "My Object Pool")
		int PoolSize = 20;

	UPROPERTY(EditAnywhere, Category = "My Object Pool")
		float PooledObjectLifeSpan = 0.0f;

	UFUNCTION()
		void OnPooledObjectDespawn(APooledObject* PoolActor);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TArray<APooledObject*> MyObjectPool;
	TArray<int> SpawnedPoolIndexes;
};
