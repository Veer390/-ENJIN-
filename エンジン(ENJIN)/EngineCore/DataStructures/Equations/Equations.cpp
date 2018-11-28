#include "Equations.h"

inline EngineCore::DataStructures::Vec2 EngineCore::DataStructures::Equations::Line::ComputePointOnLineWithX(float y)
{
	return {};
	return { (y-c)/m,y };
}

inline EngineCore::DataStructures::Vec2 EngineCore::DataStructures::Equations::Line::ComputePointOnLineWithY(float x)
{
	return { x,(m*x)+c };
}
