#pragma once
#include <cassert>
#include <cmath>

class Vec2
{
public:
	static constexpr float EPSILON = 0.0001f;
	float x, y;

	constexpr Vec2() noexcept : x(0.0f), y(0.0f) {}
	constexpr Vec2(float x_in, float y_in) noexcept : x(x_in), y(y_in) {}

	void print() const;
	float magnitude() const noexcept;
	Vec2 normalized() const noexcept;
	float distance(const Vec2& rhs) const noexcept;
	
	constexpr float	magnitudeSquared() const noexcept { return (x * x) + (y * y); }
	constexpr float	distanceSquared(const Vec2& rhs) const noexcept { return (*this - rhs).magnitudeSquared(); }

	constexpr bool operator == (const Vec2& rhs) const noexcept { return ((std::fabs(this->x - rhs.x) < EPSILON) && (std::fabs(this->y - rhs.y) < EPSILON)); }
	constexpr bool operator != (const Vec2& rhs) const noexcept { return !(*this == rhs); }

	constexpr Vec2 operator + (const Vec2& rhs) const noexcept { return Vec2((this->x + rhs.x), (this->y + rhs.y)); }
	constexpr Vec2 operator - (const Vec2& rhs) const noexcept { return Vec2((this->x - rhs.x), (this->y - rhs.y)); }
	constexpr Vec2 operator * (const Vec2& rhs) const noexcept { return Vec2((this->x * rhs.x), (this->y * rhs.y)); }
	constexpr Vec2 operator / (const Vec2& rhs) const noexcept 
	{
		assert(std::fabs(rhs.x) >= EPSILON);
		assert(std::fabs(rhs.y) >= EPSILON);

		return Vec2((this->x / rhs.x), (this->y / rhs.y));
	}

	constexpr Vec2 operator + (float rhs) const noexcept { return Vec2(this->x + rhs, this->y + rhs); }
	constexpr Vec2 operator - (float rhs) const noexcept { return Vec2(this->x - rhs, this->y - rhs); }
	constexpr Vec2 operator * (float rhs) const noexcept { return Vec2(this->x * rhs, this->y * rhs); }
	constexpr Vec2 operator / (float rhs) const noexcept
	{
		assert(std::fabs(rhs) >= EPSILON);
		return Vec2(this->x / rhs, this->y / rhs);
	}

	Vec2& operator += (const Vec2& rhs) noexcept;
	Vec2& operator -= (const Vec2& rhs) noexcept;
	Vec2& operator *= (const Vec2& rhs) noexcept;
	Vec2& operator /= (const Vec2& rhs) noexcept;

	Vec2& operator += (float rhs) noexcept;
	Vec2& operator -= (float rhs) noexcept;
	Vec2& operator *= (float rhs) noexcept;
	Vec2& operator /= (float rhs) noexcept;

	friend constexpr Vec2 operator + (float lhs, const Vec2& rhs) noexcept { return rhs + lhs; }
	friend constexpr Vec2 operator - (float lhs, const Vec2& rhs) noexcept { return Vec2(lhs - rhs.x, lhs - rhs.y); }
	friend constexpr Vec2 operator * (float lhs, const Vec2& rhs) noexcept { return rhs * lhs; }
	friend constexpr Vec2 operator / (float lhs, const Vec2& rhs) noexcept
	{
		assert(std::fabs(rhs.x) >= EPSILON);
		assert(std::fabs(rhs.y) >= EPSILON);

		return Vec2(lhs / rhs.x, lhs / rhs.y);
	}
};