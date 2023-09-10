/*
 * Transitions.hpp
 *
 *  Created on: Jul 4, 2023
 *      Author: AwaOmni3d
 */

#ifndef TRANSITIONS_HPP_
#define TRANSITIONS_HPP_

#define FMT_HEADER_ONLY

struct transitions {

	//Transitions from Idle
	std::optional<state> operator()(StateIdling&, const EventReadRequest&) {
		
		return StateReading{};
	}

	std::optional<state> operator()(StateIdling&, const EventWriteRequest&) {
		
		return StateWriting{};
	}

	//Transitions from Read
	std::optional<state> operator()(StateReading&, const EventReadDone&) {
		
		return StateIdling{};
	}

	std::optional<state> operator()(StateReading&, const EventReadError&) {
		
		return StateError{};
	}

	//Transitions from Write
	std::optional<state> operator()(StateWriting&, const EventWriteDone&) {
		
		return StateIdling{};
	}

	std::optional<state> operator()(StateWriting&, const EventWriteError&) {
		
		return StateError{};
	}

	template<typename State, typename Event>
	std::optional<state> operator()(State&, const Event&) const
	{

		return std::nullopt;
	}
};



#endif /* TRANSITIONS_HPP_ */
