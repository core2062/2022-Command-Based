// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ConveyorSubsystem.h"

class ConveyorPunchCommand
    : public frc2::CommandHelper<frc2::CommandBase, ConveyorPunchCommand> {
  public:
  /**
   * Creates a new ConveyorPunchCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit ConveyorPunchCommand(ConveyorSubsystem* subsystem);

  void Execute() override;

  private:
   ConveyorSubsystem* m_subsystem;
};