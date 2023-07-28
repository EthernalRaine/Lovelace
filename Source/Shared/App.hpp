#pragma once

#define WIN32_LEAN_AND_MEAN  
#include <Windows.h>

#include <memory>
#include <mutex>

#include "App/Properties.hpp"

class CLovelaceApp {
public:
	HMODULE m_hAppBaseAddress;

	void Construct(HMODULE hAppBaseAddress);

	void Initialize(DWORD dwCallReason);

	virtual void OnAttach() = 0;
	virtual void OnDetach() = 0;

	std::shared_ptr<CLovelaceProperties> m_pApplicationProperties;
};

#define LovelaceImplementApp(_hModule, _dwCallReason, _CApp) \
	{ \
		static auto pLovelaceApp = std::make_unique<_CApp>(_hModule); \
		pLovelaceApp->Initialize(_dwCallReason); \
	} 