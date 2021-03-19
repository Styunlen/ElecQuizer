#pragma once
#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H
#include "sciter-x-window.hpp"
#include "resources.cpp"

/*****************************
		Pre Declaration
*****************************/
class MainWindow;

/*****************************
 Global Variables Declaration
*****************************/
extern MainWindow* pwin;

/*****************************
		Class Declaration
*****************************/
class MainWindow : public sciter::window {
public:
	BEGIN_FUNCTION_MAP

	END_FUNCTION_MAP
	MainWindow() : window(SW_TITLEBAR | SW_CONTROLS | SW_MAIN | SW_ENABLE_DEBUG) {}
};

#endif