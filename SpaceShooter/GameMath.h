#pragma once

namespace GameMath {

	class Vector2 {
	public:
		float x;
		float y;

		Vector2() {
			x = 0.0f;
			y = 0.0f;
		}

		Vector2(float _x, float _y) {
			x = _x;
			y = _y;
		}

		Vector2 operator+(const Vector2& vector) {
			
			return Vector2(x + vector.x,  y + vector.y);
		}
	};
}
