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

};
