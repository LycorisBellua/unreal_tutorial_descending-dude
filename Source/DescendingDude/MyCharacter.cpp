// Lycoris Bellua © All Rights Reserved

#include "MyCharacter.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"

AMyCharacter::AMyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMyCharacter::FellOutOfWorld(const class UDamageType& dmgType)
{
    TArray<AActor*> PlayerStarts;
    FVector StartLocation;
    FRotator StartRotation;
    AController* PlayerController;

    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), PlayerStarts);
    if (PlayerStarts.Num() > 0)
    {
        StartLocation = PlayerStarts[0]->GetActorLocation();
        StartRotation = PlayerStarts[0]->GetActorRotation();
        SetActorLocation(StartLocation);
        SetActorRotation(StartRotation);

        PlayerController = GetController();
        if (PlayerController)
            PlayerController->SetControlRotation(StartRotation);
    }
}