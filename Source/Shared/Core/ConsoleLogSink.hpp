#pragma once

#include "AbstractLogSink.hpp"
#include <App/Properties.hpp>
#include <memory>
#include <mutex>

class CLovelaceConsoleLogSink : public CLovelaceAbstractLogSink {
	std::mutex m_logMutex{};

	HANDLE GetConsoleHandle() {
		return GetStdHandle(static_cast<DWORD>(-11));
	}

	void SetAttribute(WORD wAttribute) {
		SetConsoleTextAttribute(GetConsoleHandle(), wAttribute);
	}
public:
	CLovelaceConsoleLogSink(std::shared_ptr<CLovelaceProperties> pProp);

	~CLovelaceConsoleLogSink();

	void InnerWrite(std::string szPrefix, std::string szFormatted, uint16_t u16AccentColor) override;
};

