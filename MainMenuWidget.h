// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget_Base.h"
#include "MainMenuWidget.generated.h"

//-----------------------------------------------------------------------------------------------------------------------------
// Class Name			: AMainMenuWidget
// Author				: Michalis Stratis
// Classes Inherited	: UUserWidget
// Purpose				: This class will hold the widget for the main menu 
//-----------------------------------------------------------------------------------------------------------------------------
class UOptionsMenuWidget;
class UFadeAnimationWidget;
class USplashSceneWidget;

UCLASS()
class RADIANCE_API UMainMenuWidget : public UMenuWidget_Base
{
	GENERATED_BODY()

protected:

	// Creating Start Game Button
	UPROPERTY ( meta = ( BindWidget ) )
		class UButton*											StartGame;

	// Creating Options Button
	UPROPERTY ( meta = ( BindWidget ) )
		class UButton*											Options;

	// The subclass of UOptionsMenuWidget that lets us include the actual widget 
	UPROPERTY( EditDefaultsOnly,BlueprintReadWrite )
		TSubclassOf<UOptionsMenuWidget>							m_pcOptionsWidget;


	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: NativeConstruct()
	// Author			: Michalis Stratis
	// Purpose			: 
	//-----------------------------------------------------------------------------------------------------------------------------
	virtual void NativeConstruct() override;

public:
	// A pointer to UOptionsMenuWidget
	UOptionsMenuWidget* OptionsWidget;
	
	// A pointer to UFadeAnimationWidget
	UFadeAnimationWidget* FadeWidget;

	// A pointer to USplashSceneWidget
	USplashSceneWidget* SplashWidget;

	//-----------------------------------------------------------------------------------------------------------------------------
	// Destructor Name	: ~UMain_MenuWidget()
	// Author			: Michalis Stratis
	// Purpose			: UMain_MenuWidget destructor
	//-----------------------------------------------------------------------------------------------------------------------------
	~UMainMenuWidget ( );

	//-----------------------------------------------------------------------------------------------------------------------------
	// Constructor Name	: UMain_MenuWidget()
	// Author			: Michalis Stratis
	// Purpose			: UMain_MenuWidget constructor
	//-----------------------------------------------------------------------------------------------------------------------------
	UMainMenuWidget ( );

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: StartGameButtonClicked()
	// Author			: Michalis Stratis
	// Purpose			: The functionality of the play button when clicked 
	//-----------------------------------------------------------------------------------------------------------------------------
	UFUNCTION()
		void StartGameButtonClicked();

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: StartGameButtonClicked()
	// Author			: Michalis Stratis
	// Purpose			: The functionality of the play button when hovered 
	//-----------------------------------------------------------------------------------------------------------------------------
	UFUNCTION()
		void StartGameButtonHovered();

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: OptionsButtonClicked()
	// Author			: Michalis Stratis
	// Purpose			: The functionality of the options button when clicked 
	//-----------------------------------------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable)
		void OptionsButtonClicked();

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: StartGameButtonClicked()
	// Author			: Michalis Stratis
	// Purpose			: The functionality of the play button when hovered 
	//-----------------------------------------------------------------------------------------------------------------------------
	UFUNCTION()
		void  OptionsButtonHovered();


};
