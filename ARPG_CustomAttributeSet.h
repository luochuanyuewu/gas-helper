// GAS AttributeSet 自动生成

#pragma once

#include "CoreMinimal.h"

#include "Attributes/GGA_AttributeSet.h"

#include "ARPG_CustomAttributeSet.generated.h"

namespace ARPG_CustomAttributeSet
{
	
	ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Health)
	
	ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MaxHealth)
	
	ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Mana)
	
	ACTIONRPG_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MaxMana)
	
}

UCLASS()
class ACTIONRPG_API UARPG_CustomAttributeSet : public UGGA_AttributeSet
{
	GENERATED_BODY()

public:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;


	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Health{ 100 };
	ATTRIBUTE_ACCESSORS(ThisClass, Health)

	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth{ 10 };
	ATTRIBUTE_ACCESSORS(ThisClass, MaxHealth)

	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Mana{ 0.0 };
	ATTRIBUTE_ACCESSORS(ThisClass, Mana)

	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxMana{ 100 };
	ATTRIBUTE_ACCESSORS(ThisClass, MaxMana)

	

	
	UFUNCTION()

	UFUNCTION(BlueprintPure,meta=(DisplayName="GetHealthAttribute"), Category = "Attributes")
	static FGameplayAttribute Bp_GetHealthAttribute();

	UFUNCTION(BlueprintPure,meta=(DisplayName="GetHealthAttributeTag"), Category = "Attributes")
	static FGameplayTag Bp_GetHealthAttributeTag();

	/** Returns the value of Health Attribute from the ability system component belonging to Actor. */
	UFUNCTION(BlueprintPure, Category = "Ability|Attribute")
	static float GetHealthAttributeFromActor(const AActor* Actor,bool& bSuccessfullyFoundAttribute);

	
	UFUNCTION()

	UFUNCTION(BlueprintPure,meta=(DisplayName="GetMaxHealthAttribute"), Category = "Attributes")
	static FGameplayAttribute Bp_GetMaxHealthAttribute();

	UFUNCTION(BlueprintPure,meta=(DisplayName="GetMaxHealthAttributeTag"), Category = "Attributes")
	static FGameplayTag Bp_GetMaxHealthAttributeTag();

	/** Returns the value of MaxHealth Attribute from the ability system component belonging to Actor. */
	UFUNCTION(BlueprintPure, Category = "Ability|Attribute")
	static float GetMaxHealthAttributeFromActor(const AActor* Actor,bool& bSuccessfullyFoundAttribute);

	
	UFUNCTION()

	UFUNCTION(BlueprintPure,meta=(DisplayName="GetManaAttribute"), Category = "Attributes")
	static FGameplayAttribute Bp_GetManaAttribute();

	UFUNCTION(BlueprintPure,meta=(DisplayName="GetManaAttributeTag"), Category = "Attributes")
	static FGameplayTag Bp_GetManaAttributeTag();

	/** Returns the value of Mana Attribute from the ability system component belonging to Actor. */
	UFUNCTION(BlueprintPure, Category = "Ability|Attribute")
	static float GetManaAttributeFromActor(const AActor* Actor,bool& bSuccessfullyFoundAttribute);

	
	UFUNCTION()

	UFUNCTION(BlueprintPure,meta=(DisplayName="GetMaxManaAttribute"), Category = "Attributes")
	static FGameplayAttribute Bp_GetMaxManaAttribute();

	UFUNCTION(BlueprintPure,meta=(DisplayName="GetMaxManaAttributeTag"), Category = "Attributes")
	static FGameplayTag Bp_GetMaxManaAttributeTag();

	/** Returns the value of MaxMana Attribute from the ability system component belonging to Actor. */
	UFUNCTION(BlueprintPure, Category = "Ability|Attribute")
	static float GetMaxManaAttributeFromActor(const AActor* Actor,bool& bSuccessfullyFoundAttribute);

	

protected:

	/** Helper function to proportionally adjust the value of an attribute when it's associated max attribute changes. (i.e. When MaxHealth increases, Health increases by an amount that maintains the same percentage as before) */
	virtual void AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty);



	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldValue) const;

	
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldValue) const;

	
	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldValue) const;

	
	UFUNCTION()
	virtual void OnRep_MaxMana(const FGameplayAttributeData& OldValue) const;

	
};
