// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DoubleSolenoid.h>
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
  
  /**
   * Sets the conveyor speed
   * @param direction 1,-1, or 0; Multiplies to the speed to control the conveyor movement
   */
  void SetConveyorSpeed(int direction);
  
  /**
   * Sets the speed of the feed
   * @param direction 1,-1, or 0; Multiplies to the speed to control the conveyor movement
   */
  void SetFeedSpeed(int direction);
  
  void ToggleConveyorPunch();

  COREConstant<double> conveyorForwardSpeed, conveyorReverseSpeed, conveyorFeedSpeed;

 private:
  TalonSRX m_conveyorTalon, m_rightFeed, m_leftFeed;
  DoubleSolenoid m_conveyorPunch;
  bool m_conveyorPiston;
};
