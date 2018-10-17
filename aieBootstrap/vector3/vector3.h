#pragma once

class vector3
{
public:
	union 
	{
		struct
		{
			float x;
			float y;
			float z;
		};
		struct
		{
			float r;
			float g;
			float b;
		};
		float data[3];
	};
	vector3();
	vector3(float x, float y, float z);

	vector3 operator+(const vector3& other);

	float dot(const vector3& a, const vector3& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
    }

	

private:
};