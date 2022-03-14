#include "Square.h"
#include <Windows.h>
void CSquare::Draw()
{
	Rectangle(GetHDC(), 100, 100, 300, 300);
}