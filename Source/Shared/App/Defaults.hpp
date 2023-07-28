#pragma once

#include <Utility/Singleton.hpp>
#include <App/Properties.hpp>
#include <Core/LogProxy.hpp>

#include <functional>
#include <memory>
#include <string>

class CLovelaceDefaults : public CLovelaceSingleton<CLovelaceDefaults> {
public:
	void InitializeApplication(std::shared_ptr<CLovelaceProperties> pProp, std::function<void()> fnBoilerPlate);
	void ShutdownApplication(std::shared_ptr<CLovelaceProperties> pProp, std::function<void()> fnBoilerPlate);
};