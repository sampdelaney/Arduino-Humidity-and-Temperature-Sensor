/*
 * UdpTemperatureLogger.h
 *
 *  Created on: 1 Jan 2014
 *      Author: Sam
 */

#ifndef UDPTEMPERATURELOGGER_H_
#define UDPTEMPERATURELOGGER_H_

#include "ITemperatureRemoteLogger.h"
#include "UdpServerManager.h"
#include <EthernetUdp.h>

class UdpTemperatureLogger: public ITemperatureRemoteLogger {
public:
	UdpTemperatureLogger(IPAddress ipAddress, uint8_t port);
	UdpTemperatureLogger(UdpServerManager *udpServerManager);
	virtual void log(float temperature);
private:
	UdpServerManager* _udpServerManager;
	EthernetUDP _udp;
	IPAddress _ipAddress;
	uint8_t _port;
	char buffer[7];
};

#endif /* UDPTEMPERATURELOGGER_H_ */
