#include "DeckBase.h"
#include "ItemDeck.h"
#include "ModifierDeck.h"
#include "MonsterDeck.h"
#include <vector>
#include <cstdlib>
#include <stdexcept>

template <typename T>


	void GenerateDeck(std::vector<int> deck)
	{
		unsigned int index = std::rand() % deck;
	}