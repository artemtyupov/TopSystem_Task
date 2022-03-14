#include "Triangle.h"
#include <Windows.h>
void CTriangle::Draw()
{
	POINT My_Massiv[3];
	My_Massiv[0].x = 245; My_Massiv[0].y = 110;
	My_Massiv[1].x = 125; My_Massiv[1].y = 250;
	My_Massiv[2].x = 375; My_Massiv[2].y = 250;
	Polygon(GetHDC(), My_Massiv, 3);
}