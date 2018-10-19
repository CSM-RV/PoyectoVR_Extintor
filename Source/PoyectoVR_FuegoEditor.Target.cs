// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class PoyectoVR_FuegoEditorTarget : TargetRules
{
	public PoyectoVR_FuegoEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "PoyectoVR_Fuego" } );
	}
}
