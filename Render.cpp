#include "Render.h"

void CRender::DrawFigure(CFigurePtr spObj)
{
	if (!spObj)
		return;

	spObj->Draw();
}
