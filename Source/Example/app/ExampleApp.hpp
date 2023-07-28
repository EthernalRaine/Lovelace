#pragma once

#include <app.hpp>

class CExampleApp : public CLovelaceApp {
public:
	CExampleApp(HMODULE hModule) { Construct(hModule); }

	void OnAttach() override;

	void OnDetach() override;
};
