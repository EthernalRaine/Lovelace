#pragma once

#include <string>
#include <consoleapi.h>
#include <Utility/Encapsulate.hpp>

enum class LovelaceApplicationState {
	Uninitialized = -1,
	Unknown = 0,
	Initialized = 1,
	Shutdown = 2,
};

class CLovelaceProperties {
	std::string m_szAppName{};
	LovelaceApplicationState m_iAppState{};
	COLORREF m_dwConsoleColor{};
public:
	LovelaceEncapsulateProp(std::string, AppName, m_szAppName);
	LovelaceEncapsulateProp(LovelaceApplicationState, AppState, m_iAppState);
	LovelaceEncapsulateProp(COLORREF, ConsoleColor, m_dwConsoleColor);
};