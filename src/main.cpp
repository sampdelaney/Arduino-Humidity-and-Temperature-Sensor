/*
 * main.cpp
 *
 *  Created on: 28 Dec 2013
 *      Author: Sam
 */

#include <Arduino.h>
#include <Adc.h>
#include <SPI.h>
#include <Ethernet.h>
#include "ITemperatureRemoteLogger.h"
#include "NullTemperatureLogger.h"
#include "UdpTemperatureLogger.h"
#include "UdpServerManager.h"
#include <TemperatureSensor.h>
#include <LiquidCrystal.h>
uint8_t MAC_ADDRESS[] = { 1 };
IPAddress STATIC_IP_ADDRESS(192, 168, 0, 100);
uint16_t STATIC_PORT = 8081;

const unsigned long LOOP_INTERVAL = 1000;

const uint8_t ADC_ARDUINO_PIN = A0;
const uint8_t ADC_ARDUINO_RESOLUTION = 10;
const float ADC_ARDUINO_VOLTS_MIN = 0;
const float ADC_ARDUINO_VOLTS_MAX = 5;

Adc adc(ADC_ARDUINO_PIN, ADC_ARDUINO_RESOLUTION, ADC_ARDUINO_VOLTS_MIN,
		ADC_ARDUINO_VOLTS_MAX);
TemperatureSensor temperatureSensor(&adc);

/* Actual implementation is decided at run-time dependent on whether we can
 * connect to Ethernet or not.
 */
ITemperatureRemoteLogger *tempLogger;

UdpServerManager serverManager;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

float temperature;

//------------------------------------------------------------------------------

void setup() {

	lcd.begin(16, 2);
	lcd.setCursor(0, 0);
	lcd.print("Temperature:");
	// start Ethernet connection using DHCP
	/*if (Ethernet.begin(MAC_ADDRESS) == 1) {
		// use the HTTP logger
		tempLogger = new UdpTemperatureLogger(STATIC_IP_ADDRESS, STATIC_PORT);
	} else {
		// use the null logger
		tempLogger = new NullTemperatureLogger();
	}*/
}

//------------------------------------------------------------------------------

void loop() {
	//char buffer[7];
	//dtostrf(0.4, 7, 3, buffer);
	// get the current temperature
	temperature = temperatureSensor.readTemperature();
	// display on the LCD
	lcd.setCursor(0, 1);
	//lcd.write(0.23f);
	lcd.print(temperature);
	// log the temperature
	//tempLogger->log(temperature);
	// check for incoming command on UDP
	//serverManager.listenForCommand();
	// wait for a bit
	delay(LOOP_INTERVAL);
}
