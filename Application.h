#ifndef APPLICATION_H
#define APPLICATION_H

#include "Container.h"
#include "Editing.h"
#include "Show.h"

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

class Application : public Application
{
public:
    Application(Application& other) = delete;
    void operator=(const Application&) = delete;
    static Application* GetInstance();

protected:
    std::unique_ptr<IDocument> m_document;
    std::shared_ptr<IEditior> m_editor;
    std::shared_ptr<IRendrer> m_rendrer;

    Application();

    static Application* m_app;
};

Application* Application::m_app = nullptr;;
Application* Application::GetInstance()
{
    if (m_app == nullptr) {
        m_app = new Application();
    }
    return m_app;
}

#endif // APPLICATION_H
