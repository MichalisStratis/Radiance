// Fill out your copyright notice in the Description page of Project Settings.


#include "FadeAnimationWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UFadeAnimationWidget::NativeConstruct ( )
{
	Super::NativeConstruct ( );

	// Calls PlayFadeAnimation() function 
	PlayFadeAnimation ( );
}

void UFadeAnimationWidget::PlayFadeAnimation ( )
{
	// Plays animation
	PlayAnimation ( Fade_Effect );
}

void UFadeAnimationWidget::PlayFadeReverseAnimation ( )
{
	// Plays Animation in reverse
	PlayAnimationReverse ( Fade_Effect );
}
