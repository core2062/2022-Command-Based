// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ConveyorSubsystem.h"

class ConveyorFeedCommand
    : public frc2::CommandHelper<frc2::CommandBase, ConveyorFeedCommand> {
 public:
  /**
   * Creates a new ConveyorFeedCommand.
   *
   * @param subsystem The subsystem used by this command.
   * 
   * @param feedDirection direction to feed
   */
  explicit ConveyorFeedCommand(ConveyorSubsystem* subsystem, double feedDirection);

  void Execute() override;

 private:
  ConveyorSubsystem* m_subsystem;
  int m_feedDirection;
};