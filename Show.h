#ifndef SHOW_H
#define SHOW_H

#include "Container.h"

class IRendrer
{
	virtual void Save() = 0;
};

class SlideRendrer
{
private:
	std::weak_ptr<CSlide> m_pSlide;
};

class ItemRendrer
{
private:
	std::weak_ptr<CGroupItem> m_pItems;
};

class Rendrer
{
private:
	std::unique_ptr<SlideRendrer> m_pSlideRendrer;
	std::unique_ptr<ItemRendrer> m_pItemRendrer;
};

#endif //SHOW_H