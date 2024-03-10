// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class MultiPlayerTarget : TargetRules
{
	public MultiPlayerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("MultiPlayer");

        if (bBuildEditor)   // 편집기 빌드에만 포함
        {
            ExtraModuleNames.Add("MultiPlayerEditor");
        }
    }
}
