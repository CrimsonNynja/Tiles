#include "GameSprite.h"

void GameSprite::Update()
{
	Anim.Update();
	Collision.Update();
}
