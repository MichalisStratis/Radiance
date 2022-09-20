// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseButtonWidget.generated.h"

class UPauseMenuWidget;

//-----------------------------------------------------------------------------------------------------------------------------
// Class Name			: UPauseButtonWidget
// Author				: Michalis Stratis
// Classes Inherited	: UUserWidget
// Purpose				: This class will create the pause menu widget on the screen and pause the game 
//-----------------------------------------------------------------------------------------------------------------------------
UCLASS()
class RADIANCE_API UPauseButtonWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	// Creates a Pause Button
	UPROPERTY ( meta = ( BindWidget ) )
		class UButton* PauseButton;

	//----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: NativeConstruct() override
	// Author			: Unreal Engine 4
	// Editors			: Michalis Stratis
	// Purpose			: To create and add PauseMenuWidget on screen and pause the game 
	//----------------------------------------------------------------------------------------------------------------------------
	virtual void NativeConstruct() override;

	// The subclass of UPauseMenuWidget that lets us include the actual widget 
	UPROPERTY( EditDefaultsOnly,BlueprintReadWrite )
		TSubclassOf<UPauseMenuWidget>			m_pcPauseWidget;

public:

	//-----------------------------------------------------------------------------------------------------------------------------
	// Destructor Name	: ~UMain_MenuWidget()
	// Author			: Michalis Stratis
	// Purpose			: UMain_MenuWidget destructor
	//-----------------------------------------------------------------------------------------------------------------------------
	~UPauseButtonWidget ( );

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: StartGameButtonClicked()
	// Author			: Michalis Stratis
	// Purpose			: The functionality of the play button when clicked 
	//-----------------------------------------------------------------------------------------------------------------------------
	UFUNCTION()
		void PauseButtonClicked();

private:
		// A pointer to UPauseMenuWidget class
		UPauseMenuWidget* PauseWidget;
};

