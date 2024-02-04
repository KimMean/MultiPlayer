// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MultiPlayer : ModuleRules
{
	public MultiPlayer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
        PublicDependencyModuleNames.AddRange(new string[] 
		{
			"AIModule",
		});

        PublicIncludePaths.Add(ModuleDirectory);

        PrivateIncludePaths.AddRange(new string[]
		{
			"MultiPlayer"
		});
	}
}
