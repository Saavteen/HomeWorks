#include "Munchkin.h"
#include "Item.h"
#include "Modifier.h"
#include <iostream>

void Munchkin::updateLevelBy(int levels)
{
    if (m_level + levels <= 0)
    {
        m_level = 1;
    }
    else
    {
        m_level += levels;
    }

}

void Munchkin::addItem(Item* item)
{
    m_items.push_back(item);
}

void Munchkin::addItems(const std::vector<Item*>& items)
{
    m_items = items;
}

const std::vector<Item*>& Munchkin::getItems() const
{
    return m_items;
}

void Munchkin::removeModifierFromHand(int idx) 
{
    if (idx >= m_modifiers.size() || idx < 0)
    {
        return ;
    }

    m_modifiers.erase(m_modifiers.begin() + idx);
    std::cout << "Modifier at index " << idx << " removed." << std::endl;
}

void Munchkin::removeItemEquipped(int idx)
{
    if (idx >= m_items.size() || idx < 0)
    {
        return;
    }
    m_items.erase(m_items.begin() + idx);
    std::cout << "Item at index " << idx << " removed." << std::endl;
}

Modifier* Munchkin::popModifier(int idx)
{
    if (idx >= m_modifiers.size() || idx < 0)
    {
        return nullptr;
    }

    Modifier* modifier = m_modifiers[idx];
    m_modifiers.erase(m_modifiers.begin() + idx);
    return modifier;
}

void Munchkin::removeBestItemEquipped()
{
    if (m_items.empty())
    {
        return;
    }
    auto bestItemIter = std::max_element(m_items.begin(), m_items.end(),
        [](Item* a, Item* b)
        {
            return a->getBasePower() < b->getBasePower();
        }
    );
    if (bestItemIter != m_items.end())
    {
        unsigned int idx = std::distance(m_items.begin(), bestItemIter);
        std::cout << "Removing item: " << (*bestItemIter)->getName() << " with power " << (*bestItemIter)->getBasePower() << std::endl;
        m_items.erase(bestItemIter);
        std::cout << "Item at index " << idx << " removed." << std::endl;
    }

}