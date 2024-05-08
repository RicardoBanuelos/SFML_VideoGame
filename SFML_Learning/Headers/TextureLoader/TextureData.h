#pragma once

#include <unordered_map>
#include <string>

namespace TextureData {

	enum TextureID {
		TID_PLAYER,
		TID_BULLET,
		TID_ZOMBIE,
	};

	const std::unordered_map<TextureID, std::string> texturePaths = {
		{TID_PLAYER, "Assets/Player/player.png"},
		{TID_BULLET, "Assets/Bullet/bullet.png"},
		{TID_ZOMBIE, "Assets/Zombie/zombie.png"},
	};
}
