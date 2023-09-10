/*
 * Events.hpp
 *
 *  Created on: Jul 4, 2023
 *      Author: AwaOmni3d
 */

#ifndef INC_EVENTS_HPP_
#define INC_EVENTS_HPP_

struct EventInitialization {

};
struct EventReadRequest {

};

struct EventReadDone {

};

struct EventReadError {

};

struct EventWriteRequest {

};

struct EventWriteDone {

};

struct EventWriteError {

};

using event = std::variant< EventInitialization, EventReadRequest, EventReadDone, EventReadError, EventWriteRequest, EventWriteDone, EventWriteError>;


#endif /* INC_EVENTS_HPP_ */
