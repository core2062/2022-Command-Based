// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/IntakeSubsystem.h"

class IntakeSolenoidCommand
    : public frc2::CommandHelper<frc2::CommandBase, IntakeSolenoidCommand> {
  public:
  /**
   * Creates a new IntakeSolenoidCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit IntakeSolenoidCommand(IntakeSubsystem* subsystem, bool toggled);

  void Execute() override;

  private:
   IntakeSubsystem* m_subsystem;
   bool m_toggled;
};