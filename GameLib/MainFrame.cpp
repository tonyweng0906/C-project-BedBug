/**
 * @file MainFrame.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include "MainFrame.h"
#include "GameView.h"
#include "ids.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
	Create(nullptr, wxID_ANY, L"BedBug",
		   wxDefaultPosition,  wxSize( 900,790 ));

	// Create a sizer that will lay out child windows vertically
	// one above each other
	auto sizer = new wxBoxSizer( wxVERTICAL );

	// Create the view class object as a child of MainFrame
	auto gameView = new GameView();
	gameView->Initialize(this);

	// Add it to the sizer
	sizer->Add(gameView,1, wxEXPAND | wxALL );

	// Set the sizer for this frame
	SetSizer( sizer );

	// Layout (place) the child windows.
	Layout();

	CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	auto menuBar = new wxMenuBar( );

	auto fileMenu = new wxMenu();
	auto levelMenu = new wxMenu();
	auto helpMenu = new wxMenu();
	auto viewMenu = new wxMenu();

	menuBar->Append(fileMenu, L"&File" );
	menuBar->Append(levelMenu, L"&Level");
	menuBar->Append(viewMenu, L"&View");
	menuBar->Append(helpMenu, L"&Help");

	fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
	helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");
	levelMenu->Append(IDM_ONLEVEL0, "Level 0", "Load Level 0");
	levelMenu->Append(IDM_ONLEVEL1, "Level 1", "Load Level 1");
	levelMenu->Append(IDM_ONLEVEL2, "Level 2", "Load Level 2");
	levelMenu->Append(IDM_ONLEVEL3, "Level 3", "Load Level 3");
	viewMenu->Append(IDM_ONSHRINK, "Shrink", "Shrink", wxITEM_CHECK);

	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);

	SetMenuBar( menuBar );
}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

/**
 * Help menu option handlers
 * @param event
 */
void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox(L"Welcome to Bug Squash!",
				 L"About Bug Squash",
				 wxOK,
				 this);
}

