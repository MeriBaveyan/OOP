//#include <utility>
#include <memory>
#include <stack> // editing

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

///////////////////////////////////////////////
class IApplication
{
public:
	virtual void ContainDocument() = 0;
};

class CApplication :public IDocument
{
public:
	virtual IDocument* GetDocument() = 0;

private:
	std::unique_ptr<CDocument> m_pDocument;
	std::shared_ptr<CEditor> m_pEditor;
};
///////////////////////////////////////////////

using file_t = int;// change to file
using initialCommand_t = int; // get_line from file
using command_t = int; // change to command

class CCommandHistory
{
public:
	virtual command_t GetCommandHistory() = 0;

private:
	command_t m_command;
};

class CommandHandler
{
	//Fetch()
	//Decode
	//Execute
};

///////////////////////////////////

//////////EDITING//////////////////////////////
using action_t = int; // change int to action
using actionType_t = std::pair<action_t, int>; // change int to type
 
class IAction
{
public:
	virtual void Do(ISlideCollection*) = 0;
};

class CAction :public IAction
{
public:
	virtual actionType_t GetAction() = 0;

private:
	action_t m_action;
	std::unique_ptr<CGroupItem> m_pItems;
	std::unique_ptr<CSlide> m_slide;
};

class CUndoRedo
{
public:
	virtual action_t GetUndoAction() = 0;
	virtual action_t GetRedoAction() = 0;

private:
	std::unique_ptr<CAction> m_pAction;
	std::stack<action_t> m_undoStack;
	std::stack<action_t> m_redoStack;
};

class IEditior
{
public:
	virtual void Edit() = 0;
};

class CEditor :public IEditior
{
public:
	///////////////
private:
	std::weak_ptr<CDocument> m_pDocument;
	std::weak_ptr<ISlideCollection> m_pSlideCollection;
};

///////////////////////

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

////////////

class IShape
{
public:
	//virtual void Drow(std::shared_ptr<CSingleItem>, std::shared_ptr<IPinter>);
};