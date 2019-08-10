#include <SFML\Graphics.hpp>

using namespace sf;

class NODE
{
public:
	Sprite FirstLayer;   // Lớp trên cùng
	Sprite LastLayer;    // Lớp cuối cùng (lớp dưới)
	int kinds;           // Xác định có phải là boom hay không
	                     // -1 là boom
	float x;
	float y;
	bool lat;            // true là đã lật
	bool flag;           // true là đã cắm
	NODE()
	{
		lat = false;
		flag = false;
	}
	void setData(Texture &texture);
};