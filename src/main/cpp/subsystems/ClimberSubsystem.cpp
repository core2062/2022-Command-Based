// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ClimberSubsystem.h"

ClimberSubsystem::ClimberSubsystem() :
  m_climberTalon(CLIMBER_TALON_PORT),
	m_climberSpeed("Climber Speed", 0.9),
  m_climberSolenoid(PneumaticsModuleType::REVPH, CLIMBER_LOW_PORT, CLIMBER_HIGH_PORT)
{
  // Implementation of subsystem constructor goes here.
  m_climberPin = false;
  m_climberTalon.SetNeutralMode(NeutralMode::Brake);
  // double climberPin = 1;
}

void ClimberSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void ClimberSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

void ClimberSubsystem::SetClimberSpeed(double multiplier) {
  m_climberTalon.Set(ControlMode::PercentOutput,m_climberSpeed.Get()*multiplier);
}

void ClimberSubsystem::ToggleClimberPin(bool toggledPin)
{
if (toggledPin = true)
{
  std::cout << "Pin toggled";
  toggledPin = false;
}else if (toggledPin = false)
{
  std::cout << "Pin toggled";
  toggledPin = true;
}else 
{
  std::cout << "Pin not toggled";
}

  /*
  if (toggledPin = true)
  {
    m_climberSolenoid.Set(DoubleSolenoid::Value::kForward);
  }
  else if (toggledPin = false)
  {
    m_climberSolenoid.Set(DoubleSolenoid::Value::kReverse);
  }
  // m_climberPin = !m_climberPin;
*/
}