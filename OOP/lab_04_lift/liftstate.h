#ifndef LIFTSTATE_H
#define LIFTSTATE_H

enum class LiftState
{
    RISE = 0,
    DESCEND = 1,
    ON_FLOOR = 2,
    WAIT = 3,
    UNDEFINED_WAITING = 4
};

#endif // LIFTSTATE_H
