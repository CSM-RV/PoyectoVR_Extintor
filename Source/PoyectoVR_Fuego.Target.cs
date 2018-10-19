// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class PoyectoVR_FuegoTarget : TargetRules
{
	public PoyectoVR_FuegoTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "PoyectoVR_Fuego" } );
	}
}
