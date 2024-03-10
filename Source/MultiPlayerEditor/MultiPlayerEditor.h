// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "Modules/ModuleInterface.h"


class FMultiPlayerEditorModule : public IModuleInterface
{
public:
	// ~Begin IModuleInterface 
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	// ~End IModuleInterface 
};