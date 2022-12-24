#include "Container.h"

point_t SingleItem::GetCenterCoordinate()
{

}

dimention_t SingleItem::GetDimension()
{

}

angle_t SingleItem::GetAngle() 
{

}

void SingleItem::SetCenterCoordinate(const point_t&)
{

}

void SingleItem::SetDimension(const dimention_t&)
{

}

void SingleItem::SetAngle(const angle_t&)
{

}

shape_t SingleItem::GetShape()
{

}

void SingleItem::SetShape(const shape_t&)
{

}


point_t GroupItem::GetCenterCoordinate() {}
dimention_t GroupItem::GetDimension() {}
angle_t GroupItem::GetAngle() {}

void GroupItem::SetCenterCoordinate(const point_t&) {}
void GroupItem::SetDimension(const dimention_t&) {}
void GroupItem::SetAngle(const angle_t&) {}

IItemCollection* GroupItem::GetCollection() {}

void Slide::Add(IItemCollection*) {}
void Slide::Remove(IItemCollection*) {}
void Slide::GetCount(IItemCollection*) {}
IItemCollection* Slide::GetCollection() {}


void Presentaion::Add(ISlide*) {}
void Presentaion::Remove(ISlide*) {}
void Presentaion::GetCount(ISlide*) {}



void Document::SavePresentationContent() {}
void Document::SavePresentationCreationDate() {}
void Document::SavePresentationUpdateDate() {}
void Document::SavePresentationMakerUsername() {}
void Document::SavePresentationUpdaterUsername() {}

IPresentation* Document::GetPresentation() {}
