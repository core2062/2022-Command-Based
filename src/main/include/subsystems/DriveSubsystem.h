// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Compressor.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <ctre/Phoenix.h>

using namespace frc;

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

 private:
  TalonFX m_rightPrimary, m_rightSecondary, m_leftPrimary, m_leftSecondary;

  MotorControllerGroup m_right, m_left;
  DifferentialDrive m_drive;

  Compressor m_compressor;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
