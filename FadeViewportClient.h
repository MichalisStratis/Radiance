// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "FadeViewportClient.generated.h"

/**
 * 
 */
class UCanvas;
UCLASS()
class RADIANCE_API UFadeViewportClient : public UGameViewportClient
{
	GENERATED_BODY()
	
public:

    //----------------------------------------------------------------------------------------------------------------------------
    // Function Name	: PostRender() override
    // Author			: Unreal Engine 4
    // Editors			: Michalis Stratis
    // Purpose			: To add fade animation if requested from any canvas.
    //----------------------------------------------------------------------------------------------------------------------------
    virtual void PostRender( UCanvas* Canvas ) override;

    //----------------------------------------------------------------------------------------------------------------------------
    // Function Name	: ClearFade() override
    // Author			: Unreal Engine 4
    // Editors			: Michalis Stratis
    // Purpose			: To indicate if we want the fade to start or not
    //----------------------------------------------------------------------------------------------------------------------------
    virtual void ClearFade();

    //----------------------------------------------------------------------------------------------------------------------------
    // Function Name	: Fade() override
    // Author			: Unreal Engine 4
    // Editors			: Michalis Stratis
    // Purpose			: To set the necessary parameters of the fade.
    //----------------------------------------------------------------------------------------------------------------------------
    virtual void Fade(const float Duration, const bool bToBlack);

    //----------------------------------------------------------------------------------------------------------------------------
    // Function Name	: Fade() override
    // Authors			: Michalis Stratis
    // Purpose			: To drwa the fade on screen.
    //---------------------------------------------------------------------------------------------------------------------------- 
    void DrawScreenFade(UCanvas* Canvas);

private:
    uint32 bFading : 1;
    uint32 bIfBlack : 1; 
    float FadeAlpha;
    float FadeStartTime;
    float FadeDuration;
};
