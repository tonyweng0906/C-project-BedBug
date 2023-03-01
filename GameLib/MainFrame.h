/**
 * @file MainFrame.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_MAINFRAME_H
#define PROJECT1BEDBUG_GAMELIB_MAINFRAME_H

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame
{
private:

public:

	void Initialize();
	void OnExit(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
};

#endif //PROJECT1BEDBUG_GAMELIB_MAINFRAME_H
