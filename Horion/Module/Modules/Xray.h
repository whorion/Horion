#pragma once
#include "Module.h"
class Xray :
	public IModule
{
public:
	Xray();
	~Xray();

	std::vector<std::string> blocks = {"diamond ore", "gold ore", "iron ore", "coal ore", "redstone ore", "emerald ore", "lapis lazuli ore", "lava", "water"};

	// Inherited via IModule
	virtual const char* getModuleName() override;
};

