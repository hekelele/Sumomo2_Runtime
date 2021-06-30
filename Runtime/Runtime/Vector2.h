#pragma once

//- INCLUDES --------------------------------------------------------------
#include <math.h>
#include "Constant.h"
//=========================================================================

namespace Sumomo2D::Math
{
	typedef struct _Vector2 {
		float x;
		float y;

		//= Assignment ============================================================

		_Vector2() {
			x = 0;
			y = 0;
		}

		_Vector2(const _Vector2& vector) {
			this->x = vector.x;
			this->y = vector.y;
		}

		_Vector2(float x, float y) {
			this->x = x;
			this->y = y;
		}

		_Vector2(int x, int y) {
			this->x = static_cast<float>(x);
			this->y = static_cast<float>(y);
		}

		//=========================================================================


		//= ADDITION ==============================================================

		_Vector2 operator+(const _Vector2& rhs) const
		{
			return _Vector2
			(
				this->x + rhs.x,
				this->y + rhs.y
			);
		}

		void operator+=(const _Vector2& rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
		}

		//=========================================================================


		//= SUBTRACTION ===========================================================

		_Vector2 operator-(const _Vector2& rhs) const
		{
			return _Vector2
			(
				this->x - rhs.x,
				this->y - rhs.y
			);
		}

		void operator-=(const _Vector2& rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
		}

		//=========================================================================


		//= MULTIPLICATION ========================================================

		_Vector2 operator*(const float scalar) const
		{
			return _Vector2
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

		friend _Vector2 operator*(const float scalar, _Vector2 vec)
		{
			return _Vector2
			(
				vec.x  * scalar,
				vec.y  * scalar
			);
		}

		//=========================================================================


		//= DIVISION ==============================================================

		_Vector2 operator/(const float scalar) const
		{
			return _Vector2
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

		friend _Vector2 operator/(const float scalar, _Vector2 vec)
		{
			return _Vector2
			(
				vec.x / scalar,
				vec.y / scalar
			);
		}

		//=========================================================================


		//= EQUATION ==============================================================

		bool operator==(const _Vector2& rhs) const
		{
			return this->x == rhs.x && this->y == rhs.y;
		}

		bool operator!=(const _Vector2& rhs) const
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

		[[nodiscard]] static float Distance(const _Vector2& a, const _Vector2& b)
		{
			return (a - b).Magnitude();
		}

		[[nodiscard]] static float DistanceSquared(const _Vector2& a, const _Vector2& b)
		{
			return (a - b).MagnitudeSquared();
		}

		void Normalize() {
			float mag = this->Magnitude();
			this->x /= mag;
			this->y /= mag;
		}

		[[nodiscard]] _Vector2 NormalizeValue() {
			float mag = this->Magnitude();
			return _Vector2
			(
				this->x / mag,
				this->y / mag
			);
		}

		static const _Vector2 Zero;
		static const _Vector2 One;

		//=========================================================================

	}Vector2;


	//= HIGH SPEED FUNCTION ===================================================

	void VEC2_ADD(Vector2& result, const Vector2& va, const Vector2& vb);
	void VEC2_SUB(Vector2& result, const Vector2& va, const Vector2& vb);
	void VEC2_NORM(Vector2& result, const Vector2& source);
	[[nodiscard]] float VEC2_DOT(const Vector2& va, const Vector2& vb);
	[[nodiscard]] float VEC2_DEGREE(const Vector2& va, const Vector2& vb);
	[[nodiscard]] float VEC2_RADIAN(const Vector2& va, const Vector2& vb);

	//=========================================================================
}