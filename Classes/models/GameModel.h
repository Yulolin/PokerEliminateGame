#pragma once
#include <vector>
#include "controllers/CardController.h"

struct GameModel {
	std::set<CardController*> handCards;
	std::stack<CardController*> stackCards;
	std::set<CardController*> playerFieldCards;
};