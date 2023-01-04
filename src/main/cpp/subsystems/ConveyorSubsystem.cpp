// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ConveyorSubsystem.h"

ConveyorSubsystem::ConveyorSubsystem() :
  conveyorForwardSpeed("Conveyor Forward Speed", -0.7),
  conveyorReverseSpeed("Conveyor Reverse Speed", 0.7),
  conveyorFeedSpeed("Conveyor Feed Delay", 0.2),
  m_conveyorTalon(CONVEYOR_PORT),
  m_rightFeed(RIGHT_FEED),
  m_leftFeed(LEFT_FEED),
  m_conveyorPunch(frc::PneumaticsModuleType::REVPH,LAUNCHER_SOLENOID_IN_PORT,LAUNCHER_SOLENOID_OUT_PORT)
{
  m_conveyorPunch.Set(DoubleSolenoid::Value::kForward);
  // Implementation of subsystem constructor goes here.
  double conveyerPiston = 1;
}

void ConveyorSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void ConveyorSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

void ConveyorSubsystem::SetConveyorSpeed(double direction)
{
  if (direction == 1)
  {
    m_conveyorTalon.Set(ControlMode::PercentOutput,conveyorForwardSpeed.Get());
  } else if (direction == -1)
  {
    m_conveyorTalon.Set(ControlMode::PercentOutput,conveyorReverseSpeed.Get());
  } else
  {
    m_conveyorTalon.Set(ControlMode::PercentOutput,0);
  }
}

void ConveyorSubsystem::SetFeedSpeed(double direction) {
  if (direction == 1)
  {
    m_leftFeed.Set(ControlMode::PercentOutput, conveyorFeedSpeed.Get());
    m_rightFeed.Set(ControlMode::PercentOutput, -conveyorForwardSpeed.Get());
  } else if (direction == -1)
  {
    m_leftFeed.Set(ControlMode::PercentOutput, -conveyorForwardSpeed.Get());
    m_rightFeed.Set(ControlMode::PercentOutput, conveyorForwardSpeed.Get());
  } else
  {
    m_leftFeed.Set(ControlMode::PercentOutput, 0);
    m_rightFeed.Set(ControlMode::PercentOutput, 0);
  }
}

void ConveyorSubsystem::ToggleConveyorPunch()
{
  ///*
    if (m_conveyorPiston)
    {
        m_conveyorPunch.Set(DoubleSolenoid::Value::kForward);
    }
    else
    {
        m_conveyorPunch.Set(DoubleSolenoid::Value::kReverse);
    }
    m_conveyorPiston = !m_conveyorPiston;
    //*/

    /*
     if (conveyerPiston != 1)
    {
        m_conveyorPunch.Set(DoubleSolenoid::Value::kForward);
        conveyerPiston = 1;
    }
    else
    {
        m_conveyorPunch.Set(DoubleSolenoid::Value::kReverse);
        conveyerPiston = 2;
    }
    m_conveyorPiston = !m_conveyorPiston;
    */
}

void ConveyorSubsystem::SetConveyorPunch(bool punched)
{
  if(punched)
    m_conveyorPunch.Set(DoubleSolenoid::Value::kForward);
  else
    m_conveyorPunch.Set(DoubleSolenoid::Value::kReverse);
  
  m_conveyorPiston = punched;
}