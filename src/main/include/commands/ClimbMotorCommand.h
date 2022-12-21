// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ClimberSubsystem.h"

/**
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ClimbMotorCommand
    : public frc2::CommandHelper<frc2::CommandBase, ClimbMotorCommand> {
 public:
  /**
   * Creates a new ClimbMotorCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit ClimbMotorCommand(ClimberSubsystem* subsystem,
                            double climberDirection);

  void Execute() override;
  void End(bool interrupted) override;

 private:
  ClimberSubsystem* m_subsystem;
  int m_climberDirection;
};
