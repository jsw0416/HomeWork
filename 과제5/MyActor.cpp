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

    // 시작 좌표 로그
    UE_LOG(LogTemp, Log, TEXT("[BeginPlay] Start at (%.0f, %.0f)"),
        CurrentLocation.X, CurrentLocation.Y);

    // 요구사항: 스폰 시 랜덤 10회 이동 + 매 스텝 좌표 출력
    move(10);

    // 요약
    UE_LOG(LogTemp, Log, TEXT("[Summary] TotalDistance=%.2f, EventCount=%d"),
        TotalDistance, TotalEventCount);
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // 본 과제는 BeginPlay에서 전부 수행. 필요하면 여기서 실시간 이동 로직 추가.
}

int32 AMyActor::step()
{
    // 한 번에 각 축당 0 또는 1만 이동 → "2 이상 이동 금지" 조건 충족
    return FMath::RandRange(0, 1);
}

void AMyActor::TriggerEventWithProbability(float Probability)
{
    // Probability: 0~100(%) 로 해석
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
    // 시작점에서 MoveCount회 이동하며 매번 좌표 로그 출력
    for (int32 i = 1; i <= MoveCount; ++i)
    {
        PreviousLocation = CurrentLocation;

        const int32 sx = step();
        const int32 sy = step();

        CurrentLocation.X += sx;
        CurrentLocation.Y += sy;

        // 거리/이벤트/로그
        TotalDistance += Distance(CurrentLocation, PreviousLocation);
        TriggerEventWithProbability(10.f); // 10% 확률 이벤트 (옵션)

        UE_LOG(LogTemp, Log, TEXT("Step %d -> (%.0f, %.0f)"),
            i, CurrentLocation.X, CurrentLocation.Y);
    }
}
