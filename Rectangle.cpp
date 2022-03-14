#include "Rectangle.h"
#include <Windows.h>
void CRectangle::Draw()
{
	Rectangle(GetHDC(), 100, 100, 200, 500);
}