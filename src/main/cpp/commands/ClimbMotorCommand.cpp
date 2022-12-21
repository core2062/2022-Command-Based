// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ClimbMotorCommand.h"

ClimbMotorCommand::ClimbMotorCommand(ClimberSubsystem* subsystem, double climberDirection)
    : m_subsystem{subsystem},
    m_climberDirection{climberDirection} {}

void ClimbMotorCommand::Execute()
{
    m_subsystem->SetClimberSpeed(m_climberDirection);
}

void ClimbMotorCommand::End(bool interupted)
{
    m_subsystem->SetClimberSpeed(0);
}