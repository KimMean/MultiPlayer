using UnrealBuildTool;

public class MultiPlayerEditor : ModuleRules
{
	public MultiPlayerEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "UnrealEd",
            "ComponentVisualizers",
            "MultiPlayer",
        });
        //PublicIncludePaths.Add(ModuleDirectory);

        PrivateIncludePaths.AddRange(new string[]
        {
            "MultiPlayerEditor"
        });
	}
}
