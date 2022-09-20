// Fill out your copyright notice in the Description page of Project Settings.


#include "FadeViewportClient.h"
#include "Engine/Canvas.h"

void UFadeViewportClient::PostRender(UCanvas* Canvas)
{
    UGameViewportClient::PostRender(Canvas);

    // Fade if requested, you could use the same DrawScreenFade method from any canvas such as the HUD
    if (bFading)
    {
        DrawScreenFade(Canvas);
    }
}

void UFadeViewportClient::ClearFade()
{
    // Indicating bFading to false so it does not fade 
    bFading = false;
}

void UFadeViewportClient::Fade(const float Duration, const bool bToBlack)
{
    // Setting UWorld pointer to GetWorld()
    const UWorld* world = GetWorld();
    if (world)
    {
        // Indicating bFading to true so it fades
        bFading = true;

        // Setting the duration of the fade and declaring bIfBlack so it fades to black
        this->bIfBlack = bToBlack;
        FadeDuration = Duration;

        // Setting the start time of the fade
        FadeStartTime = world->GetTimeSeconds();
    }
}

void UFadeViewportClient::DrawScreenFade ( UCanvas* Canvas )
{
    if ( bFading )
    {
        // Setting UWorld pointer to GetWorld()
        const UWorld* world = GetWorld ( );
        if ( world )
        {
            // Setting a time parameter 
            const float Time = world->GetTimeSeconds ( );

            // Using Math::Clamp so the the fade animation always has a min and max value
            const float Alpha = FMath::Clamp ( ( Time - FadeStartTime ) / FadeDuration, 0.f, 1.f );

            // Make sure that we stay black in a fade to black
            // Fading to black will be applied even if alpha is 1
            if ( Alpha == 1.f && !bIfBlack )
            {
                // Indicating bFading to false so it does not fade 
                bFading = false;
            }
            else
            {
                // Setting the canvas' current colour 
                FColor OldColor = Canvas->DrawColor;

                // Setting canvas' Fade colour to Black 
                FLinearColor FadeColor = FLinearColor::Black;

                // Dictating if the screen is black so the transition starts
                FadeColor.A = bIfBlack ? Alpha : 1 - Alpha;

                // Changing the colour of the canvas to black and then back to its old colour
                Canvas->DrawColor = FadeColor.ToFColor ( true ); 
                Canvas->DrawTile ( Canvas->DefaultTexture, 0, 0, Canvas->ClipX, Canvas->ClipY, 0, 0, Canvas->DefaultTexture->GetSizeX ( ), Canvas->DefaultTexture->GetSizeY ( ) );
                Canvas->DrawColor = OldColor;
            }
        }
    }
}
