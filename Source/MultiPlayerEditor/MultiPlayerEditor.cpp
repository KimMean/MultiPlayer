// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiPlayerEditor.h"

#include "UnrealEd.h"

#include "ComponentVisualizer/ShapeComponentVisualizer.h"
#include "System/Visualizers/ShapeComponentVisualizer.h"

IMPLEMENT_GAME_MODULE(FMultiPlayerEditorModule, MultiPlayerEditor);


void FMultiPlayerEditorModule::StartupModule()
{
    if (GUnrealEd)
    {
        // Make a new instance of the visualizer
        TSharedPtr<FShapeComponentVisualizer> Visualizer = MakeShareable(new FShapeComponentVisualizer());
        // Register it to our specific component class
        GUnrealEd->RegisterComponentVisualizer(UShapeComponentVisualizer::StaticClass()->GetFName(), Visualizer);
        Visualizer->OnRegister();
    }
}

void FMultiPlayerEditorModule::ShutdownModule()
{
    if (GUnrealEd)
    {
        // Unregister when the module shuts down
        GUnrealEd->UnregisterComponentVisualizer(UShapeComponentVisualizer::StaticClass()->GetFName());
    }
}