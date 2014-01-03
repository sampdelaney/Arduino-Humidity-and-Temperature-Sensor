/*
 * ITemperatureRemoteLogger.h
 *
 *  Created on: 28 Dec 2013
 *      Author: Sam
 */

#ifndef ITEMPERATUREREMOTELOGGER_H_
#define ITEMPERATUREREMOTELOGGER_H_

class ITemperatureRemoteLogger {
public:
	virtual ~ITemperatureRemoteLogger(){};
	virtual void log(float temperature) = 0;
};

#endif /* ITEMPERATUREREMOTELOGGER_H */
