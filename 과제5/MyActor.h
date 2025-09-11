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
	//��ɱ����� �ʿ��� ��� ���� ( Ŭ������ �Ӽ� )
	FVector2D PreviousLocation; //���� ��ġ
	FVector2D CurrentLocation; // ���� ��ġ�� ��� ��ǥ

	float TotalDistance;
	int32 TotalEventCount;
	//��� ������ �ʿ��� ��� �Լ� (Ŭ������ ��� )
	int32 step();
	//����ϴ� ģ�� move
	void move(int32 MoveCount);
	void TriggerEventWithProbability(float Probability);
	float Distance(FVector2D second, FVector2D first);
};