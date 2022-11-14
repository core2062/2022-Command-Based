// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() :  
	m_leftPrimary(LEFT_FRONT_PORT),
	m_leftSecondary(LEFT_BACK_PORT),
	m_rightPrimary(RIGHT_FRONT_PORT),
	m_rightSecondary(RIGHT_BACK_PORT),
	m_etherAValue("Ether A Value", .6),
	m_etherBValue("Ether B Value", .4),
	m_etherQuickTurnValue("Ether Quick Turn Value", 1.0),
	m_ticksPerInch("Ticks Per Inch", (4 * 3.1415) / 1024),
	m_driveSpeedModifier("Drive speed Modifier", 1)
{
	// Implementation of subsystem constructor goes here.
	m_compressor.EnableDigital();
	COREEtherDrive::SetAB(m_etherAValue.Get(), m_etherBValue.Get());
	COREEtherDrive::SetQuickturn(m_etherQuickTurnValue.Get());
}

void DriveSubsystem::Periodic() {
 	// Implementation of subsystem periodic method goes here.
	SmartDashboard::PutNumber("Left side encoder", m_leftPrimary.GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("Right side encoder", m_rightPrimary.GetSelectedSensorPosition(0));
	SmartDashboard::PutNumber("Robot Heading", ahrs.GetFusedHeading());
}

void DriveSubsystem::SimulationPeriodic() {
	// Implementation of subsystem simulation periodic method goes here.
}

void DriveSubsystem::CalculateMotorSpeeds(double mag, double rot) {
	VelocityPair speeds = COREEtherDrive::Calculate(mag, rot, .1);
	SetMotorSpeed(speeds.left, speeds.right);
}

void DriveSubsystem::SetMotorSpeed(double leftPercent, double rightPercent) {
	// Sets speed based on percent output desired
	SetMotorSpeed(leftPercent* m_driveSpeedModifier.Get(), DriveSide::LEFT);
	SetMotorSpeed(rightPercent* m_driveSpeedModifier.Get(), DriveSide::RIGHT);
}

void DriveSubsystem::SetMotorSpeed(double speedInFraction, DriveSide whichSide) {
	// Sets motor speed based on drive side and desired speed
	if (whichSide == DriveSide::BOTH || whichSide == DriveSide::RIGHT) {
		m_rightPrimary.Set(ControlMode::PercentOutput, speedInFraction);
		m_rightSecondary.Set(ControlMode::PercentOutput, speedInFraction);
	}
	if (whichSide == DriveSide::BOTH || whichSide == DriveSide::LEFT) {
		m_leftPrimary.Set(ControlMode::PercentOutput, speedInFraction);
		m_leftSecondary.Set(ControlMode::PercentOutput, speedInFraction);
	}
}

double DriveSubsystem::GetRobotPosition() {
	return m_rightPrimary.GetSelectedSensorPosition(0);
}

void DriveSubsystem::InitTalons() {
	// Sets up talons
	m_leftPrimary.Set(ControlMode::PercentOutput, 0);
	m_leftSecondary.Set(ControlMode::PercentOutput, 0);
	m_rightPrimary.Set(ControlMode::PercentOutput, 0);
	m_rightSecondary.Set(ControlMode::PercentOutput, 0);

	// Encoder Functions
	m_leftPrimary.SetStatusFramePeriod(StatusFrameEnhanced::Status_1_General, 10, 0);
	m_rightPrimary.SetStatusFramePeriod(StatusFrameEnhanced::Status_1_General, 10, 0);

	m_leftPrimary.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::IntegratedSensor, 0, 0);
	m_rightPrimary.ConfigSelectedFeedbackSensor(ctre::phoenix::motorcontrol::FeedbackDevice::IntegratedSensor, 0, 0);
	
	SetTalonMode(NeutralMode::Coast);

	m_leftPrimary.SetSensorPhase(false);
	m_rightPrimary.SetSensorPhase(false);

	// Motor Inversion
	m_leftPrimary.SetInverted(false);
	m_leftSecondary.SetInverted(false);
	m_rightPrimary.SetInverted(true);
	m_rightSecondary.SetInverted(true);
 
	SetTalonMode(NeutralMode::Coast);
}

void DriveSubsystem::SetTalonMode(NeutralMode mode){
	m_leftPrimary.SetNeutralMode(mode);
	m_leftSecondary.SetNeutralMode(mode);
	m_rightPrimary.SetNeutralMode(mode);
	m_rightSecondary.SetNeutralMode(mode);
}
