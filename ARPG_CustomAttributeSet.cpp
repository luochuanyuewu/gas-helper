// GAS AttributeSet 自动生成


#include "Attributes/ARPG_CustomAttributeSet.h"

#include "Net/UnrealNetwork.h"

#include "AbilitySystemBlueprintLibrary.h"


namespace ARPG_CustomAttributeSet
{

    UE_DEFINE_GAMEPLAY_TAG(FirePower, TEXT("ActionRpg.Attribute.FirePower"))

    UE_DEFINE_GAMEPLAY_TAG(IcePower, TEXT("ActionRpg.Attribute.IcePower"))

    UE_DEFINE_GAMEPLAY_TAG(AttackPower, TEXT("ActionRpg.Attribute.AttackPower"))

}

void UARPG_CustomAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    
    DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, FirePower, COND_OwnerOnly, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, IcePower, COND_OwnerOnly, REPNOTIFY_Always);
    
    DOREPLIFETIME_CONDITION_NOTIFY(ThisClass, AttackPower, COND_OwnerOnly, REPNOTIFY_Always);
    
}


void UARPG_CustomAttributeSet::OnRep_FirePower(const FGameplayAttributeData& OldValue) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, FirePower, OldValue);
}

FGameplayAttribute UARPG_CustomAttributeSet::Bp_GetFirePowerAttribute()
{
    return ThisClass::GetFirePowerAttribute();
}

FGameplayTag UARPG_CustomAttributeSet::Bp_GetFirePowerAttributeTag()
{
return ARPG_CustomAttributeSet::FirePower;
}

float UARPG_CustomAttributeSet::GetFirePowerAttributeFromActor(const AActor* Actor, bool& bSuccessfullyFoundAttribute)
{
    return UAbilitySystemBlueprintLibrary::GetFloatAttribute(Actor,GetFirePowerAttribute(),bSuccessfullyFoundAttribute);
}

void UARPG_CustomAttributeSet::OnRep_IcePower(const FGameplayAttributeData& OldValue) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, IcePower, OldValue);
}

FGameplayAttribute UARPG_CustomAttributeSet::Bp_GetIcePowerAttribute()
{
    return ThisClass::GetIcePowerAttribute();
}

FGameplayTag UARPG_CustomAttributeSet::Bp_GetIcePowerAttributeTag()
{
return ARPG_CustomAttributeSet::IcePower;
}

float UARPG_CustomAttributeSet::GetIcePowerAttributeFromActor(const AActor* Actor, bool& bSuccessfullyFoundAttribute)
{
    return UAbilitySystemBlueprintLibrary::GetFloatAttribute(Actor,GetIcePowerAttribute(),bSuccessfullyFoundAttribute);
}

void UARPG_CustomAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldValue) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass, AttackPower, OldValue);
}

FGameplayAttribute UARPG_CustomAttributeSet::Bp_GetAttackPowerAttribute()
{
    return ThisClass::GetAttackPowerAttribute();
}

FGameplayTag UARPG_CustomAttributeSet::Bp_GetAttackPowerAttributeTag()
{
return ARPG_CustomAttributeSet::AttackPower;
}

float UARPG_CustomAttributeSet::GetAttackPowerAttributeFromActor(const AActor* Actor, bool& bSuccessfullyFoundAttribute)
{
    return UAbilitySystemBlueprintLibrary::GetFloatAttribute(Actor,GetAttackPowerAttribute(),bSuccessfullyFoundAttribute);
}
