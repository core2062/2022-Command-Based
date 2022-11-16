// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/IntakeSubsystem.h"

/**
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class IntakeMotorCommand
    : public frc2::CommandHelper<frc2::CommandBase, IntakeMotorCommand> {
  public:
  /**
   * Creates a new IntakeMotorCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit IntakeMotorCommand(IntakeSubsystem* subsystem,
                               int intakeDirection);

  void Execute() override;
  void End(bool interrupted) override;

 private:
  IntakeSubsystem* m_subsystem;
  int m_intakeDirection;
};