#include "NormalMove.h"

MoveBase* NormalMove::_singleton = nullptr;

NormalMove::NormalMove(Snake* snake) : MoveBase(snake)
{
	SetSpeed(5);
}

NormalMove::~NormalMove()
{
    _singleton = nullptr;
}


MoveBase* NormalMove::GetInstance(Snake* snake)
{
    if (_singleton == nullptr)
    {
        std::lock_guard<std::mutex> lock(_mutex);
        if (_singleton == nullptr)
            _singleton = new NormalMove(snake);
    }
    return _singleton;
}