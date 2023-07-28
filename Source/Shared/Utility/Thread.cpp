#include "Thread.hpp"

void CLovelaceThread::CreateThread(uint32_t ulThreadHash, std::function<void()> threadAction) {
	m_currentThreadAction = threadAction;

	const auto hThread = ::CreateThread(NULL, NULL, [](LPVOID) -> DWORD {
		m_currentThreadAction();
		return 0;
	}, NULL, NULL, NULL);

	m_threadMap[ulThreadHash] = hThread;
}

void CLovelaceThread::DestroyThread(uint32_t ulThreadHash) {

}

void CLovelaceThread::SuspendThread(uint32_t ulThreadHash) {

}

void CLovelaceThread::ResumeThread(uint32_t ulThreadHash) {

}
