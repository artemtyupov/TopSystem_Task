#pragma once
#include "Figure.h"

class CTriangle : public CFigure
{
public:
	CTriangle() {};
	~CTriangle() {};

	virtual void Draw() override;
};

typedef std::shared_ptr<CTriangle> CTrianglePtr;
