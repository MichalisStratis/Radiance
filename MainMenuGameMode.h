#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuGameMode.generated.h"

class UMainMenuWidget;
class USplashSceneWidget;
class URadianceGameInstance;


//-----------------------------------------------------------------------------------------------------------------------------
// Class Name			: AMainMenuGameMode
// Author				: Michalis Stratis
// Classes Inherited	: AGameModeBase
// Purpose				: This class will call the main menu and splash scene widget on the screen
//-----------------------------------------------------------------------------------------------------------------------------

UCLASS()
class RADIANCE_API AMainMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	// The subclass of UMainMenuWidget that lets us include the actual widget 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<UMainMenuWidget>	           m_pcMenuWidget;

	// The subclass of USplashSceneWidget that lets us include the actual widget 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<USplashSceneWidget>          m_pcSplashWidget;

	// Determines if the game is starting or not
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic")
		bool bIsStart=true;

	//----------------------------------------------------------------------------------------------------------------------------
	// Constructor name		: AMainMenuGameMode()
	// Author				: Michalis Stratis
	// Notes				: 
	//----------------------------------------------------------------------------------------------------------------------------
	AMainMenuGameMode ( );

	//----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: BeginPlay() override
	// Author			: Unreal Engine 4
	// Editors			: Michalis Stratis
	// Purpose			: To determine if the game has started and the desired widgets on screen
	//----------------------------------------------------------------------------------------------------------------------------
	virtual void BeginPlay ( ) override;

private:
	// A pointer to the AMainMenuWidget class 
	UMainMenuWidget*		MenuWidget;

	// A pointer to the USplashSceneWidget class 
	USplashSceneWidget*		SplashWidget;

	// A pointer to the URadianceGameInstance class 
	URadianceGameInstance*	GameInstance;

	//----------------------------------------------------------------------------------------------------------------------------
	// Function Name	: CreateWidgets() 
	// Author			: Michalis Stratis
	// Purpose			: To create and add the desired widget on viewport 
	//----------------------------------------------------------------------------------------------------------------------------
	void CreateWidgets();

};
