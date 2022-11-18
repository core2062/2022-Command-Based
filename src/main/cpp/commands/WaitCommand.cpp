// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/WaitCommand.h"

WaitCommand::WaitCommand(units::second_t duration)
    : m_duration(duration) {}

void WaitCommand::Initialize() {
  m_timer.Start();
}

void WaitCommand::Execute() {
}

void WaitCommand::End(bool interrupted) {
  m_timer.Stop();
  m_timer.Reset();
}

bool WaitCommand::IsFinished() {
  return m_timer.HasElapsed(m_duration);
}