// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() :  m_rightPrimary(0),
                                    m_rightSecondary(1),
                                    m_leftPrimary(2),
                                    m_leftSecondary(3),
                                    m_right(&m_rightPrimary,&m_rightSecondary),
                                    m_left(),
                                    m_drive(),
                                    m_compressor(frc::PneumaticsModuleType::REVPH)
{
  // Implementation of subsystem constructor goes here.
}

void DriveSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void DriveSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
