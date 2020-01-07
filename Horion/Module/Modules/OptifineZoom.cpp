#include "OptifineZoom.h"
#include <ModuleManager.h>

OptifineZoom::OptifineZoom() : IModule('H', Category::VISUAL, "Break multiple blocks at once") {

}

OptifineZoom::~OptifineZoom() {
}

const char* OptifineZoom::getModuleName() {
	return ("OptifineZoom");
}

bool OptifineZoom::isFlashMode() {
	return true;
}

void OptifineZoom::onTick(C_GameMode*) {
	static OptifineZoom* checkIfOn = moduleMgr->getModule<OptifineZoom>();
	vec2_t fov = *g_Data.getClientInstance->getFov();
	vec2_t store = fov;
	uintptr_t _this = reinterpret_cast<uintptr_t>(this);

	if (checkIfOn->isEnabled) {
		fov.x = *reinterpret_cast<float*>(_this + 0x100);
		fov.y = *reinterpret_cast<float*>(_this + 0x102);
	} else if (checkIfOn == nullptr) {
		checkIfOn = moduleMgr->getModule<OptifineZoom>();

		fov.x = *reinterpret_cast<float*>(_this + 0x600);
		fov.y = *reinterpret_cast<float*>(_this + 0x614);
	}
}