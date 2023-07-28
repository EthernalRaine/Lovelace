#pragma once

#include <map>
#include <functional>
#include <Windows.h>

#include "Singleton.hpp"

class CLovelaceThread : public CLovelaceSingleton<CLovelaceThread> {
	std::map<uint32_t, HANDLE> m_threadMap{};
	static std::function<void()> m_currentThreadAction{};
public:
	void CreateThread(uint32_t ulThreadHash, std::function<void()> threadAction);
	void DestroyThread(uint32_t ulThreadHash);
	void SuspendThread(uint32_t ulThreadHash);
	void ResumeThread(uint32_t ulThreadHash);
};