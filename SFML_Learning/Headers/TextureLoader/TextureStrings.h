#pragma once

#include <unordered_map>
#include <string>

namespace TextureStrings {
	const std::unordered_map<std::string, std::string> texturePaths = {
		{"Player", "Assets/Player/player.png"},
		{"Bullet", "Assets/Bullet/bullet.png"},
		{"Zombie", "Assets/Zombie/Idle/skeleton-idle_0.png"}
	};
}
