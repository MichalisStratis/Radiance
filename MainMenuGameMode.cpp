// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameMode.h"
#include "Menus/MainMenuWidget.h"
#include "Menus/OptionsMenuWidget.h"
#include "Menus/PauseMenuWidget.h"
#include "Menus/SplashSceneWidget.h"
#include "Menus/GameOverMenuWidget.h"
#include <Kismet/GameplayStatics.h>

#include "RadianceGameInstance.h"


AMainMenuGameMode::AMainMenuGameMode ( )
{

}

void AMainMenuGameMode::BeginPlay ( )
{
	Super::BeginPlay ( );

	// Create an instance of the game instance in order to load the save game file (Nikodem Hamrol).
	GameInstance = Cast<URadianceGameInstance>( UGameplayStatics::GetGameInstance( GetWorld() ) );

	// Check if the game instance exists (Nikodem Hamrol).
	if( GameInstance != nullptr )
	{
		// With the game instance check if the save game file exists (Nikodem Hamrol).
		GameInstance->CheckIfSaveGameExists();
	}

	if ( !GameInstance->GetHasGameStarted() )
	{
		//Creating the Splash Scene Widget and Adding it on viewport
		SplashWidget = CreateWidget<USplashSceneWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0),
														 m_pcSplashWidget);
		SplashWidget->AddToViewport ( );

		FTimerHandle TimerHandle;
		GetWorld ( )->GetTimerManager ( ).SetTimer ( TimerHandle, [ & ] ( )
													 {
														 // Removing splashscene from parent, setting the m_bHasGameStarted pointer to true 
														 SplashWidget->RemoveFromParent ( );
														 GameInstance->SetHasGameStarted ( true );

														 // Adding the widgets
														 CreateWidgets();

													 }, 14, false );

	}
	else 
	{
		// Adding the widgets
		CreateWidgets();
	}
}

void AMainMenuGameMode::CreateWidgets()
{
	//Creating the Main Menu Widget 
	MenuWidget = CreateWidget<UMainMenuWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0),
												m_pcMenuWidget);
		

	if ( MenuWidget != nullptr)
	{
		// Adding the MenuWidget on the screen 
		MenuWidget->AddToViewport();
	}
}
