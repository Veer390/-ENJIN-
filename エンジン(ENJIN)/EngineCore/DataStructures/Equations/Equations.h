#pragma once
#include<iostream>
#include<string>
#include<vector>

#include "../Vec2.h"

namespace EngineCore
{
	namespace DataStructures
	{
		namespace Equations
		{
			class Line
			{
			public:
				Line() = default;
				
				Line(Vec2 P1, Vec2 P2)
				{
					m = P2.y - P1.y / P2.x - P1.x;
					a = -1 * (P1.x*m);
					b = -1 * (P1.y*m);
					c = P1.y - (m*P1.x);
				}

			public:
				float a;
				float b;
				float c;
				float m;

				//Get The Other Coordinate By Inputting One Coordinate
				inline Vec2 ComputePointOnLineWithX(float y);
				inline Vec2 ComputePointOnLineWithY(float x);
			};
		}
	}
}