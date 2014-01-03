/*
 * NullTemperatureLogger.h
 *
 *  Created on: 28 Dec 2013
 *      Author: Sam
 */

#ifndef NULLTEMPERATURELOGGER_H_
#define NULLTEMPERATURELOGGER_H_

#include "ITemperatureRemoteLogger.h"

class NullTemperatureLogger: public ITemperatureRemoteLogger {
public:
	virtual void log(float temperature) {
	}
};

#endif /* NULLTEMPERATURELOGGER_H_ */
