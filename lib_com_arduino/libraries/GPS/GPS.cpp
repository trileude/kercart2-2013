/*
 * GPS.cpp
 *
 *  Created on: May 3, 2013
 *      Author: Yasser
 */

#include "GPS.h"
GPS::GPS(int address = 0x68) :
		a_address(address) {
	a_time = 0;
	a_date = 0;
	a_heading = 0;
	a_speed = 0;
	a_latitude = 0;
	a_longitude = 0;
}


void GPS::begin() {
	Wire.begin();
	Serial.begin(9600);
}
void GPS::retrieveTime() {
	output = (this->getDouble(0)*10);
	output += (this->getDouble(2)*10);
	output += (this->getDouble(4));
	a_time = output.toInt();
}
void GPS::retrieveDate() {
	output = (this->getDouble(6)*10);
	output += (this->getDouble(8)*10);
	output += (this->getDouble(10));
	output += (this->getDouble(12));
	a_date = output.toInt();
}
void GPS::retrieveHeading() {
	output = (this->getDouble(44));
	output += (this->getSingle(46));
	output += (this->getSingle(47));
	a_heading = output.toInt();
}
void GPS::retrieveSpeed() {
	output = (this->getDouble(52));
	output += (this->getSingle(54));
	output += (this->getSingle(55));
	a_speed = output.toInt();
}
void GPS::retrieveLatitude() {
	a_latitude = this->getSingle(14)  << 8;
	a_latitude += this->getSingle(15) << 7;
	a_latitude += this->getSingle(16) << 6;
	a_latitude += this->getSingle(17) << 5;
	a_latitude += this->getSingle(18) << 4;
	a_latitude += this->getSingle(19) << 3;
	a_latitude += this->getSingle(20) << 2;
	a_latitude += this->getSingle(21) << 1;
	a_latitude += this->getLetter(22);
}
void GPS::retrieveLongtitude() {

	a_longitude = this->getSingle(23)  << 9;
	a_longitude += this->getSingle(24) << 8;
	a_longitude += this->getSingle(25) << 7;
	a_longitude += this->getSingle(26) << 6;
	a_longitude += this->getSingle(27) << 5;
	a_longitude += this->getSingle(28) << 4;
	a_longitude += this->getSingle(29) << 3;
	a_longitude += this->getSingle(30) << 2;
	a_longitude += this->getSingle(31) << 1;
	a_longitude += this->getLetter(32);
	

}
int GPS::getLetter(int address){
	char temp =  this->getSingle(address);
	if(temp == 'N') {
		a_longitude += 0;
	}
	else if( temp == 'S') {
		a_longitude += 1;
		}
	else if( temp == 'E') {
		a_longitude += 2;
		}
	else if( temp == 'W'){
		a_longitude += 3;
		}
	else {
		a_longitude += 4;
		}
}
void GPS::retrieveLatLong() {
	this->retrieveLatitude();
	this->retrieveLongtitude();
}
void GPS::retrieveAllatOnce() {
	this->retrieveTime();
	this->retrieveDate();
	this->retrieveHeading();
	this->retrieveSpeed();
	this->retrieveLatitude();
	this->retrieveLongtitude();
}
	int GPS::getDouble(int address) {
	int Value = 0;
	byte  H_Byte = 0;
	byte  L_Byte = 0;
	Wire.beginTransmission(a_address);
	Wire.write(address);
	Wire.endTransmission();

	Wire.requestFrom(a_address, 2);
	while (Wire.available() < 2)
		;
	H_Byte = Wire.read();
	L_Byte = Wire.read();

	Value = (H_Byte * 10) + L_Byte;

	return Value;
}

	int GPS::getSingle(int address) {
	int Value = 0;
	Wire.beginTransmission(a_address);
	Wire.write(address);
	Wire.endTransmission();
	Wire.requestFrom(a_address, 1);
	while (Wire.available() < 1)
		;
	Value = Wire.read();
	return Value;
}

void GPS::send(int choice) {
	switch(choice)
	{
	case 0 :
		Serial.print(a_time, DEC);
		break;
	case 1 :
		Serial.print(a_date, DEC);
		break;
	case 2 :
		Serial.print(a_speed, DEC);
		break;
	case 3 : 
		Serial.print(a_heading, DEC);
		break;
	case 4: 
		Serial.print(a_latitude, DEC);
		break;
	case 5:
		Serial.print(a_longitude, DEC);
		break;
	}
}

void GPS::sendAll() {
		Serial.println("Time");
		Serial.println(a_time, DEC);
		Serial.println("Date");
		Serial.println(a_date, DEC);
		Serial.println("speed");
		Serial.println(a_speed, DEC);
		Serial.println("heading");
		Serial.println(a_heading, DEC);
		Serial.println("lat:");
		Serial.println(a_latitude, DEC);
		Serial.println("long:");
		Serial.println(a_longitude, DEC);
}
