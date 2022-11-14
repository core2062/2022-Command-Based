// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TeleopEtherDrive.h"

#include "subsystems/DriveSubsystem.h"

TeleopEtherDrive::TeleopEtherDrive(
    DriveSubsystem* subsystem, std::function<double()> xAxisSpeedSupplier,
    std::function<double()> yAxisRotateSuppplier)
    : m_drive{subsystem},
      m_xAxisSpeedSupplier{xAxisSpeedSupplier},
      m_yAxisRotateSupplier{yAxisRotateSuppplier} {
  AddRequirements({subsystem});
}

void TeleopEtherDrive::Execute() {
  m_drive->CalculateMotorSpeeds(m_xAxisSpeedSupplier(), m_yAxisRotateSupplier());
}
