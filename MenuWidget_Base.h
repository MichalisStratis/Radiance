// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget_Base.generated.h"

/**
 * 
 */

UCLASS()
class RADIANCE_API UMenuWidget_Base : public UUserWidget
{
	GENERATED_BODY()

protected:
	// Creates a Quit Game button
	UPROPERTY ( meta = ( BindWidget ) )
		class UButton* QuitGame;

	// Creates an Image Background
	UPROPERTY ( meta = ( BindWidget ) )
		class UImage* Background;

	// Creates a USoundBase sound for when a button is clicked
	UPROPERTY( Category = Audio, EditDefaultsOnly, meta = ( DisplayName = "Main Button Clicked" ) )
		USoundBase*							m_pcButtonClickedSound;

	// Creates a USoundBase sound for when a main button is hovered
	UPROPERTY( Category = Audio, EditDefaultsOnly, meta = ( DisplayName = "Main Button Hovered" ) )
		USoundBase*							m_pcButtonHoveredSound;

	// Creates a USoundBase sound for when the options button is clicked
	UPROPERTY( Category = Audio, EditDefaultsOnly, meta = ( DisplayName = "Options Button Clicked" ) )
		USoundBase*							m_pcOptionsButtonClickedSound;

	// Creates a USoundBase sound for when a pause button is clicked
	UPROPERTY( Category = Audio, EditDefaultsOnly, meta = ( DisplayName = "Pause UI Sound Clicked" ) )
		USoundBase*							m_pcPauseClickedSound;

	// Creates a USoundBase sound for when a pause button is hovered
	UPROPERTY( Category = Audio, EditDefaultsOnly, meta = ( DisplayName = "Pause UI Sound Hovered" ) )
		USoundBase*							m_pcPauseHoveredSound;

	// Fade Out Animation. (Michalis Stratis)
	UPROPERTY ( Transient, meta = ( BindWidgetAnim ) )
		UWidgetAnimation* FadeOut;

	// Fade In Animation. (Michalis Stratis)
	UPROPERTY ( Transient, meta = ( BindWidgetAnim ) )
		UWidgetAnimation* FadeIn;

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: NativeConstruct()
	// Author			: Unreal Engine 4
	// Editors          : Michalis Stratis
	// Purpose			: Creates the widget
	//-----------------------------------------------------------------------------------------------------------------------------
	virtual void NativeConstruct() override;

private:
	// A pointer APlayerController class 
	APlayerController* PC;

public:

	//-----------------------------------------------------------------------------------------------------------------------------
	// Destructors Name	: ~UMain_MenuWidget()
	// Author			: Michalis Stratis
	// Purpose			: UMenuWidget_Base destructor
	//-----------------------------------------------------------------------------------------------------------------------------
	~UMenuWidget_Base ( );

	// FTimer Handle variable that is used for timers and delays
	FTimerHandle TimerHandle;

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: QuitGameButtonClicked()
	// Author			: Michalis Stratis
	// Purpose			: The functionality of the quit button when clicked 
	//-----------------------------------------------------------------------------------------------------------------------------
	UFUNCTION()
		void QuitGameButtonClicked( );

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: QuitGameButtonHovered()
	// Author			: Michalis Stratis
	// Purpose			: The functionality of the quit button when hovered
	//-----------------------------------------------------------------------------------------------------------------------------
	UFUNCTION()
		void QuitGameButtonHovered( );

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: ShowMenu()
	// Author			: Michalis Stratis
	// Purpose			: This function shows the menu 
	//-----------------------------------------------------------------------------------------------------------------------------
	void ShowMenu ( );

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: HideMenu()
	// Author			: Michalis Stratis
	// Purpose			: This function hides the menu 
	//-----------------------------------------------------------------------------------------------------------------------------
	void HideMenu ( );

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: GoToMap()
	// Author			: Michalis Stratis
	// Purpose			: This function transitions to a specific map/level
	//-----------------------------------------------------------------------------------------------------------------------------
	void GoToMap ( FName level );

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: ExitGame()
	// Author			: Michalis Stratis
	// Purpose			: This function quits the game
	//-----------------------------------------------------------------------------------------------------------------------------
	void	ExitGame ( );
	
	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: PlayUISound()
	// Author			: Michalis Stratis
	// Purpose			: This function plays a USoundBase audio
	//-----------------------------------------------------------------------------------------------------------------------------
	void PlayUISound ( USoundBase* UIAudio );
};
