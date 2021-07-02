#pragma once

//- INCLUDES --------------------------------------------------------------
#include <math.h>
#include "Constant.h"
//=========================================================================

namespace Sumomo2::Math
{
	class Vector3 {
	public:
		float x;
		float y;
		float z;

		//= Assignment ============================================================

		Vector3() {
			x = 0;
			y = 0;
			z = 0;
		}

		Vector3(const Vector3& vector) {
			this->x = vector.x;
			this->y = vector.y;
			this->z = vector.z;
		}

		Vector3(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vector3(int x, int y, int z) {
			this->x = static_cast<float>(x);
			this->y = static_cast<float>(y);
			this->z = static_cast<float>(z);
		}

		//=========================================================================


		//= ADDITION ==============================================================

		Vector3 operator+(const Vector3& rhs) const
		{
			return Vector3
			(
				this->x + rhs.x,
				this->y + rhs.y,
				this->z + rhs.z
			);
		}

		void operator+=(const Vector3& rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			this->z += rhs.z;
		}

		//=========================================================================


		//= SUBTRACTION ===========================================================

		Vector3 operator-(const Vector3& rhs) const
		{
			return Vector3
			(
				this->x - rhs.x,
				this->y - rhs.y,
				this->z - rhs.z
			);
		}

		void operator-=(const Vector3& rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
			this->z -= rhs.z;
		}

		//=========================================================================


		//= MULTIPLICATION ========================================================

		Vector3 operator*(const float scalar) const
		{
			return Vector3
			(
				this->x * scalar,
				this->y * scalar,
				this->z * scalar
			);
		}

		void operator*=(const float scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
		}

		friend Vector3 operator*(const float scalar, Vector3 vec)
		{
			return Vector3
			(
				vec.x  * scalar,
				vec.y  * scalar,
				vec.z  * scalar
			);
		}

		//=========================================================================

		//= DIVISION ==============================================================

		Vector3 operator/(const float scalar) const
		{
			return Vector3
			(
				this->x / scalar,
				this->y / scalar,
				this->z / scalar
			);
		}

		void operator/=(const float scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
			this->z /= scalar;
		}

		friend Vector3 operator/(const float scalar, Vector3 vec)
		{
			return Vector3
			(
				vec.x / scalar,
				vec.y / scalar,
				vec.z / scalar
			);
		}

		//=========================================================================


		//= EQUATION ==============================================================

		bool operator==(const Vector3& rhs) const
		{
			return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z;
		}

		bool operator!=(const Vector3& rhs) const
		{
			return this->x != rhs.x || this->y != rhs.y || this->z != rhs.z;
		}

		//=========================================================================


		//= FUNCTION ==============================================================

		[[nodiscard]] float Magnitude() const
		{
			return sqrtf(x * x + y * y + z * z);
		}

		[[nodiscard]] float MagnitudeSquared() const
		{
			return x * x + y * y + z * z;
		}

		[[nodiscard]] static float Distance(const Vector3& a, const Vector3& b)
		{
			return (a - b).Magnitude();
		}

		[[nodiscard]] static float DistanceSquared(const Vector3& a, const Vector3& b)
		{
			return (a - b).MagnitudeSquared();
		}

		void Normalize() {
			float mag = this->Magnitude();
			this->x /= mag;
			this->y /= mag;
			this->z /= mag;
		}

		[[nodiscard]] Vector3 NormalizeValue() {
			float mag = this->Magnitude();
			return Vector3
			(
				this->x / mag,
				this->y / mag,
				this->z / mag
			);
		}

		static const Vector3 Zero;
		static const Vector3 One;

		//=========================================================================

	};

	//= HIGH SPEED FUNCTION ===================================================

	void VEC3_ADD(Vector3& result, const Vector3& va, const Vector3& vb);
	void VEC3_SUB(Vector3& result, const Vector3& va, const Vector3& vb);
	void VEC3_NORM(Vector3& result, const Vector3& source);
	[[nodiscard]] float VEC3_DOT(const Vector3& va, const Vector3& vb);
	[[nodiscard]] Vector3 VEC3_CROSS(const Vector3& va, const Vector3& vb);
	[[nodiscard]] float VEC3_DEGREE(const Vector3& va, const Vector3& vb);
	[[nodiscard]] float VEC3_RADIAN(const Vector3& va, const Vector3& vb);

	//=========================================================================
}