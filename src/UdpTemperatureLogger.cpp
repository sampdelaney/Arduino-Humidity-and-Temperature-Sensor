/*
 * UdpTemperatureLogger.cpp
 *
 *  Created on: 1 Jan 2014
 *      Author: Sam
 */

#include "UdpTemperatureLogger.h"
#include <EthernetUdp.h>

UdpTemperatureLogger::UdpTemperatureLogger(IPAddress ipAddress, uint8_t port) :
		ITemperatureRemoteLogger() {
	_ipAddress = ipAddress;
	_port = port;
	_udpServerManager = NULL;
}

UdpTemperatureLogger::UdpTemperatureLogger(UdpServerManager* udpServerManager) :
		ITemperatureRemoteLogger() {
	_ipAddress = INADDR_NONE;
	_port = 0;
	_udpServerManager = udpServerManager;
}

void UdpTemperatureLogger::log(float temperature) {
	// convert float temperature to string
	dtostrf(temperature, 7, 3, buffer);
	// check which IP address we're using - always try to use server manager first
	if (_udpServerManager != NULL && _udpServerManager->serverAvailable()) {
		_udp.beginPacket(*_udpServerManager->getServerAddress(),
				_udpServerManager->getServerPort());
	} else {
		_udp.beginPacket(_ipAddress, _port);
	}
	_udp.write(buffer);
	_udp.endPacket();
}
