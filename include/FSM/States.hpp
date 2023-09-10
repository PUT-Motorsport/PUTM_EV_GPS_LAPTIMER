/*
 * States.hpp
 *
 *  Created on: Jul 4, 2023
 *      Author: AwaOmni3d
 */

#ifndef INC_STATES_HPP_
#define INC_STATES_HPP_

struct StateIdling {

};

struct StateWaitingForStart{

};

struct StateMeasuring {

};

using state = std::variant< StateIdling, StateMeasuringAcc, StateMeasuringSkidpad, StateMeasuringLap>;



#endif /* INC_STATES_HPP_ */
