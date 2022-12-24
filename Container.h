#ifndef CONTAINER_H
#define CONTAINER_H

#include <memory>

using point_t = std::pair<float, float>;
using dimention_t = std::pair<float, float>;
using angle_t = float;
using shape_t = int; // shape 
using thickness_t = float;
using color_t = int; //change int to color

enum ColorType
{
	Line, Fill, Gradient1, Gradient2
};

class IItem
{
public:
	virtual point_t GetCenterCoordinate() = 0;
	virtual dimention_t GetDimension() = 0;
	virtual angle_t GetAngle() = 0;

	virtual void SetCenterCoordinate(const point_t&) = 0;
	virtual void SetDimension(const dimention_t&) = 0;
	virtual void SetAngle(const angle_t&) = 0;
};

class IVisualAttributes
{
public:
	//FillStyle;

	virtual thickness_t GetLineThickness() = 0;
	virtual color_t GetLineColor(enum ColorType) = 0;
	virtual color_t GetFillColor() = 0;

	virtual void SetLineThickness(const thickness_t&) = 0;
	virtual void SetLineColor(const color_t&) = 0;
	virtual void SetFillColor(const color_t&) = 0;
};

class IItemCollection
{
public:
	virtual void Add(IItem*) = 0;
	virtual void Remove(IItem*) = 0;
	virtual void GetCount(IItem*) = 0;
	virtual IItem* At() = 0;
	//virtual pos 
};

class ISlideCollection
{
public:
	virtual void Add(ISlide*) = 0;
	virtual void Remove(ISlide*) = 0;
	virtual void GetCount(ISlide*) = 0;
	virtual ISlide* At() = 0;
	//virtual pos 
};

class ISlide :public IItemCollection
{
public:
	virtual void Add(IItemCollection*) = 0;
	virtual void Remove(IItemCollection*) = 0;
	virtual void GetCount(IItemCollection*) = 0;
	//virtual IItemCollection* At() = 0;
	//virtual pos 
};

class IPresentation :public ISlide
{
public:
	virtual void Add(ISlide*) = 0;
	virtual void Remove(ISlide*) = 0;
	virtual void GetCount(ISlide*) = 0;
	//virtual ISlide* At() = 0;
	//virtual pos 
};

class IDocument
{
public:
	virtual void SavePresentationContent() = 0;
	virtual void SavePresentationCreationDate() = 0;
	virtual void SavePresentationUpdateDate() = 0;
	virtual void SavePresentationMakerUsername() = 0;
	virtual void SavePresentationUpdaterUsername() = 0;
};

class CSingleItem : public IItem, IVisualAttributes
{
public:
	virtual shape_t GetShape() = 0;
	virtual IVisualAttributes GetAttributes() = 0;

	virtual void SetShape(const shape_t&) = 0;
	virtual IVisualAttributes SetAttributes() = 0;

private:
	point_t m_center;
	dimention_t m_dimension;
	angle_t m_angle;
	shape_t m_shape;
	//CAppearance m_appearance;
};

class CGroupItem : public IItem
{
public:
	virtual IItemCollection* GetCollection() = 0;

private:
	std::shared_ptr<CSingleItem> m_pSingleItem;
};

class CSlide :public ISlide
{
public:
	virtual IItemCollection* GetCollection() = 0;

private:
	std::shared_ptr<CGroupItem> m_pItems;
};

class CPresentation :public IPresentation
{
public:
	virtual ISlideCollection* GetCollection() = 0;

private:
	std::shared_ptr<CSlide> m_pSlides;
};

class CDocument :public IDocument
{
public:
	virtual IPresentation* GetPresentation() = 0;

private:
	std::unique_ptr<CPresentation> m_pPresentation;
};

class SingleItem : public CSingleItem
{
	point_t GetCenterCoordinate() override;
	dimention_t GetDimension() override;
	angle_t GetAngle() override;

	void SetCenterCoordinate(const point_t&) override;
	void SetDimension(const dimention_t&) override;
	void SetAngle(const angle_t&) override;

	shape_t GetShape() override;
	//IVisualAttributes GetAttributes() override;

	void SetShape(const shape_t&) override;
	//IVisualAttributes SetAttributes() override;
};

class GroupItem : CGroupItem
{
	point_t GetCenterCoordinate() override;
	dimention_t GetDimension() override;
	angle_t GetAngle() override;

	void SetCenterCoordinate(const point_t&) override;
	void SetDimension(const dimention_t&) override;
	void SetAngle(const angle_t&) override;

	IItemCollection* GetCollection() override;
};

class Slide : public CSlide
{
	void Add(IItemCollection*) override;
	void Remove(IItemCollection*) override;
	void GetCount(IItemCollection*) override;
	IItemCollection* GetCollection() override;
};

class Presentaion : public CPresentation
{
	void Add(ISlide*) override;
	void Remove(ISlide*) override;
	void GetCount(ISlide*) override;
};

class Document : public CDocument
{
	void SavePresentationContent() override;
	void SavePresentationCreationDate() override;
	void SavePresentationUpdateDate() override;
	void SavePresentationMakerUsername() override;
	void SavePresentationUpdaterUsername() override;

	IPresentation* GetPresentation() override;
};
#endif //CONTAINER_H