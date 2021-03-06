#include "StyTools.h"
#include "StySocket.h"
#include "MainWindow.h"

//HINSTANCE ghInstance = 0;

#define WINDOW_CLASS_NAME L"ElecQuizer"			// the main window class name

int uimain(std::function<int()> run) {
	SciterSetOption(NULL, SCITER_SET_DEBUG_MODE, TRUE);

	sciter::archive::instance().open(aux::elements_of(resources)); // bind resources[] (defined in "resources.cpp") with the archive
	MainWindow *pwin = new MainWindow();
	//SciterSetOption(pwin->get_hwnd(), SCITER_ALPHA_WINDOW, TRUE);
	SciterSetOption(NULL, SCITER_SET_SCRIPT_RUNTIME_FEATURES,
		ALLOW_FILE_IO |
		ALLOW_SOCKET_IO |
		ALLOW_EVAL |
		ALLOW_SYSINFO);
	::pwin = pwin;

	// note: this:://app URL is dedicated to the sciter::archive content associated with the application
	pwin->load(WSTR("this://app/main.html"));

	pwin->expand();
	return run();
}