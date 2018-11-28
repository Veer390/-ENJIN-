#include "Rectangle.h"
#include<cmath>
#include<cassert>

#define PI 3.14159265

int DistanceBetweenTwoPoints(EngineCore::DataStructures::Vec2 P1, EngineCore::DataStructures::Vec2 P2)
{
	return sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
}
EngineCore::DataStructures::_Rectangle::_Rectangle(Vec2 TopRight, Vec2 TopLeft, Vec2 BottomLeft, Vec2 BottomRight)
	:
	TopRight(TopRight),
	TopLeft(TopLeft),
	BottomLeft(BottomLeft),
	BottomRight(BottomRight)
{
	width = DistanceBetweenTwoPoints(TopLeft, TopRight);
	height = DistanceBetweenTwoPoints(TopLeft, BottomLeft);
	Centre = { TopLeft.x + (width / 2),TopLeft.y - (height / 2) };

	//Asserts To Make Sure It Is A Rectangle...
	assert(TopRight.x > TopLeft.x);
	assert(TopRight.y == TopLeft.y);

	//Making Sure BottomLeft is Actually Bottom Left
	assert(BottomRight.x > BottomLeft.x);
	assert(BottomRight.y == BottomLeft.y);

	//Final Measure To Make Sure The Rectangle is Not Inverted..
	assert(BottomRight.y > TopRight.y);

	//Another Measure
	assert(TopLeft.x == BottomLeft.x);
	assert(TopRight.x == BottomRight.x);
}

EngineCore::DataStructures::_Rectangle::_Rectangle(Vec2 TopLeft, int Width, int Height)
	:
	TopLeft(TopLeft),
	TopRight({ TopLeft.x + Width,TopLeft.y }),
	BottomLeft({ TopLeft.x,TopLeft.y + Height }),
	BottomRight({ TopLeft.x + Width,TopLeft.y + Height }),
	width(Width),
	height(Height),
	Centre({TopLeft.x+(Width/2),TopLeft.y-(Height/2)})
{}

//Generates A Rectangle With Origin  At Center
EngineCore::DataStructures::_Rectangle::_Rectangle(int Width, int Height)
	:
	TopLeft({float(-Width/2),float(Height/2)}),
	TopRight({float(Width/2),float(Height/2)}),
	BottomLeft({float(-Width/2),float(-Height/2)}),
	BottomRight({float(Width/2),float(-Height/2)}),
	width(Width),
	height(Height),
	Centre({0,0})
{}

std::vector<EngineCore::DataStructures::Vec2> EngineCore::DataStructures::_Rectangle::GetRectangleVertices()
{
	std::vector<Vec2> Temp;
	Temp.emplace_back(TopRight);
	Temp.emplace_back(TopLeft);
	Temp.emplace_back(BottomLeft);
	Temp.emplace_back(BottomRight);

	return Temp;
}

void EngineCore::DataStructures::_Rectangle::SetRectangle(Vec2 TopLeft, Vec2 TopRight, Vec2 BottomLeft, Vec2 BottomRight)
{
	this->TopLeft = TopLeft;
	this->TopRight = TopRight;
	this->BottomLeft = BottomLeft;
	this->BottomRight = BottomRight;
}

void EngineCore::DataStructures::_Rectangle::MakeRectangle()
{
	std::vector<Vec2> Temp = GetRectangleVertices();
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
		{
			if (Temp[i].x > Temp[j].x)
				std::swap(Temp[i], Temp[j]);
		}
	}
	//After This First Two are Left Side And Second two Are Right Side..
	
	//Find TopLeft And Bottom Left..
	if (Temp[0].y > Temp[1].y)
	{
		TopLeft = { Temp[0].x, Temp[0].y };
		BottomLeft = { Temp[1].x, Temp[1].y };
	}
	BottomLeft = { Temp[0].x, Temp[0].y };
	TopLeft = { Temp[1].x, Temp[1].y };

	//Find Top Right And Bottom Right
	if (Temp[2].y > Temp[3].y)
	{
		TopRight = { Temp[2].x, Temp[2].y };
		BottomRight = { Temp[3].x, Temp[3].y };
	}
	BottomRight = { Temp[2].x, Temp[2].y };
	TopRight = { Temp[3].x, Temp[3].y };
}

