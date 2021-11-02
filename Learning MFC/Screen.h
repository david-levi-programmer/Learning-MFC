#pragma once

#include <Windows.h>
#include <glm.hpp>
#include <string>
#include "glad.h"
#include "wglext.h"

class Screen
{

public:

	static Screen* Instance();

	bool Initialize(HWND wnd);

	void SetViewport(GLint x, GLint y, GLsizei width, GLsizei height);

	void ActivateContext();
	void DeactivateContext();

	void Refresh();
	void Present();
	void Shutdown();

private:

	Screen();
	Screen(const Screen&);
	Screen& operator=(const Screen&);

	GLint m_pixelFormat;

	glm::ivec4 m_viewport;
	glm::uvec2 m_resolution;

	HDC m_deviceContext;
	HGLRC m_renderContext;

	PIXELFORMATDESCRIPTOR m_pixelFormatClass;
	PFNWGLCREATECONTEXTATTRIBSARBPROC m_wglCreateContextAttribsARB;

};