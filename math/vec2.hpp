#pragma once

struct vec2f {
	float x;
	float y;
};

struct vec2i {
	int x;
	int y;

	bool operator==(const vec2i& other) const {
		return x == other.x && y == other.y;
	};

	vec2i operator+(const vec2i& other) const {
		return { x + other.x, y + other.y };
	};
};