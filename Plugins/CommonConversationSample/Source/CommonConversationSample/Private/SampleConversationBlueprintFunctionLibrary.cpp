// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleConversationBlueprintFunctionLibrary.h"

#include "GameFeaturesSubsystem.h"


const FClientConversationMessagePayload& USampleConversationBlueprintFunctionLibrary::GetLastMessage(
	UConversationParticipantComponent* ConversationParticipantComponent)
{
	check(ConversationParticipantComponent)
	
	return ConversationParticipantComponent->GetLastMessage();
}

void USampleConversationBlueprintFunctionLibrary::RequestCustomAdvanceConversation(
	USampleConversationInstance* Conversation, UConversationParticipantComponent* ConversationParticipantComponent,
	const FAdvanceConversationRequest& InChoicePicked)
{
	if( Conversation && ConversationParticipantComponent)
	{
		Conversation->WaitingChoice = false;
		ConversationParticipantComponent->RequestServerAdvanceConversation(InChoicePicked);
	}
}

const UConversationTaskNode* USampleConversationBlueprintFunctionLibrary::GetConversationTaskNode(const FConversationContext& Context)
{
	return Context.GetTaskBeingConsidered();
}

bool USampleConversationBlueprintFunctionLibrary::IsGameFeaturePluginActive(FString PluginName)
{
	if (UGameFeaturesSubsystem* GameFeaturesSubsystem = GEngine ? GEngine->GetEngineSubsystem<UGameFeaturesSubsystem>() : nullptr)
	{
		FString PluginURL;
		if (UGameFeaturesSubsystem::Get().GetPluginURLByName(PluginName,  PluginURL))
		{
			return GameFeaturesSubsystem->IsGameFeaturePluginActive(PluginURL);
		}
	}

	return false;
}