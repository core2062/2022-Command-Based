#include "commands/LaunchBallCommandGroup.h"

LaunchBallCommandGroup::LaunchBallCommandGroup(ConveyorSubsystem* conveyor) :
                                            launcherFeedDelayTime("Launcher Feed Delay", 1.5),
                                            launcherPunchDelayTime("Launcher Punch Delay", 1.25)
{
    AddCommands(
        ConveyorFeedCommand(conveyor,1),
        ConveyorPunchToggleCommand(conveyor,true),
        WaitCommand(1.25s),
        ConveyorPunchToggleCommand(conveyor,false),
        WaitCommand(1.5s),
        ConveyorFeedCommand(conveyor,0)
    );
}