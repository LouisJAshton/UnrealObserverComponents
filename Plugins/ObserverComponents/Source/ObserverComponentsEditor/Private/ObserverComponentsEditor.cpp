#include "ObserverComponentsEditor.h"

#include "BroadcastComponent.h"
#include "BroadcastLinkVisualiser.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "UnrealEd.h"

#define LOCTEXT_NAMESPACE "FObserverComponentsEditorModule"

void FObserverComponentsEditorModule::StartupModule()
{
    if (GUnrealEd == nullptr)
    {
        return;
    }
    
    TSharedPtr<FBroadcastLinkVisualiser> BroadcastVisualiser = MakeShareable(new FBroadcastLinkVisualiser);
    GUnrealEd->RegisterComponentVisualizer(UBroadcastComponent::StaticClass()->GetFName(), BroadcastVisualiser);
}

void FObserverComponentsEditorModule::ShutdownModule()
{
    if (GUnrealEd == nullptr)
    {
        return;
    }

    GUnrealEd->UnregisterComponentVisualizer(UBroadcastComponent::StaticClass()->GetFName());
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FObserverComponentsEditorModule, ObserverComponentsEditor)