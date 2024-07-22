
#include "ModifierDeck.h"

#include "Modifier.h"
#include "DeckGenerator.h"

ModifierDeck::ModifierDeck()
{
	m_modifiersDatabase =
	{
		{new SimpleModifier{3}},
		{new SimpleModifier{3}},
		{new SimpleModifier{2}},
		{new SimpleModifier{2}},
		{new SimpleModifier{2}},
		{new SimpleModifier{4}},
		{new SimpleModifier{1}},
		{new SimpleModifier{1}},
		{new SimpleModifier{1}},
		{new DoubleMunchkinLevel{}},
		{new DoubleMunchkinLevel{}},
		{new HalvesMonsterLevel{Tribe::Human}},
		{new HalvesMonsterLevel{Tribe::God}}
	};
}

ModifierDeck::~ModifierDeck()
{
	//TODO: Clear memory
}

Modifier* ModifierDeck::generateModifier() const
{
	//#TODO: this call should return unique modifier every time
	//either for as long as the same game is being played
	//or unless ALL cards were generated from database to the game - in this case 
	//make ALL cards available again

	return generateRandomElement(m_modifiersDatabase);
}
