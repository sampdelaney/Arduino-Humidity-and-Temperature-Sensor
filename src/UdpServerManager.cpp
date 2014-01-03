/*
 * UdpServerManager.cpp
 *
 *  Created on: 1 Jan 2014
 *      Author: Sam
 */

#include "UdpServerManager.h"

UdpServerManager::UdpServerManager() {
	// default to zero'd address
	_serverAddress = INADDR_NONE;
	_serverPort = 0;
}

UdpServerManager::~UdpServerManager() {
	// TODO Auto-generated destructor stub
}

void UdpServerManager::listenForCommand() {
	// try to read from udp
	int packetSize = _udp.parsePacket();
	// if something is in the buffer,
	if (packetSize > 0) {
		String cmd = _udp.readString();
		// handle different commands
		if (cmd == "arduino_temp.discover_client") {
			discoverClient();
		} else if (cmd == "arduino_temp.bind_address") {
			bindServerAddress();
		} else if (cmd == "arduino_temp.unbind_address") {
			unbindServerAddress();
		}
	}
}

IPAddress* UdpServerManager::getServerAddress() {
	return &_serverAddress;
}

uint16_t UdpServerManager::getServerPort() {
	return _serverPort;
}

bool UdpServerManager::serverAvailable() {
	return !(_serverAddress == INADDR_NONE && _serverPort == 0);
}

void UdpServerManager::bindServerAddress() {
	_serverAddress = _udp.remoteIP();
	_serverPort = _udp.remotePort();
}

void UdpServerManager::discoverClient() {
	_udp.beginPacket(_udp.remoteIP(), _udp.remotePort());
	_udp.write("arduino_temp.hello_world");
	_udp.endPacket();
}

void UdpServerManager::unbindServerAddress() {
	if (_serverAddress == _udp.remoteIP() && _serverPort == _udp.remotePort()) {
		// reset address
		_serverAddress = INADDR_NONE;
		_serverPort = 0;
	}
}
