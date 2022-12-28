// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConversationInstance.h"
#include "SampleConversationInstance.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class COMMONCONVERSATIONSAMPLE_API USampleConversationInstance : public UConversationInstance
{
	GENERATED_BODY()

	void PauseConversationAndSendClientChoices(const FConversationContext& Context, const FClientConversationMessage& ClientMessage) override;

public:

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStartWatingChoiceDelegate);
	UPROPERTY(BlueprintAssignable)
	FStartWatingChoiceDelegate OnStartWatingChoice;
	
	UPROPERTY(BlueprintReadWrite)
	bool WaitingChoice = false;
};
