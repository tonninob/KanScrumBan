/*
 * Responsible.h
 *
 *  Created on: Aug 7, 2014
 *      Author: twiik
 */

#ifndef IRESPONSIBLE_H_
#define IRESPONSIBLE_H_

#include <string>

class IResponsible {
public:
	virtual ~IResponsible() {};
	virtual std::string tellName() = 0;
	virtual bool operator== (IResponsible& compareto) = 0;
};

#endif /* IRESPONSIBLE_H_ */
