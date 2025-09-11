// MyActor.cpp
#include "MyActor.h"
#include "Math/UnrealMathUtility.h" // FMath::RandRange, FMath::Sqrt

AMyActor::AMyActor()
    : PreviousLocation(FVector2D::ZeroVector)
    , CurrentLocation(FVector2D::ZeroVector)
    , TotalDistance(0.f)
    , TotalEventCount(0)
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    // ���� ��ǥ �α�
    UE_LOG(LogTemp, Log, TEXT("[BeginPlay] Start at (%.0f, %.0f)"),
        CurrentLocation.X, CurrentLocation.Y);

    // �䱸����: ���� �� ���� 10ȸ �̵� + �� ���� ��ǥ ���
    move(10);

    // ���
    UE_LOG(LogTemp, Log, TEXT("[Summary] TotalDistance=%.2f, EventCount=%d"),
        TotalDistance, TotalEventCount);
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // �� ������ BeginPlay���� ���� ����. �ʿ��ϸ� ���⼭ �ǽð� �̵� ���� �߰�.
}

int32 AMyActor::step()
{
    // �� ���� �� ��� 0 �Ǵ� 1�� �̵� �� "2 �̻� �̵� ����" ���� ����
    return FMath::RandRange(0, 1);
}

void AMyActor::TriggerEventWithProbability(float Probability)
{
    // Probability: 0~100(%) �� �ؼ�
    const float Clamped = FMath::Clamp(Probability, 0.f, 100.f);
    const int32 Roll = FMath::RandRange(1, 100);

    if (Roll <= Clamped)
    {
        ++TotalEventCount;
        UE_LOG(LogTemp, Warning, TEXT("[Event] Triggered! (roll=%d, p=%.0f%%, count=%d)"),
            Roll, Clamped, TotalEventCount);
    }
}

float AMyActor::Distance(FVector2D second, FVector2D first)
{
    const float dx = first.X - second.X;
    const float dy = first.Y - second.Y;
    return FMath::Sqrt(dx * dx + dy * dy);
}

void AMyActor::move(int32 MoveCount)
{
    // ���������� MoveCountȸ �̵��ϸ� �Ź� ��ǥ �α� ���
    for (int32 i = 1; i <= MoveCount; ++i)
    {
        PreviousLocation = CurrentLocation;

        const int32 sx = step();
        const int32 sy = step();

        CurrentLocation.X += sx;
        CurrentLocation.Y += sy;

        // �Ÿ�/�̺�Ʈ/�α�
        TotalDistance += Distance(CurrentLocation, PreviousLocation);
        TriggerEventWithProbability(10.f); // 10% Ȯ�� �̺�Ʈ (�ɼ�)

        UE_LOG(LogTemp, Log, TEXT("Step %d -> (%.0f, %.0f)"),
            i, CurrentLocation.X, CurrentLocation.Y);
    }
}
