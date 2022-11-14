// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/POVButton.h>

#include "commands/ExampleCommand.h"
#include "commands/TeleopEtherDrive.h"
#include "commands/ClimbMotorCommand.h"
#include "commands/ClimbSolenoidCommand.h"

#include "subsystems/ExampleSubsystem.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/ClimberSubsystem.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // Joysticks
  frc::Joystick m_driveController{0};
  frc::Joystick m_operatorController{1};
  // Joystick Buttons in use
  frc2::POVButton m_driverDPadN,m_driverDPadS;
  frc2::JoystickButton m_driverYButton;

  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  DriveSubsystem m_driveSubsystem;
  ClimberSubsystem m_climberSubsystem;

  ExampleCommand m_autonomousCommand;

  void ConfigureButtonBindings();
};
