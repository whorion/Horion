#pragma once
#include "Module.h"

class OptifineZoom : public IModule {
private:

public:
	OptifineZoom();
	~OptifineZoom();

	virtual bool isFlashMode() override;
	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onTick(C_GameMode* gm) override;
};
