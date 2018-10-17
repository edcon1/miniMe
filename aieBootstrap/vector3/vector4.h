#pragma once
class vector4
{
public:
	union
	{
		struct 
		{
			float x;
			float y;
			float z;
			float w;
		};
		float data[4];

	};
	vector4();
	vector4(float x, float y, float z, float w);


private:


};