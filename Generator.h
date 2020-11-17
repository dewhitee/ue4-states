#pragma once

#ifndef ACTIONSTATE
#define ACTIONSTATE(action_name) \
void action_name(bool Is##action_name) { UpdateAction(Is##action_name, EActionState::##action_name); } \
bool action_name() const { return States.Contains(EActionState::##action_name); }
#endif

#ifndef INIT_ACTIONSTATES
#define INIT_ACTIONSTATES(...) \
enum class EActionState : uint8 \
{ \
	__VA_ARGS__ \
};
#endif

#ifndef LIST_ACTIONSTATES
#define LIST_ACTIONSTATES
#endif

#ifndef CONDITIONSTATE
#define CONDITIONSTATE(condition_name) \
void condition_name(bool Is##condition_name) { UpdateCondition(Is##condition_name, EConditionState::##condition_name); } \
bool condition_name() const { return States.Contains(EConditionState::##condition_name); }
#endif

