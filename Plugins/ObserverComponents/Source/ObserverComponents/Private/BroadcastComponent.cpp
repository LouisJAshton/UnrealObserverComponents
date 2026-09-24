#include "BroadcastComponent.h"

#include "ListenerComponent.h"

// Sets default values for this component's properties
UBroadcastComponent::UBroadcastComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UBroadcastComponent::Broadcast() const
{
	for (const auto Listener : GetListenerComponents())
	{
		Listener->Call();
	}
}

TArray<const UListenerComponent*> UBroadcastComponent::GetListenerComponents() const
{
	TArray<const UListenerComponent*> Components;
	for (const auto Listener : Listeners)
		if (const UListenerComponent* Comp = Cast<UListenerComponent>(Listener.GetComponent(Listener.OtherActor.Get())))
			Components.Add(Comp);

	return Components;
}