int EngineCore::DataStructures::_Rectangle::GetWidth()
{
	return width;//TopRight.x - TopLeft.x;
}

int EngineCore::DataStructures::_Rectangle::GetHeight()
{
	return height;//TopRight.y - BottomRight.y;
}

EngineCore::DataStructures::Vec2 EngineCore::DataStructures::_Rectangle::GetTopLeft()
{
	return TopLeft;
}

EngineCore::DataStructures::Vec2 EngineCore::DataStructures::_Rectangle::GetTopRight()
{
	return TopRight;
}

EngineCore::DataStructures::Vec2 EngineCore::DataStructures::_Rectangle::GetBottomLeft()
{
	return BottomLeft;
}

EngineCore::DataStructures::Vec2 EngineCore::DataStructures::_Rectangle::GetBottomRight()
{
	return BottomRight;
}

EngineCore::DataStructures::Vec2 EngineCore::DataStructures::_Rectangle::GetCentre()
{
	//int W = GetWidth();
	//int H = GetHeight();
	Centre = { (TopLeft.x + BottomRight.x) / 2,(TopLeft.y + BottomRight.y) / 2 };
	return Centre;
}

void EngineCore::DataStructures::_Rectangle::SetTopLeft(Vec2 TL)
{
	TopLeft = TL;
}

void EngineCore::DataStructures::_Rectangle::SetTopRight(Vec2 TR)
{
	TopRight = TR;
}

void EngineCore::DataStructures::_Rectangle::SetBottomLeft(Vec2 BL)
{
	BottomLeft = BL;
}

void EngineCore::DataStructures::_Rectangle::SetBottomRight(Vec2 BR)
{
	BottomRight = BR;
}

void EngineCore::DataStructures::_Rectangle::TranslateRectangle(Vec2 TranslateByCoordinates)
{
	TopLeft += TranslateByCoordinates;
	TopRight += TranslateByCoordinates;
	BottomLeft += TranslateByCoordinates;
	BottomRight += TranslateByCoordinates;
}

void EngineCore::DataStructures::_Rectangle::ScaleRectangle(int ScalingFactor)
{
	TopLeft *= ScalingFactor;
	TopRight *= ScalingFactor;
	BottomLeft *= ScalingFactor;
	BottomRight *= ScalingFactor;
}

void EngineCore::DataStructures::_Rectangle::RotateRectangle(int theta)
{
	float Angle = (theta * PI )/ 180;

	std::vector<Vec2> AllVertices;
	AllVertices.emplace_back(TopRight);
	AllVertices.emplace_back(TopLeft);
	AllVertices.emplace_back(BottomLeft);
	AllVertices.emplace_back(BottomRight);

	//_Rectangle Temp(GetWidth(), GetHeight());

	Vec2 Centre = GetCentre();
	for (auto& i : AllVertices)
	{
		float tempx = i.x - Centre.x;
		float tempy = i.y - Centre.y;

		float RotatedX = (tempx * cos(Angle)) - (tempy * sin(Angle));
		float RotatedY = (tempx * sin(Angle)) + (tempy * cos(Angle));

		i.x = RotatedX + Centre.x;
		i.y = RotatedY + Centre.y;
	}
	TopRight = AllVertices[0];
	TopLeft = AllVertices[1];
	BottomLeft = AllVertices[2];
	BottomRight = AllVertices[3];
}

EngineCore::DataStructures::_Rectangle EngineCore::DataStructures::_Rectangle::operator+(_Rectangle rhs)
{
	_Rectangle Temp;
	Temp.SetBottomLeft(BottomRight + rhs.GetBottomLeft());
	Temp.SetBottomRight(BottomRight + rhs.GetBottomRight());
	Temp.SetTopLeft(TopLeft + rhs.GetTopLeft());
	Temp.SetTopRight(TopRight + rhs.GetTopRight());

	return Temp;
}

void EngineCore::DataStructures::_Rectangle::GetNormalized(int Width, int Height)
{
	TopLeft.x = TopLeft.x / Width;
	TopLeft.y = TopLeft.y / Height;

	TopRight.x = TopRight.x / Width;
	TopRight.y = TopRight.y / Height;

	BottomLeft.x = BottomLeft.x / Width;
	BottomLeft.y = BottomLeft.y / Height;

	BottomRight.x = BottomRight.x / Width;
	BottomRight.y = BottomRight.y / Height;

}
