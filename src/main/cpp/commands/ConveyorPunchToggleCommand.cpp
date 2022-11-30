// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ConveyorPunchToggleCommand.h"

ConveyorPunchToggleCommand::ConveyorPunchToggleCommand(ConveyorSubsystem* subsystem, bool punched)
    : m_subsystem{subsystem},
    m_punched{punched}{}

void ConveyorPunchToggleCommand::Execute()
{
    m_subsystem->SetConveyorPunch(m_punched);
}