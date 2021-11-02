#include "Screen.h"


Screen* Screen::Instance()
{
	static Screen* screen = new Screen;
	return screen;
}

Screen::Screen()
{
	m_pixelFormat = 0;
	m_pixelFormatClass = { 0 };

	m_viewport = glm::vec4(0);
	m_resolution = glm::uvec2(0);

	m_deviceContext = nullptr;
	m_renderContext = nullptr;
	m_wglCreateContextAttribsARB = nullptr;
}

void Screen::SetViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
	glViewport(x, y, width, height);
	m_viewport = glm::vec4(x, y, width, height);
}

bool Screen::Initialize(HWND wnd)
{
	m_deviceContext = GetDC(wnd);


	m_pixelFormatClass.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	m_pixelFormatClass.nVersion = 1;
	m_pixelFormatClass.dwFlags = PFD_SUPPORT_OPENGL |
		PFD_DRAW_TO_WINDOW |
		PFD_DOUBLEBUFFER;
	m_pixelFormatClass.iPixelType = PFD_TYPE_RGBA;
	m_pixelFormatClass.cDepthBits = 32;
	m_pixelFormatClass.cStencilBits = 32;

	m_pixelFormat = ChoosePixelFormat(m_deviceContext, &m_pixelFormatClass);
	SetPixelFormat(m_deviceContext, m_pixelFormat, &m_pixelFormatClass);

	HGLRC temporaryContext = wglCreateContext(m_deviceContext);

	wglMakeCurrent(m_deviceContext, temporaryContext);

	m_wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)
		wglGetProcAddress("wglCreateContextAttribsARB");

	if (!m_wglCreateContextAttribsARB)
	{
		return false;
	}

	wglDeleteContext(temporaryContext);

	int profile = WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB;
	
	int attribs[] = { WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
					   WGL_CONTEXT_MINOR_VERSION_ARB, 5,
					   WGL_CONTEXT_PROFILE_MASK_ARB, profile, 0 };

	m_renderContext = m_wglCreateContextAttribsARB(m_deviceContext, NULL, attribs);

	if (!m_renderContext)
	{
		
	}

    wglMakeCurrent(m_deviceContext, m_renderContext);

	if (!gladLoadGL())
	{

	}

    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    return true;
}

void Screen::ActivateContext()
{
	wglMakeCurrent(m_deviceContext, m_renderContext);
}

void Screen::DeactivateContext()
{
	wglMakeCurrent(nullptr, nullptr);
}

void Screen::Refresh()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Screen::Present()
{
	SwapBuffers(m_deviceContext);
}

void Screen::Shutdown()
{
	wglMakeCurrent(m_deviceContext, nullptr);
	wglDeleteContext(m_renderContext);
}