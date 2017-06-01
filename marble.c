#pragma config(Sensor, in1,    color,          sensorLineFollower)
#pragma config(Sensor, in2,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, in3,    lightSensor,    sensorReflection)
#pragma config(Sensor, dgtl1,  limitSwitch,    sensorTouch)
#pragma config(Sensor, dgtl2,  bumpSwitch,     sensorTouch)
#pragma config(Sensor, dgtl3,  quad,           sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  sonar,          sensorSONAR_cm)
#pragma config(Sensor, dgtl12, green,          sensorLEDtoVCC)
#pragma config(Motor,  port2,           front,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           back,          tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           servoMotor,    tmotorServoStandard, openLoop)
#pragma config(Motor,  port10,          flashlight,    tmotorVexFlashlight, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


task main()
{
turnFlashlightOn(flashlight, 127);
setServo(servoMotor, 0);
int count = 0;
while(count<15){
	startMotor(front, 20);
	wait(1);
	stopMotor(front);
	if(SensorValue[color]<1600){
		setServo(servoMotor, 45);
	}
	if(SensorValue[color]>2800){
		setServo(servoMotor, -45);
	}
	wait(3);
	startMotor(back, -20);
	wait(5);
	stopMotor(back);
	setServo(servoMotor, 0);

	count++;
	}
}
