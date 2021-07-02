#include "Vector3.h"


namespace Sumomo2::Math {
	const Vector3 Vector3::Zero(0.0f, 0.0f, 0.0f);
	const Vector3 Vector3::One(1.0f, 1.0f, 10.f);


	void VEC3_ADD(Vector3 & result, const Vector3 & va, const Vector3 & vb)
	{
		result.x = va.x + vb.x;
		result.y = va.y + vb.y;
		result.z = va.z + vb.z;
	}

	void VEC3_SUB(Vector3 & result, const Vector3 & va, const Vector3 & vb)
	{
		result.x = va.x - vb.x;
		result.y = va.y - vb.y;
		result.z = va.z - vb.z;
	}

	void VEC3_NORM(Vector3 & result, const Vector3 & source)
	{
		float mag = source.Magnitude();
		result.x /= mag;
		result.y /= mag;
		result.z /= mag;
	}

	float VEC3_DOT(const Vector3 & va, const Vector3 & vb)
	{
		return 0.0f;
	}

	Vector3 VEC3_CROSS(const Vector3 & va, const Vector3 & vb)
	{
		return Vector3{
			va.y*vb.z - va.z*vb.y,
			va.z*vb.x - va.x*vb.z,
			va.x*vb.y - va.y*vb.x
		};
	}

	float VEC3_DEGREE(const Vector3 & va, const Vector3 & vb)
	{
		float cos_theta = VEC3_DOT(va, vb) / (va.Magnitude()*vb.Magnitude());
		return acosf(cos_theta)*Rad2Deg;
	}

	float VEC3_RADIAN(const Vector3 & va, const Vector3 & vb)
	{
		float cos_theta = VEC3_DOT(va, vb) / (va.Magnitude()*vb.Magnitude());
		return acosf(cos_theta);
	}

}
