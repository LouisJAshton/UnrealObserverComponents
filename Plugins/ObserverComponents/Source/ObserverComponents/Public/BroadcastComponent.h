#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BroadcastComponent.generated.h"


class UListenerComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OBSERVERCOMPONENTS_API UBroadcastComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBroadcastComponent();

protected:

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, meta=(UseComponentPicker, AllowAnyActor, AllowedClasses="ListenerComponent"))
	TSet<FComponentReference> Listeners;

public:
	UFUNCTION(BlueprintCallable)
	void Broadcast() const;

	TArray<const UListenerComponent*> GetListenerComponents() const;
};