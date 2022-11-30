// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() : 
  m_driverDPadN(&m_driveController,0,0),
  m_driverDPadS(&m_driveController,180,0),
  m_driverYButton(&m_driveController,4),
  m_operatorAButton(&m_operatorController,1),
  m_operatorBButton(&m_operatorController,2), // idk if this is B or not may have to change eventually
  m_operatorRightButton(&m_operatorController,6),
  m_operatorRightTrigger(&m_operatorController,25),
  m_operatorLeftTrigger(&m_operatorController,24),
  m_autonomousCommand(&m_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  m_driveSubsystem.SetDefaultCommand(TeleopEtherDrive(&m_driveSubsystem, 
                                                      [this] {return -m_driveController.GetRawAxis(1); },
                                                      [this] {return m_driveController.GetRawAxis(2); }));

  m_driverDPadN.WhenHeld(new ClimbMotorCommand(&m_climberSubsystem,1));
  m_driverDPadS.WhenHeld(new ClimbMotorCommand(&m_climberSubsystem,-1));
  m_driverYButton.WhenPressed(new ClimbSolenoidCommand(&m_climberSubsystem));

  m_operatorAButton.WhenPressed(new IntakeSolenoidCommand(&m_intakeSubsystem));
  m_operatorBButton.WhenPressed(new LaunchBallCommandGroup(&m_conveyorSubsystem));
  m_operatorRightButton.WhenPressed(new IntakeMotorCommand(&m_intakeSubsystem, -1));
  m_operatorRightTrigger.WhenPressed(new IntakeMotorCommand(&m_intakeSubsystem, 1));
  m_operatorLeftTrigger.WhenPressed(new LauncherCommand(&m_launcherSubsystem, 1));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_autonomousCommand;
}
