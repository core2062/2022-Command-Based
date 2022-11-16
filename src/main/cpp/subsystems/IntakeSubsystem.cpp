// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IntakeSubsystem.h"

IntakeSubsystem::IntakeSubsystem() : 
  m_intakeTalon(INTAKE_PORT),
  m_intakeSpeed("Intake Speed", 0.9),
  m_intakeSolenoid(PneumaticsModuleType::REVPH, INTAKE_SOLENOID_IN_PORT, INTAKE_SOLENOID_OUT_PORT)
{
  //Implementation of subsystem constructor goes here.
  m_intakePiston = false;
  m_intakeTalon.SetNeutralMode(NeutralMode::Brake);

}

void IntakeSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void IntakeSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

void IntakeSubsystem::SetIntakeSpeed(double multiplier) {
    m_intakeTalon.Set(ControlMode::PercentOutput, m_intakeSpeed.Get()*multiplier);
}

void IntakeSubsystem::ToggleIntakePiston()
{
    if (m_intakePiston)
    {
        m_intakeSolenoid.Set(DoubleSolenoid::Value::kForward);
    }
    else
    {
        m_intakeSolenoid.Set(DoubleSolenoid::Value::kReverse);
    }
    m_intakePiston = !m_intakePiston;
}