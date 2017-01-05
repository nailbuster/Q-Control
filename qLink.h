/*
QControl PID controller for BBQ

Copyright (c) 2016 David Paiva (david@nailbuster.com). All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _QLINK_h
#define _QLINK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//#define SoftSerial   //define if using Software serial on 10,11; 
//#define HardSerial   //define if using Software serial on 10,11;  

#ifdef SoftSerial
#include "SoftwareSerial.h"
#endif

class QLinkClass
{
 protected:
	 unsigned long lastTimerChk;
	 String msgStr="";
	 void checkSerialMsg();
	 void updateInfoEsp();
 public:
	 QLinkClass();
	 int updateInterval = 3;   //default seconds
	 bool inProgMode = false;  //are we updating eeprom values?
	 void begin();
	 void run();			   //called in main loop
	 void SendAlarm(char * ProbName, String AlarmType, int AlarmCheckTemp, int CurTemp);
};




#endif

