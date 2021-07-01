#include "Random.h"

namespace Sumomo2::Math {
	float RandomRange(float min, float max)
	{
		float len = max - min;
		return static_cast<float>(rand() % 10000 / 10000.0 * len + min);
	}

	void SetSeed() {
		srand(static_cast<unsigned int>(time(0)));
	}
}