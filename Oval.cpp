#include "Oval.h"
#include <Windows.h>
void COval::Draw()
{
	Ellipse(GetHDC(), 100, 100, 300, 500);
}