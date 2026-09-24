#include "BroadcastLinkVisualiser.h"

#include "BroadcastComponent.h"
#include "CanvasItem.h"
#include "CanvasTypes.h"
#include "ListenerComponent.h"

void FBroadcastLinkVisualiser::DrawVisualization(const UActorComponent* Component, const FSceneView* View,
                                                 FPrimitiveDrawInterface* PDI)
{
	const UBroadcastComponent* Comp = Cast<const UBroadcastComponent>(Component);
	if (Comp == nullptr)
		return;

	const TArray<const UListenerComponent*> ListenerComponents = Comp->GetListenerComponents();
	
	for (const auto Listener : ListenerComponents)
	{
		const UE::Math::TVector<double> displacement = Listener->GetOwner()->GetActorLocation() - Comp->GetOwner()->
			GetActorLocation();

		const UE::Math::TVector<double> dir = displacement.GetSafeNormal();
		float length = displacement.Length();
		length = FMath::Max(length - 50, 0.0f);
		
		FTransform transform = FTransform(dir);
		FMatrix arrow2World = transform.ToMatrixWithScale();
		
		arrow2World.SetOrigin(Comp->GetOwner()->GetActorLocation());
		arrow2World.SetAxes(&(dir));
		
		DrawDirectionalArrow(PDI, arrow2World, FLinearColor::Blue, length, 10, SDPG_Foreground, 1);
	}
}

void FBroadcastLinkVisualiser::DrawVisualizationHUD(const UActorComponent* Component, const FViewport* Viewport,
	const FSceneView* View, FCanvas* Canvas)
{
	const UBroadcastComponent* Comp = Cast<const UBroadcastComponent>(Component);
	if (Comp == nullptr)
		return;

	UFont* LargeFont = GEngine->GetLargeFont();
	
	const int32 HalfX = 0.5f * Viewport->GetSizeXY().X;
	const int32 HalfY = 0.5f * Viewport->GetSizeXY().Y;

	const TArray<const UListenerComponent*> ListenerComponents = Comp->GetListenerComponents();
	
	for (const auto Listener : ListenerComponents)
	{
		FVector location = Comp->GetOwner()->GetActorLocation() / 2 + Listener->GetOwner()->GetActorLocation() / 2;
		location.Z += 20;
		auto screenLocation = View->Project(location);

		if (screenLocation.W <= 0.f)
			continue;
		
		const float DrawPosX = HalfX + (HalfX * screenLocation.X);
		const float DrawPosY = HalfY + (HalfY * screenLocation.Y * -1);

		FCanvasTextItem TextItem(
			FVector2D(DrawPosX, DrawPosY),
			FText::FromString(FString::Printf(
				TEXT("%s --> %s (%s)"), *Component->GetName(), *Listener->GetCalledFunction().GetMemberName().ToString(), *Listener->GetOwner()->GetActorLabel())),
			LargeFont,
			FLinearColor::White
		);

		const float offset = LargeFont->GetStringSize(*TextItem.Text.ToString()) / 2.f;
		TextItem.Position = FVector2D(DrawPosX - offset, DrawPosY);
		TextItem.EnableShadow(FLinearColor::Black);
		Canvas->DrawItem(TextItem);
	}
}