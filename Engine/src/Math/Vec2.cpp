#include <cassert>
#include <iostream>
#include <cmath>
#include "Vec2.h"

void Vec2::print() const
{
	std::cout << this->x << " " << this->y << "\n";
}

float Vec2::magnitude() const noexcept
{
	return std::sqrt(Vec2::magnitudeSquared());
}

Vec2 Vec2::normalized() const noexcept
{
	float mag = this->magnitude();
	assert(std::fabs(mag) >= EPSILON);

	return ((*this) / mag);
}

float Vec2::distance(const Vec2& rhs) const noexcept
{
	//return std::sqrt(((rhs.x - this->x) * (rhs.x - this->x)) + ((rhs.y - this->y) * (rhs.y - this->y)));
	return (*this - rhs).magnitude();
}

Vec2& Vec2::operator += (const Vec2& rhs) noexcept
{
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

Vec2& Vec2::operator -= (const Vec2& rhs) noexcept
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	return *this;
}

Vec2& Vec2::operator *= (const Vec2& rhs) noexcept
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	return *this;
}

Vec2& Vec2::operator /= (const Vec2& rhs) noexcept
{
	assert(std::fabs(rhs.x) >= EPSILON);
	assert(std::fabs(rhs.y) >= EPSILON);

	this->x /= rhs.x;
	this->y /= rhs.y;
	return *this;
}

Vec2& Vec2::operator += (float rhs) noexcept
{
	this->x += rhs;
	this->y += rhs;
	return *this;
}

Vec2& Vec2::operator -= (float rhs) noexcept
{
	this->x -= rhs;
	this->y -= rhs;
	return *this;
}

Vec2& Vec2::operator *= (float rhs) noexcept
{
	this->x *= rhs;
	this->y *= rhs;
	return *this;
}

Vec2& Vec2::operator /= (float rhs) noexcept
{
	assert(std::fabs(rhs) >= EPSILON);

	this->x /= rhs;
	this->y /= rhs;
	return *this;
}