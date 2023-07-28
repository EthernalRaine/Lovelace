#include "FileLogSink.hpp"

#include <Utility/Filesystem.hpp>
#include <filesystem>

CLovelaceFileLogSink::CLovelaceFileLogSink(std::shared_ptr<CLovelaceProperties> pProp) {
	std::stringstream szPath = CLovelaceFilesystem::Get()->GetBaseFolder() << "\\" << pProp->GetAppName();
	std::filesystem::create_directory(szPath.str());
	szPath << "Log.txt";

	if (CLovelaceFilesystem::Get()->DoesFileExist(szPath.str()))
		std::filesystem::remove(szPath.str());

	m_outputStream.open(szPath.str(), std::ios::out | std::ios::app);
}

CLovelaceFileLogSink::~CLovelaceFileLogSink() {
	m_outputStream.close();
}

void CLovelaceFileLogSink::InnerWrite(std::string szPrefix, std::string szFormatted, uint16_t u16AccentColor) {
	m_logMutex.lock();
	struct tm localTime {};
	time_t currentTime = 0;
	char szTimestamp[30];

	time(&currentTime);
	localtime_s(&localTime, &currentTime);
	sprintf_s(szTimestamp, "[%02d:%02d:%02d]", localTime.tm_hour, localTime.tm_min, localTime.tm_sec);

	m_outputStream << "[" << szTimestamp << " | " << szPrefix << "] " << szFormatted << "\n";

	m_logMutex.unlock();
}