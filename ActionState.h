// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Generator.h"

/** Set of actions (enums) with the corresponding accessors for each action
 *
 * Example of accessor:
 * Sprinting(bool IsSprinting)
 * Sprinting() const
 */
class FActionState
{
	enum class EActionState : uint8
	{
		Sprinting,
		Crouching,
		Walking,
		Swimming,
		Reloading,

		Aiming,
		AimingWithBow,

		Shooting,
		ShootingWithBow,

		Crawling,
		Blocking,
		ClimbingLedge,
		Hanging,
		Jumping,
		JumpingOfLedge,
		Landing,

		MovingRight,
		MovingLeft,
		MovingForward,
		MovingBackward,

		ControllingCannon,
		ReloadingCannon,

		ControllingShip,
		RepairingShip,
		ControllingVehicle,

		Teleporting,
		Evading,
		Slipping,			// Slipping on the slope
		Hooking,			// Hooking to the wall with the hook
		Rebounding,			// Rebounding (jumping) from the walls

		Reflecting,
		Interacting,
	};
	TSet<EActionState> States;

public:
	ACTIONSTATE(Sprinting)
	ACTIONSTATE(Crouching)
	ACTIONSTATE(Walking)
	ACTIONSTATE(Swimming)
	ACTIONSTATE(Reloading)
	ACTIONSTATE(Aiming)
	ACTIONSTATE(Shooting)
	ACTIONSTATE(ShootingWithBow)
	ACTIONSTATE(Crawling)
	ACTIONSTATE(Blocking)
	ACTIONSTATE(ClimbingLedge)
	ACTIONSTATE(Hanging)
	ACTIONSTATE(Jumping)
	ACTIONSTATE(JumpingOfLedge)
	ACTIONSTATE(Landing)
	ACTIONSTATE(MovingRight)
	ACTIONSTATE(MovingLeft)
	ACTIONSTATE(MovingForward)
	ACTIONSTATE(MovingBackward)
	ACTIONSTATE(Reflecting)
	ACTIONSTATE(ControllingCannon)
	ACTIONSTATE(ControllingShip)
	ACTIONSTATE(Interacting)
private:
	// Add or remove action from States array depending on IsDoing value (true => adding, false => removing)
	void UpdateAction(bool IsDoing, EActionState ActionState)
	{
		IsDoing ? States.Add(ActionState) : static_cast<void>(States.Remove(ActionState));
	}
};
