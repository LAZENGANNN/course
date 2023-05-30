#pragma once
#pragma once
#include "settings.h"

class EnemyObj {
public:
	EnemyObj() {  }

	virtual void spawn() = 0;


protected:
	sf::Clock timer;
	int speedRange1 = 3;
	int speedRange2 = 0;
};