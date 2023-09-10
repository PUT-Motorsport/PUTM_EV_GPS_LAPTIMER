/*
 * FSM.hpp
 *
 *  Created on: Jul 4, 2023
 *      Author: AwaOmni3d
 */

#ifndef INC_FSM_HPP_
#define INC_FSM_HPP_4

#include <variant>
#include <optional>
#include "States.hpp"
#include "Events.hpp"
#include "Transitions.hpp"

template<typename StateVariant, typename EventVariant, typename Transition>
class fsm {
	StateVariant state_ = { StateIdling{} };
public:
	void dispatch(const EventVariant& event)
	{
		std::optional<StateVariant> new_state = std::visit(Transition{}, state_, event);
		if (new_state)
		{
			state_ = *std::move(new_state);
		}
	}
	inline StateVariant return_state()
	{
		return state_;
	}
};

using connection_fsm = fsm<state, event, transitions>;

template<typename Fsm, typename... Events>
void dispatch(Fsm& fsm, Events&&... events)
{
	(fsm.dispatch(std::forward<Events>(events)), ...);
}

#endif /* INC_FSM_HPP_ */
