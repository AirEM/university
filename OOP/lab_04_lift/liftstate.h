#ifndef LIFTSTATE_H
#define LIFTSTATE_H

enum class LiftState
{
    RISE = 0,
    DESCEND = 1,
    WAIT = 2,
    UNDEFINED_WAITING = 3
};

#endif // LIFTSTATE_H
