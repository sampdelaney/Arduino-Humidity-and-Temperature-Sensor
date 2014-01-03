/*
 * UdpServerManager.h
 *
 *  Created on: 1 Jan 2014
 *      Author: Sam
 */

#ifndef UDPSERVERMANAGER_H_
#define UDPSERVERMANAGER_H_

#include <EthernetUdp.h>

class UdpServerManager {
public:
	UdpServerManager();
	virtual ~UdpServerManager();
	void listenForCommand();
	bool serverAvailable();
	IPAddress* getServerAddress();
	uint16_t getServerPort();
private:
	EthernetUDP _udp;
	IPAddress _serverAddress;
	uint16_t _serverPort;
	/**
	 * Sets the current server address and port from the remote address on the
	 * UDP. This is usually invoked when the "set address" command is received.
	 */
	void discoverClient();
	void bindServerAddress();
	void unbindServerAddress();
};

#endif /* UDPSERVERMANAGER_H_ */
