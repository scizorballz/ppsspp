// NOTE: Apologies for the quality of this code, this is really from pre-opensource Dolphin - that is, 2003.

#ifndef _DISASM_H
#define _DISASM_H

#include "Windows/W32Util/DialogManager.h"
#include "Windows/Debugger/CtrlDisasmView.h"
#include "Windows/Debugger/Debugger_Lists.h"
#include "Windows/Debugger/CPURegsInterface.h"
#include "Globals.h"
#include "Core/CPU.h"
#include "Core/MIPS/MIPSDebugInterface.h"
#include "Core/Debugger/Breakpoints.h"
#include <vector>

#include "Common/CommonWindows.h"

class CDisasm : public Dialog
{
private:
	RECT defaultRect;
	RECT defaultBreakpointRect;
	RECT regRect;
	RECT disRect;
	RECT breakpointRect;

	DebugInterface *cpu;
	u64 lastTicks;

	HWND statusBarWnd;
	CtrlBreakpointList* breakpointList;
	CtrlThreadList* threadList;
	std::vector<BreakPoint> displayedBreakPoints_;
	std::vector<MemCheck> displayedMemChecks_;

	BOOL DlgProc(UINT message, WPARAM wParam, LPARAM lParam);
	void UpdateSize(WORD width, WORD height);
	void SavePosition();
	void updateThreadLabel(bool clear);
public:
	int index; //helper 

	CDisasm(HINSTANCE _hInstance, HWND _hParent, DebugInterface *cpu);
	~CDisasm();
	//
	// --- tools ---
	//
	
	virtual void Update()
	{
		UpdateDialog(true);
		breakpointList->update();
	};
	void UpdateDialog(bool _bComplete = false);
	// SetDebugMode 
	void SetDebugMode(bool _bDebug);
	// show dialog
	void Goto(u32 addr);
	void NotifyMapLoaded();
};

#endif