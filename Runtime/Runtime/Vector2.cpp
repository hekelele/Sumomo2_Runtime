#include "Vector2.h"


namespace Sumomo2::Math {
	const Vector2 Vector2::Zero(0.0f, 0.0f);
	const Vector2 Vector2::One(1.0f, 1.0f);

	void VEC2_ADD(Vector2& result, const Vector2& va, const Vector2& vb)
	{
		result.x = va.x + vb.x;
		result.y = va.y + vb.y;
	}

	void VEC2_SUB(Vector2 & result, const Vector2 & va, const Vector2 & vb)
	{
		result.x = va.x - vb.x;
		result.y = va.y - vb.y;
	}

	void VEC2_NORM(Vector2 & result, const Vector2 & source)
	{
		float mag = source.Magnitude();
		result.x /= mag;
		result.y /= mag;
	}

	float VEC2_DOT(const Vector2 & va, const Vector2 & vb)
	{
		return va.x*vb.x + va.y*vb.y;
	}

	float VEC2_CROSS_1(const Vector2 & va, const Vector2 & vb)
	{
		return va.x * vb.y - va.x * vb.y;
	}

	Vector2 VEC2_CROSS_2(const Vector2 & v)
	{
		return Vector2{
			v.y,
			-v.x
		};
	}

	float VEC2_DEGREE(const Vector2 & va, const Vector2 & vb)
	{
		float cos_theta = VEC2_DOT(va, vb) / (va.Magnitude()*vb.Magnitude());
		return acosf(cos_theta)*Rad2Deg;
	}

	float VEC2_RADIAN(const Vector2 & va, const Vector2 & vb)
	{
		float cos_theta = VEC2_DOT(va, vb) / (va.Magnitude()*vb.Magnitude());
		return acosf(cos_theta);
	}
}