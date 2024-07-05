#include "Runaway.h"
#include "Munchkin.h"
#include "ModifierDeck.h"
#include "DeckGenerator.h"
#include <iostream>

void Runaway_LevelDowngrade::apply(Munchkin* munchkin)
{
	munchkin->updateLevelBy(-m_levelToDowngrade);
}

void Runaway_LevelDowngradeIf::apply(Munchkin* munchkin)
{
	if (munchkin->getLevel() >= m_minimalMunchkinLevelToApply)
	{
		Runaway_LevelDowngrade::apply(munchkin);
	}
}

void Runaway_ModifierFromHandRemoval::apply(Munchkin* munchkin)
{
	munchkin->removeModifierFromHand(m_RandomModifierElement);
}