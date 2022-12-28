// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFeaturePluginOperationResult.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncActionLoadAndActivateGameFeaturePlugin.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCompletedAsyncActionLoadAndActivateGameFeaturePlugin);

/**
 * 
 */
UCLASS()
class COMMONCONVERSATIONSAMPLE_API UAsyncActionLoadAndActivateGameFeaturePlugin : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FCompletedAsyncActionLoadAndActivateGameFeaturePlugin Succeeded;

	UPROPERTY(BlueprintAssignable)
	FCompletedAsyncActionLoadAndActivateGameFeaturePlugin Failed;

	UPROPERTY()
	FString GameFeaturePluginName;
	
public:
	UAsyncActionLoadAndActivateGameFeaturePlugin(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable,meta = ( WorldContext = "WorldContextObject",BlueprintInternalUseOnly = "true" ))
	static UAsyncActionLoadAndActivateGameFeaturePlugin* LoadAndActivateGameFeaturePlugin(UObject* WorldContextObject, FString GameFeatureName);

	virtual void Activate() override;

	void Completed(const UE::GameFeatures::FResult& Result);
};
