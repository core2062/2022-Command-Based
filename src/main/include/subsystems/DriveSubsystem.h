// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Compressor.h>
#include <ctre/Phoenix.h>
#include <CORERobotLib.h>
#include <COREUtilities/COREConstant.h>
#include <COREDrive/COREEtherDrive.h>
#include <AHRS.h>

#include "Constants.h"

using namespace CORE;
using namespace frc;

enum class DriveSide{LEFT = 1, RIGHT = 2, BOTH = 3};

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;
  
  /**
   * Uses args to calculate motor speeds with Ether drive
   * @param mag Y Axis
   * @param rot X Axis
   */
	void CalculateMotorSpeeds(double mag, double rot);

  /**
   * Primarily used to take in the calculated values from Ether drive to call SetMotorSpeed(double speedInFraction, DriveSide whichSide)
   */
	void SetMotorSpeed(double leftPercent, double rightPercent);

  /**
   * Sets the speed of the motors
   */
	void SetMotorSpeed(double speedInFraction, DriveSide whichSide);
  
  /**
   * Returns the encoder value of the m_rightPrimary Talon
   */
  double GetRobotPosition();

	void InitTalons();

  /**
   * Used to toggle between Coast and Brake mode of the Talons
   */
	void SetTalonMode(NeutralMode mode);

	AHRS ahrs{SPI::Port::kMXP};

 private:
  TalonFX m_leftPrimary, m_leftSecondary, m_rightPrimary, m_rightSecondary;

  COREConstant<double> m_etherAValue, m_etherBValue, m_etherQuickTurnValue, m_ticksPerInch, m_driveSpeedModifier;

  Compressor m_compressor{frc::PneumaticsModuleType::REVPH};
};
