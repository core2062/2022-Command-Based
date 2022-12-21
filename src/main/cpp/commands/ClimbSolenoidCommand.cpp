// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ClimbSolenoidCommand.h"

ClimbSolenoidCommand::ClimbSolenoidCommand(ClimberSubsystem* subsystem, bool toggledPin)
    : m_subsystem{subsystem},
    m_toggledPin{toggledPin} {}

void ClimbSolenoidCommand::Execute()
{
    m_subsystem->ToggleClimberPin(m_toggledPin);
}