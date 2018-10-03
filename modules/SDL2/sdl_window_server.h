#pragma once

#include "servers/window_server.h"

class SDLWindowServer : public WindowServer {
private:
	SDL_Window *window;

public:
	bool running;

public:
	SDLWindowServer();
	virtual bool init();
	virtual void terminate();
	virtual bool instanceWindow(const char *p_title, int p_width, int p_height);
	virtual void freeWindow();
	virtual bool isDrawable() const;
	virtual void set_drawable(bool p_state);
	virtual void getWindowSize(int *r_width, int *r_height);
	virtual void appendRequiredExtensions(vector<const char *> &r_extensions);
	virtual bool createSurface(VkInstance p_instance, VkSurfaceKHR *r_surface);
};