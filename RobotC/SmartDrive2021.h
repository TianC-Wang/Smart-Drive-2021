#pragma config(Motor, motor1, lMotor, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor, motor6, rMotor, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Sensor, port2, rSonar, sensorVexIQ_Distance)
#pragma config(Sensor, port3, fSonar, sensorVexIQ_Distance)

//Drivetrain
void arcade(short _LSpeed, short _RSpeed);
void arcade(short _Speed);
void arcade(void);
void arcadeForMsec(short _LSpeed, short _RSpeed, long _MilliSec);
void arcadeForMsec(short _Speed, long _MilliSec);
void arcadeForEnco(short _LSpeed, short _RSpeed, long _Encoder);
void arcadeForEnco(short _Speed, long _Encoder);

void arcade(short _LSpeed, short _RSpeed) {
	setMotorSpeed(lMotor, _LSpeed);
	setMotorSpeed(rMotor, _RSpeed);}

void arcade(short _Speed) {
	arcade(_Speed, _Speed);}

void arcade(void) {
	arcade(0);}

void arcadeForMsec(short _LSpeed, short _RSpeed, long _MilliSec) {
	long localtimer = 0;
	while(localtimer < _MilliSec) {
		arcade(_LSpeed, _RSpeed);
		wait1Msec(1);
		localtimer++;}}

void arcadeForMsec(short _Speed, long _MilliSec) {
	arcadeForMsec(_Speed, _Speed, _MilliSec);}

void arcadeForEnco(short _LSpeed, short _RSpeed, long _Encoder) {
	long len = getMotorEncoder(lMotor);
	long ren = getMotorEncoder(rMotor);
	while((abs(len-getMotorEncoder(lMotor))+abs(ren-getMotorEncoder(rMotor)))/2 < _Encoder)
		arcade(_LSpeed, _RSpeed);}

void arcadeForEnco(short _Speed, long _Encoder) {
	arcadeForEnco(_Speed, _Speed, _Encoder);}
