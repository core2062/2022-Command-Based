// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TeleopEtherDrive.h"

#include "subsystems/DriveSubsystem.h"

TeleopEtherDrive::TeleopEtherDrive(
    DriveSubsystem* subsystem, std::function<double()> xaxisSpeedSupplier,
    std::function<double()> zaxisRotateSuppplier)
    : m_drive{subsystem},
      m_xaxisSpeedSupplier{xaxisSpeedSupplier},
      m_zaxisRotateSupplier{zaxisRotateSuppplier} {
  AddRequirements({subsystem});
}

void TeleopEtherDrive::Execute() {
  m_drive->CalculateMotorSpeeds(m_xaxisSpeedSupplier(), m_zaxisRotateSupplier());
}
