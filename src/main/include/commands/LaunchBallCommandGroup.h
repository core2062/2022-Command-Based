#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "subsystems/ConveyorSubsystem.h"

#include "ConveyorPunchToggleCommand.h"
#include "ConveyorFeedCommand.h"
#include "WaitCommand.h"

/**
 * First fires the punch & runs the feed; La
 */
class LaunchBallCommandGroup
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, LaunchBallCommandGroup> {
 public:
    /**
     * Creates Command group
     * 
     * @param conveyor The conveyor subsystem
     */
    LaunchBallCommandGroup(ConveyorSubsystem* conveyor);

    COREConstant<double> launcherFeedDelayTime, launcherPunchDelayTime;
};