using UnrealBuildTool;

public class ObserverComponentsEditor : ModuleRules
{
    public ObserverComponentsEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "UnrealEd",
                "ComponentVisualizers",
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "ObserverComponents",
            }
        );
    }
}