#pragma once

#include <vector>
#include <string>

namespace TextureStrings {
	const std::vector<std::string> names = {
		"background",
		"player",
		"enemy",
		"bullet"
	};

	const std::vector<std::string> paths = {
		"assets/Background/hjm-wasteland.png",
		"assets/Player/Textures/spritesheet.png",
		"assets/Skeleton/Textures/spritesheet.png",
		"assets/bullets.png"
	};

	const int SIZE = names.size();
}
