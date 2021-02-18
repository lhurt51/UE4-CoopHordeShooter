// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class CoopShooterTarget : TargetRules
{
	public CoopShooterTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V1;
		ExtraModuleNames.AddRange( new string[] { "CoopShooter" } );
	}
}
