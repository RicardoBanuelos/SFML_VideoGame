#pragma once

#include <unordered_map>
#include <utility>

enum WeaponID: int {
	HANDGUN = 0,
};

// This values were calculated by trial and error lol
const std::unordered_map<WeaponID, std::pair<float, float>> weaponOffsetsMap = {
	{HANDGUN, {115, 52}}
};