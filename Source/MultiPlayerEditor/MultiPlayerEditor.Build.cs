using UnrealBuildTool;

public class MultiPlayerEditor : ModuleRules
{
	public MultiPlayerEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "MultiPlayer",
        });
        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "CoreUObject",
            "Engine",
            "UnrealEd",
            "ComponentVisualizers"
        });
        //PublicIncludePaths.Add(ModuleDirectory);

        PrivateIncludePaths.AddRange(new string[]
		{
            "MultiPlayerEditor"
        });
	}
}
