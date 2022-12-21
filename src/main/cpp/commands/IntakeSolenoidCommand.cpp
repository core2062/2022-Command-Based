// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IntakeSolenoidCommand.h"

IntakeSolenoidCommand::IntakeSolenoidCommand(IntakeSubsystem* subsystem, bool toggled)
    : m_subsystem{subsystem}, 
    m_toggled{toggled} {}

void IntakeSolenoidCommand::Execute()
{
    m_subsystem->IntakePiston(m_toggled);
}