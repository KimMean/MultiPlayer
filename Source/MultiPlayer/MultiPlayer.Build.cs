// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MultiPlayer : ModuleRules
{
	public MultiPlayer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
	    	"CoreUObject",
	    	"Engine",
       	    "InputCore",
	    	"HeadMountedDisplay",
            "EnhancedInput",
	    	"AIModule",
            "AnimGraphRuntime",
        });
        PublicIncludePaths.Add(ModuleDirectory);

        PrivateIncludePaths.AddRange(new string[]
		{
			"MultiPlayer"
		});
	}
}
