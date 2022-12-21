// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/LauncherSubsystem.h"

/**
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class LauncherCommand
    : public frc2::CommandHelper<frc2::CommandBase, LauncherCommand> {
 public:
  /**
   * Creates a new LauncherCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit LauncherCommand(LauncherSubsystem* subsystem,
                            double launcherDirection);

  void Execute() override;
  void End(bool interrupted) override;

 private:
  LauncherSubsystem* m_subsystem;
  int m_launcherDirection;
};
