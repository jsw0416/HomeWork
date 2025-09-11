// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HOMEWORK5_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//기능구현에 필요한 멤버 변수 ( 클래스의 속성 )
	FVector2D PreviousLocation; //이전 위치
	FVector2D CurrentLocation; // 현재 위치를 담는 좌표

	float TotalDistance;
	int32 TotalEventCount;
	//기능 구현에 필요한 멤버 함수 (클래스의 기능 )
	int32 step();
	//출력하는 친구 move
	void move(int32 MoveCount);
	void TriggerEventWithProbability(float Probability);
	float Distance(FVector2D second, FVector2D first);
};