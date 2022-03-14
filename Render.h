#pragma once
#include "Figure.h"

class CRender
{
public:
	CRender() {};
	~CRender() {};

	void DrawFigure(CFigurePtr spObj);
};

typedef std::shared_ptr<CRender> CRenderPtr;

