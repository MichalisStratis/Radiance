// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FadeAnimationWidget.generated.h"

class UWidgetAnimation;

//-----------------------------------------------------------------------------------------------------------------------------
// Class Name			: UFadeAnimationWidget
// Author				: Michalis Stratis
// Classes Inherited	: UUserWidget
// Purpose				: This class is responsible to pla animations normally and in reverse
//-----------------------------------------------------------------------------------------------------------------------------
UCLASS()
class RADIANCE_API UFadeAnimationWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: NativeConstruct()
	// Author			: Unreal Engine 4
	// Editors			: Michalis Stratis
	// Purpose			: Creates the widget 
	//-----------------------------------------------------------------------------------------------------------------------------
	virtual void NativeConstruct() override;

	// Fade Animation. (Michalis Stratis)
	UPROPERTY ( Transient, BlueprintReadOnly,  meta = ( BindWidgetAnim ) )
		UWidgetAnimation* Fade_Effect;

public:
	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: PlayFadeAnimation()
	// Author			: Michalis Stratis
	// Purpose			: Play an Animation
	//-----------------------------------------------------------------------------------------------------------------------------
	void PlayFadeAnimation( );

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: PlayFadeReverseAnimation()
	// Author			: Michalis Stratis
	// Purpose			: Play an Animation In Reverse
	//-----------------------------------------------------------------------------------------------------------------------------
	void PlayFadeReverseAnimation( );
};
