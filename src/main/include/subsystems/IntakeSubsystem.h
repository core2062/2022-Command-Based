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

class IntakeSubsystem : public frc2::SubsystemBase {
public:
    IntakeSubsystem();

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
   * Sets the speed of the intake Talon to COREConstant m_intakeSpeed*imput
   * * @param multiplier Value being multiplied by m_intakeSpeed; Recommend just passing in +/- 1
   */
    void SetIntakeSpeed(double multiplier);

    /**
     * Toggles the intake using m_intakePiston
     */
    void ToggleIntakePiston();

private:
    TalonSRX m_intakeTalon;
    COREConstant<double> m_intakeSpeed;
    DoubleSolenoid m_intakeSolenoid;
    bool m_intakePiston;
};
