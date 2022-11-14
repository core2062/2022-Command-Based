// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

/* Drive ports */
#define RIGHT_FRONT_PORT 1
#define RIGHT_BACK_PORT 2
#define LEFT_FRONT_PORT 3
#define LEFT_BACK_PORT 4

/* Intake Ports */
#define INTAKE_PORT 5

/* Conveyor ports */
#define CONVEYOR_PORT 6

/* Launcher */
#define RIGHT_FEED 7
#define LEFT_FEED 8
#define RIGHT_LAUNCHER 9
#define LEFT_LAUNCHER 10

/* Climber */
#define CLIMBER_TALON_PORT 11

/* Solenoids */
#define COMPRESSOR_PCM 2
#define CLIMBER_PCM 2
#define LAUNCHER_SOLENOID_IN_PORT 10
#define LAUNCHER_SOLENOID_OUT_PORT 11
#define CLIMBER_LOW_PORT 6
#define CLIMBER_HIGH_PORT 7
#define INTAKE_SOLENOID_IN_PORT 12
#define INTAKE_SOLENOID_OUT_PORT 13
