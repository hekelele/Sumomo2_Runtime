#pragma once

//- INCLUDES --------------------------------------------------------------
#include <math.h>
#include "Constant.h"
//=========================================================================

namespace Sumomo2D::Math
{
	struct Vector2 {
		float x;
		float y;

		//= Assignment ============================================================

		Vector2() {
			x = 0;
			y = 0;
		}

		Vector2(const Vector2& vector) {
			this->x = vector.x;
			this->y = vector.y;
		}

		Vector2(float x, float y) {
			this->x = x;
			this->y = y;
		}

		Vector2(int x, int y) {
			this->x = static_cast<float>(x);
			this->y = static_cast<float>(y);
		}

		//=========================================================================


		//= ADDITION ==============================================================

		Vector2 operator+(const Vector2& rhs) const
		{
			return Vector2
			(
				this->x + rhs.x,
				this->y + rhs.y
			);
		}

		void operator+=(const Vector2& rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
		}

		//=========================================================================


		//= SUBTRACTION ===========================================================

		Vector2 operator-(const Vector2& rhs) const
		{
			return Vector2
			(
				this->x - rhs.x,
				this->y - rhs.y
			);
		}

		void operator-=(const Vector2& rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
		}

		//=========================================================================


		//= MULTIPLICATION ========================================================

		Vector2 operator*(const float scalar) const
		{
			return Vector2
			(
				this->x * scalar,
				this->y * scalar
			);
		}

		void operator*=(const float scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
		}

		friend Vector2 operator*(const float scalar, Vector2 vec)
		{
			return Vector2
			(
				vec.x  * scalar,
				vec.y  * scalar
			);
		}

		//=========================================================================


		//= DIVISION ==============================================================

		Vector2 operator/(const float scalar) const
		{
			return Vector2
			(
				this->x / scalar,
				this->y / scalar
			);
		}

		void operator/=(const float scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
		}

		friend Vector2 operator/(const float scalar, Vector2 vec)
		{
			return Vector2
			(
				vec.x / scalar,
				vec.y / scalar
			);
		}

		//=========================================================================


		//= EQUATION ==============================================================

		bool operator==(const Vector2& rhs) const
		{
			return this->x == rhs.x && this->y == rhs.y;
		}

		bool operator!=(const Vector2& rhs) const
		{
			return this->x != rhs.x || this->y != rhs.y;
		}

		//=========================================================================


		//= FUNCTION ==============================================================

		[[nodiscard]] float Magnitude() const
		{
			return sqrtf(x * x + y * y);
		}

		[[nodiscard]] float MagnitudeSquared() const
		{
			return x * x + y * y;
		}

		[[nodiscard]] static float Distance(const Vector2& a, const Vector2& b)
		{
			return (a - b).Magnitude();
		}

		[[nodiscard]] static float DistanceSquared(const Vector2& a, const Vector2& b)
		{
			return (a - b).MagnitudeSquared();
		}

		void Normalize() {
			float mag = this->Magnitude();
			this->x /= mag;
			this->y /= mag;
		}

		[[nodiscard]] Vector2 NormalizeValue() {
			float mag = this->Magnitude();
			return Vector2
			(
				this->x / mag,
				this->y / mag
			);
		}

		static const Vector2 Zero;
		static const Vector2 One;

		//=========================================================================

	};


	//= HIGH SPEED FUNCTION ===================================================

	void VEC2_ADD(Vector2& result, const Vector2& va, const Vector2& vb);
	void VEC2_SUB(Vector2& result, const Vector2& va, const Vector2& vb);
	void VEC2_NORM(Vector2& result, const Vector2& source);
	[[nodiscard]] float VEC2_DOT(const Vector2& va, const Vector2& vb);
	[[nodiscard]] float VEC2_DEGREE(const Vector2& va, const Vector2& vb);
	[[nodiscard]] float VEC2_RADIAN(const Vector2& va, const Vector2& vb);

	//=========================================================================
}