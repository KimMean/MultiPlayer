// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MultiPlayer : ModuleRules
{
    public MultiPlayer(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

<<<<<<< Updated upstream
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
=======
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay",
            "EnhancedInput","AIModule",
        });
>>>>>>> Stashed changes


<<<<<<< Updated upstream
		PrivateIncludePaths.AddRange(new string[]
		{
			"MultiPlayer"
		});
	}
=======
        PrivateIncludePaths.AddRange(new string[]
        {
            "MultiPlayer"
        });
    }
>>>>>>> Stashed changes
}
