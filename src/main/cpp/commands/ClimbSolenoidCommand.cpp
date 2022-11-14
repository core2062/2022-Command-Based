// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ClimbSolenoidCommand.h"

ClimbSolenoidCommand::ClimbSolenoidCommand(ClimberSubsystem* subsystem)
    : m_subsystem{subsystem} {}

void ClimbSolenoidCommand::Execute()
{
    m_subsystem->ToggleClimberPin();
}