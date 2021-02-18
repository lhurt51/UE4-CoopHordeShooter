// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class CoopShooterEditorTarget : TargetRules
{
	public CoopShooterEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V1;
		ExtraModuleNames.AddRange(new string[] { "CoopShooter" });
    }
}
