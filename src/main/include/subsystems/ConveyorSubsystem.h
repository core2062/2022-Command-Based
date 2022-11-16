// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <CORERobotLib.h>

#include "Constants.h"

using namespace frc;

class ConveyorSubsystem : public frc2::SubsystemBase {
 public:
  ConveyorSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

  void SetConveyorSpeed(int direction);

  COREConstant<double> conveyorForwardSpeed,conveyorReverseSpeed;

 private:
  TalonSRX m_conveyorTalon;  
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
