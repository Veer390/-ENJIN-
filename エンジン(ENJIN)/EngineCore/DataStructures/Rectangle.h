#pragma once
#include<iostream>
#include<string>
#include<vector>

#include "Vec2.h"
#include "Equations/Equations.h"

namespace EngineCore
{
	namespace DataStructures
	{
		class _Rectangle
		{
		private:
			Vec2 TopLeft;
			Vec2 TopRight;
			Vec2 BottomLeft;
			Vec2 BottomRight;

			int width;
			int height;
			Vec2 Centre;

			std::vector<EngineCore::DataStructures::Equations::Line> LineEquationsAllSides;

		public:
			_Rectangle(Vec2 TopRight, Vec2 TopLeft, Vec2 BottomLeft, Vec2 BottomRight);
			_Rectangle(Vec2 TopLeft, int Width, int Height);
			_Rectangle(int Width, int Height);

			_Rectangle() = default;

			//Helper Functions
		public:
			//Starts From Top Right Then Top Left Then Bottom Left Then Bottom Right
			std::vector<Vec2> GetRectangleVertices();
			void SetRectangle(Vec2 TopLeft, Vec2 TopRight, Vec2 BottomLeft, Vec2 BottomRight);
			void MakeRectangle(); //Scans Through All Vertices of the rectangle and again makes it back into  a rectangle.. COSTLY

			int GetWidth();
			int GetHeight();

			Vec2 GetTopLeft();
			Vec2 GetTopRight();
			Vec2 GetBottomLeft();
			Vec2 GetBottomRight();
			Vec2 GetCentre();

			void SetTopLeft(Vec2 TL);
			void SetTopRight(Vec2 TR);
			void SetBottomLeft(Vec2 BL);
			void SetBottomRight(Vec2 BR);

			//Rectangle Operations...
			void TranslateRectangle(Vec2 TranslateByCoordinates);
			void ScaleRectangle(int ScalingFactor);
			void RotateRectangle(int theta);

			_Rectangle operator +(_Rectangle rhs); //Adds All Coordinates Together...

			//Friend Declarations....
		public:
			void GetNormalized(int Width, int Height); //This Function Is Only Used For Rendering With Opengl And No part Of The Engine Might Want To Use It..


		};
	}
}