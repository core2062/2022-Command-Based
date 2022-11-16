// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IntakeMotorCommand.h"

IntakeMotorCommand::IntakeMotorCommand(IntakeSubsystem* subsystem, int intakeDirection)
    : m_subsystem{subsystem},
    m_intakeDirection{intakeDirection} {}

void IntakeMotorCommand::Execute()
{
    m_subsystem->SetIntakeSpeed(m_intakeDirection);
}

void IntakeMotorCommand::End(bool interupted)
{
    m_subsystem->SetIntakeSpeed(0);
}