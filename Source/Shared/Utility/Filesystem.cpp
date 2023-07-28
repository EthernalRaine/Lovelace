#include "Filesystem.hpp"

#include <shlobj_core.h>

std::stringstream CLovelaceFilesystem::GetBaseFolder() {
	char path[MAX_PATH];
	SHGetFolderPathA(NULL, CSIDL_MYDOCUMENTS, NULL, NULL, path);
	
	return std::stringstream(std::string(path));
}

bool CLovelaceFilesystem::DoesFileExist(std::string szFilePath) {
	struct stat buffer;
	return (stat(szFilePath.c_str(), &buffer) == 0);
}