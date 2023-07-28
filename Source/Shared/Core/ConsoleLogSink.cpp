#include "ConsoleLogSink.hpp"

#define FOREGROUND_WHITE FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN

CLovelaceConsoleLogSink::CLovelaceConsoleLogSink(std::shared_ptr<CLovelaceProperties> pProp) {
	AllocConsole();
	freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	SetConsoleTitleA(pProp->GetAppName().c_str());

	CONSOLE_SCREEN_BUFFER_INFOEX csbiInfo{};
	csbiInfo.cbSize = sizeof(csbiInfo);
	GetConsoleScreenBufferInfoEx(GetConsoleHandle(), &csbiInfo);
	csbiInfo.ColorTable[1] = pProp->GetConsoleColor();
	SetConsoleScreenBufferInfoEx(GetConsoleHandle(), &csbiInfo);
}

CLovelaceConsoleLogSink::~CLovelaceConsoleLogSink() {
	fclose(stdout);
	FreeConsole();
}

void CLovelaceConsoleLogSink::InnerWrite(std::string szPrefix, std::string szFormatted, uint16_t u16AccentColor) {
	m_logMutex.lock();
	struct tm localTime {};
	time_t currentTime = 0;

	time(&currentTime);
	localtime_s(&localTime, &currentTime);

	SetAttribute(FOREGROUND_WHITE);
	printf("[");
	SetAttribute(u16AccentColor);
	printf("%02d:%02d:%02d", localTime.tm_hour, localTime.tm_min, localTime.tm_sec);
	SetAttribute(FOREGROUND_WHITE);
	printf(" | ");
	SetAttribute(u16AccentColor);
	printf(szPrefix.c_str());
	SetAttribute(FOREGROUND_WHITE);
	printf("] ");
	SetAttribute(u16AccentColor);

	printf(szFormatted.c_str());
	printf("\n");
	m_logMutex.unlock();
}