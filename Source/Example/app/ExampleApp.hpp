#pragma once

#include <app.hpp>

class CExampleApp : public CLovelaceApp {
public:
	void OnAttach() override;

	void OnDetach() override;
};
