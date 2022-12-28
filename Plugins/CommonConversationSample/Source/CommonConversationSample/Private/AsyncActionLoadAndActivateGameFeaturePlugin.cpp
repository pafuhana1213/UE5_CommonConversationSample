// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncActionLoadAndActivateGameFeaturePlugin.h"
#include "GameFeaturesSubsystem.h"

UAsyncActionLoadAndActivateGameFeaturePlugin::UAsyncActionLoadAndActivateGameFeaturePlugin(const FObjectInitializer& ObjectInitializer)
{
}

UAsyncActionLoadAndActivateGameFeaturePlugin* UAsyncActionLoadAndActivateGameFeaturePlugin::LoadAndActivateGameFeaturePlugin(UObject* WorldContextObject, FString GameFeatureName)
{
	
	UAsyncActionLoadAndActivateGameFeaturePlugin* Action = NewObject<UAsyncActionLoadAndActivateGameFeaturePlugin>();
	Action->GameFeaturePluginName = GameFeatureName;
	Action->RegisterWithGameInstance(WorldContextObject);
	return Action;
}

void UAsyncActionLoadAndActivateGameFeaturePlugin::Activate()
{
	Super::Activate();

	if (UGameFeaturesSubsystem* GameFeaturesSubsystem = GEngine ? GEngine->GetEngineSubsystem<UGameFeaturesSubsystem>() : nullptr)
	{
		FString PluginURL;
		if (UGameFeaturesSubsystem::Get().GetPluginURLByName(GameFeaturePluginName,  PluginURL))
		{
			FGameFeaturePluginLoadComplete GameFeaturePluginLoadComplete;
			//GameFeaturePluginLoadComplete.BindUFunction(this, FName(TEXT("Completed")));
			GameFeaturePluginLoadComplete.BindUObject(this, &UAsyncActionLoadAndActivateGameFeaturePlugin::Completed);
			GameFeaturesSubsystem->LoadAndActivateGameFeaturePlugin(PluginURL, GameFeaturePluginLoadComplete);
			return;
		}
	}

	Failed.Broadcast();
	SetReadyToDestroy();
}

void UAsyncActionLoadAndActivateGameFeaturePlugin::Completed(const UE::GameFeatures::FResult& Result)
{
	if(Result.HasError())
	{
		Failed.Broadcast();
	}
	else
	{
		Succeeded.Broadcast();
	}
	
	SetReadyToDestroy();
}