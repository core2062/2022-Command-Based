// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ConveyorLowCommand.h"

ConveyorLowCommand::ConveyorLowCommand(ConveyorSubsystem* subsystem, double conveyorDirection)
    : m_subsystem{subsystem},
    m_conveyorDirection{conveyorDirection} {}

void ConveyorLowCommand::Execute()
{
    m_subsystem->SetConveyorSpeed(m_conveyorDirection);
}

void ConveyorLowCommand::End(bool interupted)
{
    m_subsystem->SetConveyorSpeed(0);
}