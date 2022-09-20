// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget_Base.h"
#include "GameOverMenuWidget.generated.h"

//-----------------------------------------------------------------------------------------------------------------------------
// Class Name			: UGameOverMenuWidget
// Author				: Michalis Stratis
// Classes Inherited	: UMenuWidget_Base
// Purpose				: This class will hold the functionality of the Game Over Menu
//-----------------------------------------------------------------------------------------------------------------------------
UCLASS()
class RADIANCE_API UGameOverMenuWidget : public UMenuWidget_Base
{
	GENERATED_BODY()

protected:

	UPROPERTY ( meta = ( BindWidget ) )
		class UButton* PlayAgain;

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: NativeConstruct()
	// Author			: Michalis Stratis
	// Purpose			: Creating the widget
	//-----------------------------------------------------------------------------------------------------------------------------
	virtual void NativeConstruct() override;

public:
	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: ~UGameOverMenuWidget()
	// Author			: Michalis Stratis
	// Purpose			: UMain_MenuWidget destructor
	//-----------------------------------------------------------------------------------------------------------------------------
	~UGameOverMenuWidget ( );

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: ~UGameOverMenuWidget()
	// Author			: Michalis Stratis
	// Purpose			: UMain_MenuWidget constructor
	//-----------------------------------------------------------------------------------------------------------------------------
	UGameOverMenuWidget ( );

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: PlayAgainButtonClicked()
	// Author			: Michalis Stratis
	// Purpose			: The functionality of the play again button when clicked 
	//-----------------------------------------------------------------------------------------------------------------------------
	UFUNCTION()
		void PlayAgainButtonClicked();

	//-----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: PlayAgainButtonHovered()
	// Author			: Michalis Stratis
	// Purpose			: The functionality of the play again button when hovered 
	//-----------------------------------------------------------------------------------------------------------------------------
	UFUNCTION()
		void PlayAgainButtonHovered();
	
};
