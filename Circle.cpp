#include "Circle.h"
#include <Windows.h>
void CCircle::Draw()
{
	Ellipse(GetHDC(), 100, 100, 300, 300);
}