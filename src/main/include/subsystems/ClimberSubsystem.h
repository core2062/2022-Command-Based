// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include <CORERobotLib.h>

#include "Constants.h"

using namespace CORE;
using namespace frc;

class ClimberSubsystem : public frc2::SubsystemBase {
public:
  ClimberSubsystem();

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
   * Sets the speed of the climber Talon to COREConstant m_climberSpeed*imput
   * @param multiplier Value being multiplied by m_climberSpeed; Recommend just passing in +/- 1
   */
  void SetClimberSpeed(double multiplier);

  /**
   * Toggles the climber's punch using m_climberPin
   */
  void ToggleClimberPin(bool toggledPin);

private:
  TalonSRX m_climberTalon;
  COREConstant<double> m_climberSpeed;
  DoubleSolenoid m_climberSolenoid;
  bool m_climberPin;
  
};
