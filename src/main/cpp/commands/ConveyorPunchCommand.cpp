// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ConveyorPunchCommand.h"

ConveyorPunchCommand::ConveyorPunchCommand(ConveyorSubsystem* subsystem)
    : m_subsystem{subsystem}{}

void ConveyorPunchCommand::Execute()
{
    m_subsystem->ToggleConveyorPunch();
}