// Fill out your copyright notice in the Description page of Project Settings.


#include "SampleConversationInstance.h"

void USampleConversationInstance::PauseConversationAndSendClientChoices(const FConversationContext& Context,
	const FClientConversationMessage& ClientMessage)
{
	Super::PauseConversationAndSendClientChoices(Context, ClientMessage);

	WaitingChoice = true;
	OnStartWatingChoice.Broadcast();
}