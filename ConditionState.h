// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#ifndef CONDITIONSTATE
#define CONDITIONSTATE(condition_name) \
void condition_name(bool Is##condition_name) { UpdateCondition(Is##condition_name, EConditionState::##condition_name); } \
bool condition_name() const { return States.Contains(EConditionState::##condition_name); }
#endif

/** Set of states (enums) with the corresponding accessors for each state
 *
 * Example of accessor:
 * IsNearLadder(bool IsNearLadder)
 * IsNearLadder() const
 */
class FConditionState
{
	enum class EConditionState : uint8
	{
		IsNearLadder,
		IsOnLadder,
		CanMoveLeft,
		CanMoveRight,
		CanJumpLeft,
		CanJumpRight,
		CanTurnLeft,
		CanTurnRight,
		CanJumpUp,
		InFirstPerson,
		InThirdPerson,

		InHelmZone,

		CanWallRun,
	};
	TSet<EConditionState> States;

public:
	CONDITIONSTATE(IsNearLadder)
	CONDITIONSTATE(IsOnLadder)
	CONDITIONSTATE(CanMoveLeft)
	CONDITIONSTATE(CanMoveRight)
	CONDITIONSTATE(CanJumpLeft)
	CONDITIONSTATE(CanJumpRight)
	CONDITIONSTATE(CanTurnLeft)
	CONDITIONSTATE(CanTurnRight)
	CONDITIONSTATE(CanJumpUp)
	CONDITIONSTATE(InFirstPerson)
	CONDITIONSTATE(InThirdPerson)
	CONDITIONSTATE(InHelmZone)
	CONDITIONSTATE(CanWallRun)
private:
	// Add or remove condition from States array depending on IsConditionMet value (true => adding, false => removing)
	void UpdateCondition(bool IsConditionMet, EConditionState ConditionState)
	{
		IsConditionMet ? States.Add(ConditionState) : static_cast<void>(States.Remove(ConditionState));
	}
};
