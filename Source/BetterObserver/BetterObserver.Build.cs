// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BetterObserver : ModuleRules
{
	public BetterObserver(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"BetterObserver",
			"BetterObserver/Variant_Platforming",
			"BetterObserver/Variant_Platforming/Animation",
			"BetterObserver/Variant_Combat",
			"BetterObserver/Variant_Combat/AI",
			"BetterObserver/Variant_Combat/Animation",
			"BetterObserver/Variant_Combat/Gameplay",
			"BetterObserver/Variant_Combat/Interfaces",
			"BetterObserver/Variant_Combat/UI",
			"BetterObserver/Variant_SideScrolling",
			"BetterObserver/Variant_SideScrolling/AI",
			"BetterObserver/Variant_SideScrolling/Gameplay",
			"BetterObserver/Variant_SideScrolling/Interfaces",
			"BetterObserver/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
