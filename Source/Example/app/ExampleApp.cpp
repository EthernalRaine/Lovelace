#include "ExampleApp.hpp"

#include <App/Defaults.hpp>

void CExampleApp::OnAttach() {
	m_pApplicationProperties->SetAppName("ExampleApp");

	CLovelaceDefaults::Get()->InitializeApplication(m_pApplicationProperties, []() {

	});
}

void CExampleApp::OnDetach() {

	CLovelaceDefaults::Get()->ShutdownApplication(m_pApplicationProperties, []() {

	});
}