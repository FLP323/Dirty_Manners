// Fill out your copyright notice in the Description page of Project Settings.


#include "DirtyMannersAttributeSet.h"
#include "DirtyMannersCharacter.h"

UDirtyMannersAttributeSet::UDirtyMannersAttributeSet()
{

}

void UDirtyMannersAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    ADirtyMannersCharacter* DirtyChar = Cast<ADirtyMannersCharacter>(GetOwningActor());
    if (!DirtyChar)
        return;

    if (Attribute == GetHealthAttribute())
        NewValue = FMath::Min(NewValue, static_cast<float>(DirtyChar->MaxHealth));
    else if (Attribute == GetArmorAttribute())
        NewValue = FMath::Min(NewValue, static_cast<float>(DirtyChar->MaxArmor));
    else if (Attribute == GetBulletsAttribute())
        NewValue = FMath::Clamp(NewValue, 0.0f, static_cast<float>(DirtyChar->MaxBullets));
    else if (Attribute == GetRocketsAttribute())
        NewValue = FMath::Clamp(NewValue, 0.0f, static_cast<float>(DirtyChar->MaxRockets));
    else if (Attribute == GetSoapAttribute())
        NewValue = FMath::Clamp(NewValue, 0.0f, static_cast<float>(DirtyChar->MaxSoap));
}

bool UDirtyMannersAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
    float AbsoluteMagnitude = FMath::Abs(Data.EvaluatedData.Magnitude);

    ADirtyMannersCharacter* DirtyChar = Cast<ADirtyMannersCharacter>(GetOwningActor());
    if (!DirtyChar)
        return false;

    if (Data.EvaluatedData.Magnitude > 0)
    {
        if (Data.EvaluatedData.Attribute == GetArmorAttribute() && GetArmor() + AbsoluteMagnitude >= DirtyChar->MaxArmor)
        {
            SetArmor(DirtyChar->MaxArmor);
            return false;
        }
        if (Data.EvaluatedData.Attribute == GetHealthAttribute() && GetHealth() + AbsoluteMagnitude >= DirtyChar->MaxHealth)
        {
            SetHealth(DirtyChar->MaxHealth);
            return false;
        }
        if (Data.EvaluatedData.Attribute == GetBulletsAttribute() && GetBullets() + AbsoluteMagnitude >= DirtyChar->MaxBullets)
        {
            SetBullets(DirtyChar->MaxBullets);
            return false;
        }
        if (Data.EvaluatedData.Attribute == GetRocketsAttribute() && GetRockets() + AbsoluteMagnitude >= DirtyChar->MaxRockets)
        {
            SetRockets(DirtyChar->MaxRockets);
            return false;
        }
        if (Data.EvaluatedData.Attribute == GetSoapAttribute() && GetSoap() + AbsoluteMagnitude >= DirtyChar->MaxSoap)
        {
            SetSoap(DirtyChar->MaxSoap);
            return false;
        }
    }

    return true;
}

void UDirtyMannersAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    ADirtyMannersCharacter* DirtyChar = Cast<ADirtyMannersCharacter>(GetOwningActor());
    if (!DirtyChar)
        return;

    if (Data.EvaluatedData.Attribute == GetArmorAttribute())
    {
        if (GetArmor() < 0.0f)
        {
            const float Overflow = -GetArmor();
            SetArmor(0.0f);

            const float NewHealth = FMath::Max(0.0f, GetHealth() - Overflow);
            SetHealth(NewHealth);
        }
        else if (GetArmor() > DirtyChar->MaxArmor)
        {
            SetArmor(DirtyChar->MaxArmor);
        }
    }
    else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        if (GetHealth() < 0.0f)
        {
            SetHealth(0.0f);
        }
        else if (GetHealth() > DirtyChar->MaxHealth)
        {
            SetHealth(DirtyChar->MaxHealth);
        }
    }
    else if (Data.EvaluatedData.Attribute == GetBulletsAttribute())
    {
        if (GetBullets() < 0.0f)
        {
            SetBullets(0.0f);
        }
        else if (GetBullets() > DirtyChar->MaxBullets)
        {
            SetBullets(DirtyChar->MaxBullets);
        }
    }
    else if (Data.EvaluatedData.Attribute == GetRocketsAttribute())
    {
        if (GetRockets() < 0.0f)
        {
            SetRockets(0.0f);
        }
        else if (GetRockets() > DirtyChar->MaxRockets)
        {
            SetRockets(DirtyChar->MaxRockets);
        }
    }
    else if (Data.EvaluatedData.Attribute == GetSoapAttribute())
    {
        if (GetSoap() < 0.0f)
        {
            SetSoap(0.0f);
        }
        else if (GetSoap() > DirtyChar->MaxSoap)
        {
            SetSoap(DirtyChar->MaxSoap);
        }
    }
}
