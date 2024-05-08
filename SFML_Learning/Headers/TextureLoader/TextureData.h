#pragma once

#include <unordered_map>
#include <string>

namespace TextureData {

	enum TextureID {
		TID_PLAYER_IDLE,
		TID_BULLET,
		TID_ZOMBIE_WALK_SHEET,
		TID_ZOMBIE_ATTACK_SHEET,
	};

	const std::unordered_map<TextureID, std::string> texturePaths = {
		{TID_PLAYER_IDLE, "Assets/Player/player.png"},
		{TID_BULLET, "Assets/Bullet/bullet.png"},
		{TID_ZOMBIE_WALK_SHEET, "Assets/Zombie/walk.png"},
		{TID_ZOMBIE_ATTACK_SHEET, "Assets/Zombie/attack.png"},
	};
}
