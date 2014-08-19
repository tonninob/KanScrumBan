/*
 * NoSuchTaskInStory.h
 *
 *  Created on: Aug 18, 2014
 *      Author: twiik
 */

#ifndef NOSUCHTASKINSTORY_H_
#define NOSUCHTASKINSTORY_H_

namespace ScrumExceptions {

class NoSuchTaskInStory : public std::exception {
	virtual const char* what() const throw()
	{
		return "No such task added to specified story";
	}
};

} /* namespace ScrumExceptions */

#endif /* NOSUCHTASKINSTORY_H_ */
