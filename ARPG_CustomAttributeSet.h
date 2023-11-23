// GAS AttributeSet 自动生成

#pragma once

#include "CoreMinimal.h"

#include "Attributes/GGA_AttributeSet.h"

#include "ARPG_CustomAttributeSet.generated.h"

namespace ARPG_CustomAttributeSet
{
	
	ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FirePower)
	
	ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(IcePower)
	
	ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(AttackPower)
	
}

UCLASS()
class ACTIONRPG_API UARPG_CustomAttributeSet : public UGGA_AttributeSet
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_FirePower, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData FirePower{ 100 };
	ATTRIBUTE_ACCESSORS(ThisClass, FirePower)

	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_IcePower, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData IcePower{ 10 };
	ATTRIBUTE_ACCESSORS(ThisClass, IcePower)

	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AttackPower, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData AttackPower{ 0.0 };
	ATTRIBUTE_ACCESSORS(ThisClass, AttackPower)

	

	
	UFUNCTION()
	void OnRep_FirePower(const FGameplayAttributeData& OldValue) const;

	UFUNCTION(BlueprintPure,meta=(DisplayName="GetFirePowerAttribute"), Category = "Attributes")
	static FGameplayAttribute Bp_GetFirePowerAttribute();

	UFUNCTION(BlueprintPure,meta=(DisplayName="GetFirePowerAttributeTag"), Category = "Attributes")
	static FGameplayTag Bp_GetFirePowerAttributeTag();

	/** Returns the value of FirePower Attribute from the ability system component belonging to Actor. */
	UFUNCTION(BlueprintPure, Category = "Ability|Attribute")
	static float GetFirePowerAttributeFromActor(const AActor* Actor,bool& bSuccessfullyFoundAttribute);

	
	UFUNCTION()
	void OnRep_IcePower(const FGameplayAttributeData& OldValue) const;

	UFUNCTION(BlueprintPure,meta=(DisplayName="GetIcePowerAttribute"), Category = "Attributes")
	static FGameplayAttribute Bp_GetIcePowerAttribute();

	UFUNCTION(BlueprintPure,meta=(DisplayName="GetIcePowerAttributeTag"), Category = "Attributes")
	static FGameplayTag Bp_GetIcePowerAttributeTag();

	/** Returns the value of IcePower Attribute from the ability system component belonging to Actor. */
	UFUNCTION(BlueprintPure, Category = "Ability|Attribute")
	static float GetIcePowerAttributeFromActor(const AActor* Actor,bool& bSuccessfullyFoundAttribute);

	
	UFUNCTION()
	void OnRep_AttackPower(const FGameplayAttributeData& OldValue) const;

	UFUNCTION(BlueprintPure,meta=(DisplayName="GetAttackPowerAttribute"), Category = "Attributes")
	static FGameplayAttribute Bp_GetAttackPowerAttribute();

	UFUNCTION(BlueprintPure,meta=(DisplayName="GetAttackPowerAttributeTag"), Category = "Attributes")
	static FGameplayTag Bp_GetAttackPowerAttributeTag();

	/** Returns the value of AttackPower Attribute from the ability system component belonging to Actor. */
	UFUNCTION(BlueprintPure, Category = "Ability|Attribute")
	static float GetAttackPowerAttributeFromActor(const AActor* Actor,bool& bSuccessfullyFoundAttribute);

	
};
