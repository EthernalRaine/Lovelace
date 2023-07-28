#pragma once

#include <Utility/Singleton.hpp>
#include "AbstractLogSink.hpp"
#include <vector>
#include <string>
#include <format>
#include <memory>
#include <Windows.h>
#include <consoleapi.h>

class CLovelaceLogProxy : public CLovelaceSingleton<CLovelaceLogProxy> {
public:
	CLovelaceLogProxy() = default;

	template <typename... Args>
	void Write(std::string szPrefix, std::string szData, Args&&... args) {
		std::string szFmtArg = std::vformat(szData, std::make_format_args(args...));
		AbstractWrite(szPrefix, szFmtArg, FOREGROUND_BLUE);
	}

	template <typename... Args>
	void WriteWarning(std::string szData, Args&&... args) {
		std::string szFmtArg = std::vformat(szData, std::make_format_args(args...));
		AbstractWrite("Warning", szFmtArg, FOREGROUND_RED | FOREGROUND_GREEN);
	}

	template <typename... Args>
	void WriteError(std::string szData, Args&&... args) {
		std::string szFmtArg = std::vformat(szData, std::make_format_args(args...));
		AbstractWrite("Error", szFmtArg, FOREGROUND_RED);
	}

	void AddSink(std::shared_ptr<CLovelaceAbstractLogSink> pSink);
	void CloseAllSinks();
private:
	std::vector<std::shared_ptr<CLovelaceAbstractLogSink>> m_logSinks{};

	void AbstractWrite(std::string szPrefix, std::string szFormatted, uint16_t u16AccentColor);
};