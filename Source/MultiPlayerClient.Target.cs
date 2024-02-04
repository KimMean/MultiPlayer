// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class MultiPlayerClientTarget : TargetRules
{
	public MultiPlayerClientTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Client;
        DefaultBuildSettings = BuildSettingsVersion.V4;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
        ExtraModuleNames.Add("MultiPlayer");
	}
}
