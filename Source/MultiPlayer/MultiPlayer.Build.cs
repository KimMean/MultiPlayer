using UnrealBuildTool;
using UnrealBuildTool.Rules;

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
			"UMG",
            "NavigationSystem",
        });
        PublicIncludePaths.Add(ModuleDirectory);

        PrivateIncludePaths.AddRange(new string[]
		{
			"MultiPlayer"
		});
	}
}
