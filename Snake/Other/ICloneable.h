#pragma once

template <typename T>
class ICloneable
{
public:
	T virtual Clone() const = 0;
};

