#ifndef EDITING_H
#define EDITING_H

#include "Container.h"
#include <stack> // editing

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

class IEditor
{
public:
	virtual void Edit() = 0;
};

class CEditor :public IEditor
{
public:
	///////////////
private:
	std::weak_ptr<CDocument> m_pDocument;
	std::weak_ptr<ISlideCollection> m_pSlideCollection;
};

#endif //EDITING_H