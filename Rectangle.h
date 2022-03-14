#pragma once
#include "Figure.h"

class CRectangle : public CFigure
{
public:
	CRectangle() {};
	~CRectangle() {};

	virtual void Draw() override;
};

typedef std::shared_ptr<CRectangle> CRectanglePtr;
