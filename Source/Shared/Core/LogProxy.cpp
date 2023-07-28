#include "LogProxy.hpp"

void CLovelaceLogProxy::AddSink(std::shared_ptr<CLovelaceAbstractLogSink> pSink) {
	m_logSinks.push_back(pSink);
}

void CLovelaceLogProxy::CloseAllSinks() {
	for (auto sink : m_logSinks) {
		sink.reset();
	}
}

void CLovelaceLogProxy::AbstractWrite(std::string szPrefix, std::string szFormatted) {
	for (auto sink : m_logSinks) {
		sink->InnerWrite(szPrefix, szFormatted);
	}
}