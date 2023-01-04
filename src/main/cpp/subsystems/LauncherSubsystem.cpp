// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LauncherSubsystem.h"

LauncherSubsystem::LauncherSubsystem() :
  m_launcherLeftTalon(LEFT_LAUNCHER),
  m_launcherRightTalon(RIGHT_LAUNCHER),
	m_launcherSpeed("Climber Speed", 0.9)
{
  // Implementation of subsystem constructor goes here.
  m_launcherLeftTalon.SetNeutralMode(NeutralMode::Brake);
  m_launcherRightTalon.SetNeutralMode(NeutralMode::Brake);
  
}

void LauncherSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void LauncherSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

void LauncherSubsystem::SetLauncherSpeed(double multiplier) {
  m_launcherLeftTalon.Set(ControlMode::PercentOutput,-m_launcherSpeed.Get()*multiplier);
  m_launcherRightTalon.Set(ControlMode::PercentOutput,m_launcherSpeed.Get()*multiplier);
}