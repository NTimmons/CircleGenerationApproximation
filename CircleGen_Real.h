#pragma once
#include <array>
#include "helper.h"

namespace RealImpl
{
	template <typename T, int numVerts>
	std::array<std::pair<T, T>, numVerts> GenerateCircleVertices_A(T _radius, std::pair<T, T> _offset)
	{
		std::array<std::pair<T, T>, numVerts> points;

		T theta = 0.f;
		T thetaStep = (T)(PI) / (T)numVerts;
		for (int i = 0; i < numVerts; i++)
		{
			T x = (_radius * cos(theta)) + _offset.first;
			T y = (_radius * sin(theta)) + _offset.second;
			points[i] = std::make_pair(x, y);
			theta += thetaStep;
		}

		return points;
	}

	template <typename T, int numVerts>
	std::array<std::pair<T, T>, numVerts> GenerateCircleVertices_B(T _radius, std::pair<T, T> _offset)
	{
		std::array<std::pair<T, T>, numVerts> points;

		T thetaStep = (T)(PI) / (T)numVerts;
		std::pair<T, T> movingPos = std::make_pair((T)_radius + _offset.first, (T)_radius + +_offset.second);
		for (int i = 0; i < numVerts; i++)
		{
			movingPos = rotate2d(thetaStep, movingPos.first, movingPos.second);
			points[i] = movingPos;
		}

		return points;
	}

	template<typename T>
	std::pair<T, T> rotate2d(T _rads, T _xpos, T _ypos)
	{
		T Mat2D[2][2];
		T newX, newY;

		Mat2D[0][0] = cos(_rads);
		Mat2D[0][1] = -sin(_rads);
		Mat2D[1][0] = sin(_rads);
		Mat2D[1][1] = cos(_rads);

		newX = (Mat2D[0][0] * _xpos) + (Mat2D[0][1] * _ypos);
		newY = (Mat2D[1][0] * _xpos) + (Mat2D[1][1] * _ypos);

		return std::make_pair(newX, newY);
	}
}

