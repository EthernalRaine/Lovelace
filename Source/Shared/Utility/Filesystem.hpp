#pragma once

#include <string>
#include <sstream>
#include "Singleton.hpp"

class CLovelaceFilesystem : public CLovelaceSingleton<CLovelaceFilesystem> {
public:
	std::stringstream GetBaseFolder();
	bool DoesFileExist(std::string szFilePath);
};

