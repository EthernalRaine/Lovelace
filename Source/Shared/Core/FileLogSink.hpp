#pragma once

#include "AbstractLogSink.hpp"
#include <App/Properties.hpp>
#include <memory>
#include <mutex>
#include <fstream>

class CLovelaceFileLogSink : public CLovelaceAbstractLogSink {
public:
	CLovelaceFileLogSink(std::shared_ptr<CLovelaceProperties> pProp);
	~CLovelaceFileLogSink();

	void InnerWrite(std::string szPrefix, std::string szFormatted, uint16_t u16AccentColor) override;
private:
	std::mutex m_logMutex{};
	std::ofstream m_outputStream{};

};