#include <iostream>
#include <math.h>

typedef unsigned char byte;

using namespace std;

int clamp(int a, int b, int val) { return max(a, min(b, val)); }


void drawline(byte data[], int width, int x1, int x2, int y){
	int H = (sizeof(data)/sizeof(*data)) / (width / 8);

	for (int h = 0; h < H; h++)
	{
		for (int b = 0; b < width; b += 8)
		{
		    int idx = h*width/8+b/8;
			if(h!=y) data[idx]=0;
			else
			{
				if     (b+7<x1 || b>x2)		data[idx]=0;
				else if(b>=x1 && b+7<=x2)	data[idx]=0xFF;

				else
				{
					// mark all bits in range
					int l = 7-clamp(0, 7, x1-b);
					int r = 7-clamp(0, 7, x2-b);

					data[idx]= (1<<l) ^ (1<<r);
				}
			}
		}
	}
}


int main()
{
	constexpr int size = 32; // 32x32 px
	byte screen[size/8*size];

	drawline(screen, size, 3, 20, 9);

	//actually draw it
	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size; ++x)
		{
			byte b = screen[y*(size/8)+x/8];
			byte mask = (1<<(7-(x%8)));

			bool biton = ( b & mask ) != 0;
			cout << (biton ? '#' : ' ');
		}
		cout << endl;
	}

	return 0;
}