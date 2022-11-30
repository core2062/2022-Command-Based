// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ConveyorSubsystem.h"

class ConveyorPunchToggleCommand
    : public frc2::CommandHelper<frc2::CommandBase, ConveyorPunchToggleCommand> {
  public:
  /**
   * Creates a new ConveyorPunchToggleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit ConveyorPunchToggleCommand(ConveyorSubsystem* subsystem, bool punched);

  void Execute() override;

  private:
   ConveyorSubsystem* m_subsystem;
   bool m_punched;
};