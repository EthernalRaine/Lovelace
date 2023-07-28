#include "app.hpp"

#include "Utility/Thread.hpp"

void CLovelaceApp::Construct(HMODULE hAppBaseAddress) {
	m_hAppBaseAddress = hAppBaseAddress;

	m_pApplicationProperties = std::make_shared<CLovelaceProperties>();
	m_pApplicationProperties->SetAppState(LovelaceApplicationState::Uninitialized);
}

void CLovelaceApp::Initialize(DWORD dwCallReason) {
	if (dwCallReason == DLL_PROCESS_ATTACH)
		CLovelaceThread::Get()->CreateThread(0, [this] { OnAttach(); });
	else if (dwCallReason == DLL_PROCESS_DETACH)
		OnDetach();
}