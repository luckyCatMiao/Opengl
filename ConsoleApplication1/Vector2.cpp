#include "Vector2.h"
#include <cmath>
Vector2& distance(Vector2& v1, Vector2& v2) {

	Vector2* newV = new Vector2(fabs(v2.x - v1.x), fabs(v2.y - v1.x));
	return *newV;
}