// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/LauncherCommand.h"

LauncherCommand::LauncherCommand(LauncherSubsystem* subsystem, int launcherDirection)
    : m_subsystem{subsystem},
    m_launcherDirection{launcherDirection} {}

void LauncherCommand::Execute()
{
    m_subsystem->SetLauncherSpeed(m_launcherDirection);
}

void LauncherCommand::End(bool interupted)
{
    m_subsystem->SetLauncherSpeed(0);
}