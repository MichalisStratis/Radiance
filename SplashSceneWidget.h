// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SplashSceneWidget.generated.h"

//-----------------------------------------------------------------------------------------------------------------------------
// Class Name			: USplashSceneWidget
// Author				: Michalis Stratis
// Classes Inherited	: UUserWidget
// Purpose				: This class will create a splash scene widget to be initialised in different parts of the code
//-----------------------------------------------------------------------------------------------------------------------------
UCLASS()
class RADIANCE_API USplashSceneWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: NativeConstruct()
	// Author			: Michalis Stratis
	// Purpose			: Creating the widget
	//-----------------------------------------------------------------------------------------------------------------------------
	virtual void NativeConstruct() override;

};
