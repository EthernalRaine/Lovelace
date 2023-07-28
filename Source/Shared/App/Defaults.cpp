#include "Defaults.hpp"

#include <Core/FileLogSink.hpp>
#include <Core/ConsoleLogSink.hpp>

void CLovelaceDefaults::InitializeApplication(std::shared_ptr<CLovelaceProperties> pProp, std::function<void()> fnBoilerPlate) {
	pProp->SetConsoleColor(RGB(31, 128, 196));

	CLovelaceLogProxy::Get()->AddSink(std::make_shared<CLovelaceConsoleLogSink>());
	CLovelaceLogProxy::Get()->AddSink(std::make_shared<CLovelaceFileLogSink>());
	
	{
		fnBoilerPlate();
	}

	pProp->SetAppState(LovelaceApplicationState::Initialized);
}

void CLovelaceDefaults::ShutdownApplication(std::shared_ptr<CLovelaceProperties> pProp, std::function<void()> fnBoilerPlate) {
	{
		fnBoilerPlate();
	}

	pProp->SetAppState(LovelaceApplicationState::Shutdown);
}