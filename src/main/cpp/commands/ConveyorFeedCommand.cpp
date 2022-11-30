// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ConveyorFeedCommand.h"

ConveyorFeedCommand::ConveyorFeedCommand(ConveyorSubsystem* subsystem, int feedDirection)
    : m_subsystem{subsystem},
    m_feedDirection{feedDirection} {}

void ConveyorFeedCommand::Execute()
{
    m_subsystem->SetFeedSpeed(m_feedDirection);
}