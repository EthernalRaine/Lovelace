// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include "app/ExampleApp.hpp"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwCallReason, LPVOID /*lpReserved*/) {
   
	LovelaceImplementApp(hModule, dwCallReason, CExampleApp);

	return TRUE;
}