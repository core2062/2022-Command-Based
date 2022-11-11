// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveSubsystem.h"

class TeleopEtherDrive
    : public frc2::CommandHelper<frc2::CommandBase, TeleopEtherDrive> {
 public:
  TeleopEtherDrive(DriveSubsystem* subsystem,
                    std::function<double()> xaxisSpeedSupplier,
                    std::function<double()> zaxisRotateSupplier);
  void Execute() override;

 private:
  DriveSubsystem* m_drive;
  std::function<double()> m_xaxisSpeedSupplier;
  std::function<double()> m_zaxisRotateSupplier;
};
