// GAS AttributeSet 自动生成


#include "Attributes/ARPG_CustomAttributeSet.h"

#include "Net/UnrealNetwork.h"

#include "AbilitySystemBlueprintLibrary.h"

namespace ARPG_CustomAttributeSet
{

    UE_DEFINE_GAMEPLAY_TAG(Health, TEXT("ActionRpg.Attribute.Health"))

    UE_DEFINE_GAMEPLAY_TAG(MaxHealth, TEXT("ActionRpg.Attribute.MaxHealth"))

    UE_DEFINE_GAMEPLAY_TAG(Mana, TEXT("ActionRpg.Attribute.Mana"))

    UE_DEFINE_GAMEPLAY_TAG(MaxMana, TEXT("ActionRpg.Attribute.MaxMana"))

}

void UARPG_CustomAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    
    DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Health, COND_OwnerOnly, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxHealth, COND_OwnerOnly, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, Mana, COND_OwnerOnly, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, MaxMana, COND_OwnerOnly, REPNOTIFY_Always);
    
}


void UARPG_CustomAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	// This is called whenever attributes change, so for max health/mana we want to scale the current totals to match
	Super::PreAttributeChange(Attribute, NewValue);

    
    if (Attribute == GetMaxHealthAttribute())
    {
        AdjustAttributeForMaxChange(Health, MaxHealth, NewValue, GetHealthAttribute());
    }
    

    

    
    if (Attribute == GetMaxManaAttribute())
    {
        AdjustAttributeForMaxChange(Mana, MaxMana, NewValue, GetManaAttribute());
    }
    

    

}

void UARPG_CustomAttributeSet::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue,
                                                   const FGameplayAttribute& AffectedAttributeProperty)
{
	UAbilitySystemComponent* AbilityComp = GetOwningAbilitySystemComponent();
	const float CurrentMaxValue = MaxAttribute.GetCurrentValue();
	if (!FMath::IsNearlyEqual(CurrentMaxValue, NewMaxValue) && AbilityComp)
	{
		// Change current value to maintain the current Val / Max percent
		const float CurrentValue = AffectedAttribute.GetCurrentValue();
		float NewDelta = (CurrentMaxValue > 0.f) ? (CurrentValue * NewMaxValue / CurrentMaxValue) - CurrentValue : NewMaxValue;

		AbilityComp->ApplyModToAttributeUnsafe(AffectedAttributeProperty, EGameplayModOp::Additive, NewDelta);
	}
}



FGameplayAttribute UARPG_CustomAttributeSet::Bp_GetHealthAttribute()
{
    return ThisClass::GetHealthAttribute();
}

FGameplayTag UARPG_CustomAttributeSet::Bp_GetHealthAttributeTag()
{
return ARPG_CustomAttributeSet::Health;
}

float UARPG_CustomAttributeSet::GetHealthAttributeFromActor(const AActor* Actor, bool& bSuccessfullyFoundAttribute)
{
    return UAbilitySystemBlueprintLibrary::GetFloatAttribute(Actor,GetHealthAttribute(),bSuccessfullyFoundAttribute);
}

void UARPG_CustomAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Health, OldValue);
}



FGameplayAttribute UARPG_CustomAttributeSet::Bp_GetMaxHealthAttribute()
{
    return ThisClass::GetMaxHealthAttribute();
}

FGameplayTag UARPG_CustomAttributeSet::Bp_GetMaxHealthAttributeTag()
{
return ARPG_CustomAttributeSet::MaxHealth;
}

float UARPG_CustomAttributeSet::GetMaxHealthAttributeFromActor(const AActor* Actor, bool& bSuccessfullyFoundAttribute)
{
    return UAbilitySystemBlueprintLibrary::GetFloatAttribute(Actor,GetMaxHealthAttribute(),bSuccessfullyFoundAttribute);
}

void UARPG_CustomAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxHealth, OldValue);
}



FGameplayAttribute UARPG_CustomAttributeSet::Bp_GetManaAttribute()
{
    return ThisClass::GetManaAttribute();
}

FGameplayTag UARPG_CustomAttributeSet::Bp_GetManaAttributeTag()
{
return ARPG_CustomAttributeSet::Mana;
}

float UARPG_CustomAttributeSet::GetManaAttributeFromActor(const AActor* Actor, bool& bSuccessfullyFoundAttribute)
{
    return UAbilitySystemBlueprintLibrary::GetFloatAttribute(Actor,GetManaAttribute(),bSuccessfullyFoundAttribute);
}

void UARPG_CustomAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldValue) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, Mana, OldValue);
}



FGameplayAttribute UARPG_CustomAttributeSet::Bp_GetMaxManaAttribute()
{
    return ThisClass::GetMaxManaAttribute();
}

FGameplayTag UARPG_CustomAttributeSet::Bp_GetMaxManaAttributeTag()
{
return ARPG_CustomAttributeSet::MaxMana;
}

float UARPG_CustomAttributeSet::GetMaxManaAttributeFromActor(const AActor* Actor, bool& bSuccessfullyFoundAttribute)
{
    return UAbilitySystemBlueprintLibrary::GetFloatAttribute(Actor,GetMaxManaAttribute(),bSuccessfullyFoundAttribute);
}

void UARPG_CustomAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldValue) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, MaxMana, OldValue);
}

