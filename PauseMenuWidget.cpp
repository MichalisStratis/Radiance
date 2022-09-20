// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenuWidget.h"
#include "MainMenuWidget.h"
#include "OptionsMenuWidget.h"
#include "Components/Button.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Radiance/Player/PlayerCharacter.h"

void UPauseMenuWidget::NativeConstruct ( )
{
	// Call the native construct from the UUserWidget.
	Super::NativeConstruct ( );
	 
	// Creating the Main Menu Widget 
	MenuWidget = CreateWidget<UMainMenuWidget>( UGameplayStatics::GetPlayerController( GetWorld(), 0 ), 
												 m_pcMenuWidget );

	// Creating the Options Menu Widget 
	OptionsWidget = CreateWidget<UOptionsMenuWidget>( UGameplayStatics::GetPlayerController( GetWorld(), 0 ), 
												 m_pcOptionsWidget );

	// Adding OptionMenuOnTheScreen and setting it to hidden 
	OptionsWidget->AddToViewport ( );
	OptionsWidget->SetVisibility ( ESlateVisibility::Hidden );

	// On click functionality of the ReturnToMainMenu button 
	ReturnToMainMenu->OnClicked.AddDynamic ( this, &UPauseMenuWidget::MainMenuButtonClicked );
	ReturnToMainMenu->OnHovered.AddDynamic ( this, &UPauseMenuWidget::MainMenuButtonHovered );

	// On click functionality of the Resume button 
	ResumeButton->OnClicked.AddDynamic ( this, &UPauseMenuWidget::ResumeButtonClicked );
	ResumeButton->OnHovered.AddDynamic ( this, &UPauseMenuWidget::ResumeButtonHovered );

	// On click functionality of the Options button 
	Options->OnClicked.AddDynamic ( this, &UPauseMenuWidget::OptionsButtonClicked );
	Options->OnHovered.AddDynamic ( this, &UPauseMenuWidget::OptionsButtonHovered );

}

UPauseMenuWidget::~UPauseMenuWidget ( )
{
}

void UPauseMenuWidget::MainMenuButtonHovered ( )
{
	// Plays UI sound
	PlayUISound ( m_pcPauseHoveredSound );
}

void UPauseMenuWidget::MainMenuButtonClicked ( )
{
	// Plays UI sound
	PlayUISound ( m_pcButtonClickedSound );

	// Plays Fade Out Animation
	PlayAnimation ( FadeOut );

	if ( MenuWidget != nullptr ) 
	{
		GetWorld ( )->GetTimerManager ( ).SetTimer ( TimerHandle, [ & ] ()
			{
				 // Opening the final map (Michalis Stratis)
				 UGameplayStatics::OpenLevel ( this, "Map_MainMenuEnd" );

			}, 2, false );
	}
}


void UPauseMenuWidget::OptionsButtonHovered ( )
{
	// Plays UI Sound
	PlayUISound ( m_pcPauseHoveredSound );
}

void UPauseMenuWidget::OptionsButtonClicked ( )
{
	//Plays UI Sound
	PlayUISound ( m_pcOptionsButtonClickedSound );

	if ( OptionsWidget != nullptr )
	{
		// Setting this as the previous accessed widget to return here from the options
		OptionsWidget->SetPreviousAccessedWidget ( this );

		// Setting this widget's visibility to hidden and making Options Menu visible
		SetVisibility ( ESlateVisibility::Hidden );
		OptionsWidget->SetVisibility ( ESlateVisibility::Visible );
	}
	
}

void UPauseMenuWidget::ResumeButtonHovered ( )
{
	// Plays UI Sound
	PlayUISound ( m_pcPauseHoveredSound );
}

void UPauseMenuWidget::SetPlayerCharacter(APlayerCharacter* pcPlayer)
{
	// Setting the player pointer to APlayerCharacter object
	m_pcPlayer = pcPlayer;
}

void UPauseMenuWidget::ResumeButtonClicked ( )
{
	// Plays UI Sound
	PlayUISound ( m_pcButtonClickedSound );

	// Calling DisablePauseMenu to disable this menu
	m_pcPlayer->DisablePauseMenu();

	// Resuming the game
	UGameplayStatics::SetGamePaused(GetWorld( ), false );

}
