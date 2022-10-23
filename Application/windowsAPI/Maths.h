#pragma once

struct Vector2
{
	float x;
	float y;

	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2(const Vector2& other) = default;
	//Vector2(const Vector2&& other) = default;		이동생성자 - 한번 찾아보자

	Vector2() = default;
	~Vector2() = default;


	Vector2 operator +(Vector2 other)
	{
		Vector2 temp;
		temp.x = x + other.x;
		temp.y = y + other.y;

		return temp;
	}

	Vector2 operator -(Vector2 other)
	{
		Vector2 temp;
		temp.x = x - other.x;
		temp.y = y - other.y;

		return temp;
	}

	Vector2 operator /(const float value)
	{
		Vector2 temp;
		
		temp.x = x / value;
		temp.y = y / value;

		return temp;
	}
};
