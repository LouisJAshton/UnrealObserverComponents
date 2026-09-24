
#include "ListenerComponent.h"

// Sets default values for this component's properties
UListenerComponent::UListenerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UListenerComponent::Call() const
{
	UFunction* func = CalledFunction.ResolveMember<UFunction>(GetOwner()->GetClass());
	if (!func)
		return;

	GetOwner()->ProcessEvent(func, nullptr);
}