#pragma once
#include "Figure.h"

class CSquare : public CFigure
{
public:
	CSquare() {};
	~CSquare() {};

	virtual void Draw() override;
};

typedef std::shared_ptr<CSquare> CSquarePtr;
