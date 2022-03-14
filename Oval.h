#pragma once
#include "Figure.h"

class COval : public CFigure
{
public:
	COval() {};
	~COval() {};

	virtual void Draw() override;
};

typedef std::shared_ptr<COval> COvalPtr;
