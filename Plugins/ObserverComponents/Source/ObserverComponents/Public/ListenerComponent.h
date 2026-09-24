#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ListenerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OBSERVERCOMPONENTS_API UListenerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UListenerComponent();

protected:
	UPROPERTY(EditDefaultsOnly, meta = (FunctionReference, PrototypeFunction="/Script/ObserverComponents.ListenerComponent.Blah", DefaultBindingName="Trigger"))
	FMemberReference CalledFunction;

	UFUNCTION(BlueprintInternalUseOnly)
	void Blah() {};
public:

	FMemberReference GetCalledFunction() const { return CalledFunction; }
	
	void Call() const;
};