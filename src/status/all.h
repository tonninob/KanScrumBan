/*
 * all.h
 *
 *  Created on: Aug 12, 2014
 *      Author: twiik
 */

#ifndef ALL_STATUSES_H_
#define ALL_STATUSES_H_

#include <string>

namespace ScrumWorkStatus {

	class WorkStatus {
	public:
		virtual ~WorkStatus() {};
		virtual std::string describe() = 0;
	};

	class NotStarted: public WorkStatus {
	public:
		virtual ~NotStarted() {};
		virtual std::string describe() {
			return "Not started";
		}
	};

	class Started: public WorkStatus {
	public:
		virtual ~Started() {};
		virtual std::string describe() {
			return "Started";
		}
	};

	class OnHold: public WorkStatus {
	public:
		virtual ~OnHold() {};
		virtual std::string describe() {
			return "On hold";
		}
	};

	class Completed: public WorkStatus {
	public:
		virtual ~Completed() {};
		virtual std::string describe() {
			return "Completed";
		}
	};

	class Removed: public WorkStatus {
	public:
		virtual ~Removed() {};
		virtual std::string describe() {
			return "Removed";
		}
	};

}

#endif /* ALL_STATUSES_H_ */
