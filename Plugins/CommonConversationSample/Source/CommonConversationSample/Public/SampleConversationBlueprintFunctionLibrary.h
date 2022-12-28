// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConversationParticipantComponent.h"
#include "GameFeaturesSubsystem.h"
#include "SampleConversationInstance.h"
#include "SampleConversationBlueprintFunctionLibrary.generated.h"

UCLASS()
class COMMONCONVERSATIONSAMPLE_API USampleConversationBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static const FClientConversationMessagePayload& GetLastMessage(UConversationParticipantComponent* ConversationParticipantComponent);

	UFUNCTION(BlueprintCallable)
	static void RequestCustomAdvanceConversation(USampleConversationInstance* Conversation, UConversationParticipantComponent* ConversationParticipantComponent, const FAdvanceConversationRequest& InChoicePicked);

	UFUNCTION(BlueprintCallable)
	static const UConversationTaskNode* GetConversationTaskNode(const FConversationContext& Context);
	
	UFUNCTION(BlueprintCallable)
	static bool IsGameFeaturePluginActive(FString PluginName);
};


