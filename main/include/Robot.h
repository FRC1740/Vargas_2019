/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <WPILib.h>
#include <string>

#include <SmartDashboard/SendableChooser.h>
#include <TimedRobot.h>

#define DEADBAND 0.2 // Vary as necessary

// Arm Constants
#define DOWN 0.5
#define UP -DOWN
#define OPEN 0.5
#define CLOSE -OPEN

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
  double deadBand(double);
 
 private:
	frc::Spark m_frontLeft{2};
	frc::Spark m_rearLeft{3};
	frc::Spark m_frontRight{0};
	frc::Spark m_rearRight{1};
  frc::Spark m_arm{4};
  frc::Spark m_wrist{5};
  
	frc::MecanumDrive m_drive{m_frontLeft, m_rearLeft, m_frontRight, m_rearRight};
  frc::XboxController m_Xbox{0};
	//frc::Joystick m_ThreeAxisStick{1};

  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
