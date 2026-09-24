#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BroadcastComponent.generated.h"


class UListenerComponent;

UCLASS( ClassGroup=(Observer), meta=(BlueprintSpawnableComponent) )
class OBSERVERCOMPONENTS_API UBroadcastComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBroadcastComponent();

protected:

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category=Observer, meta=(UseComponentPicker, AllowAnyActor, AllowedClasses="ListenerComponent"))
	TSet<FComponentReference> Listeners;

public:
	UFUNCTION(BlueprintCallable, Category=Observer)
	void Broadcast() const;

	TArray<const UListenerComponent*> GetListenerComponents() const;
};