// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Compressor.h>
#include <frc/Preferences.h>
#include <ctre/Phoenix.h>
#include <CORERobotLib.h>
#include <COREUtilities/COREConstant.h>
#include <COREDrive/COREEtherDrive.h>
#include <AHRS.h>

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
  
	void CalculateMotorSpeeds(double mag, double rot);
	void SetMotorSpeed(double speedInFraction, DriveSide whichSide);
	void SetMotorSpeed(double leftPercent, double rightPercent);
  double GetRobotPosition();
	void InitTalons();
	void SetTalonMode(NeutralMode mode);

	AHRS ahrs{SPI::Port::kMXP};

 private:
  TalonFX m_leftPrimary{1}, m_leftSecondary{2}, m_rightPrimary{3}, m_rightSecondary{4};

  COREConstant<double> m_etherAValue, m_etherBValue, m_etherQuickTurnValue, m_ticksPerInch, m_driveSpeedModifier;

  Compressor m_compressor{frc::PneumaticsModuleType::REVPH};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
