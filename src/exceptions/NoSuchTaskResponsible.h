/*
 * NoSuchTaskResponsible.h
 *
 *  Created on: Aug 7, 2014
 *      Author: twiik
 */

#ifndef NOSUCHTASKRESPONSIBLE_H_
#define NOSUCHTASKRESPONSIBLE_H_

#include <exception>

namespace ScrumExceptions {

class NoSuchTaskResponsible : public std::exception {
	virtual const char* what() const throw()
	{
		return "No such responsible added to specified task";
	}
};

} /* namespace ScrumExceptions */

#endif /* NOSUCHTASKRESPONSIBLE_H_ */
