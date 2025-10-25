// Lycoris Bellua © All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class DESCENDINGDUDE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMyCharacter();

public:	
	virtual void FellOutOfWorld(const class UDamageType& dmgType) override;
};
