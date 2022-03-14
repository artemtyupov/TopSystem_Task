#pragma once
#include "Figure.h"

class CCircle : public CFigure
{
public:
	CCircle() {};
	~CCircle() {};

	virtual void Draw() override;
};

typedef std::shared_ptr<CCircle> CCirclePtr;
