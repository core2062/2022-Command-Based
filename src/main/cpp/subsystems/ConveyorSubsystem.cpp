// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ConveyorSubsystem.h"

ConveyorSubsystem::ConveyorSubsystem() :
  conveyorForwardSpeed("Conveyor Forward Speed", -0.7),
  conveyorReverseSpeed("Conveyor Reverse Speed", 0.7),                                       
  m_conveyorTalon(CONVEYOR_PORT)
 {
  // Implementation of subsystem constructor goes here.
}

void ConveyorSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void ConveyorSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

void ConveyorSubsystem::SetConveyorSpeed(int direction)
{

}
