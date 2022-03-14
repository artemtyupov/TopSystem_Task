#pragma once
#include <windows.h>
#include <memory>
class CFigure
{
public:
	CFigure() {};
	~CFigure() {};

	void SetHDC(HDC hdc) { m_hdc = hdc; }
	HDC GetHDC() { return m_hdc; }

	virtual void Draw() {};
private:
	HDC m_hdc;
};

typedef std::shared_ptr<CFigure> CFigurePtr;

