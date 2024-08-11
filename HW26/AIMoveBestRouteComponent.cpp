#include "AIMoveBestRouteComponent.h"
#include "GameObjects.h"
#include "Map.h"
#include "FontManager.h"

AIMoveBestRouteComponent::AIMoveBestRouteComponent(GameObject* referenceObject, GameObject* targetObject)
    : AIMoveToComponent(referenceObject, targetObject), m_mapGraph(buildGraph())
{
#ifdef DEBUG_VERTEX
    m_text.setFont(FontManager::getInstance().getDefaultFont());

    m_text.setCharacterSize(48); // in pixels, not points!
    m_text.setFillColor(sf::Color::Blue);
    m_text.setOrigin(m_text.getGlobalBounds().getSize().x / 2, m_text.getGlobalBounds().getSize().y / 2);
#endif
}

void AIMoveBestRouteComponent::update(float dt)
{
    updatePath(m_mapGraph);
    const sf::Vector2u nextTileToMove = getNextTileToMove();
    const sf::Vector2f targetPosition = Map::GetInstance().getPositionFromTile(nextTileToMove);

    moveTo(dt, targetPosition);
}

void AIMoveBestRouteComponent::draw(sf::RenderWindow* window)
{
#ifdef DEBUG_VERTEX
    const Map::TilesMapType& mapTiles = Map::GetInstance().getAllTiles();

    for (unsigned y = 0; y < mapTiles.size(); y++)
    {
        for (unsigned x = 0; x < mapTiles[y].size(); x++)
        {
            const int vertixNumber = convertMapTileToVertix({ x, y });
            const sf::Vector2f position = Map::GetInstance().getPositionFromTile({ x, y });

            m_text.setPosition(position);
            m_text.setString(std::to_string(vertixNumber));

            window->draw(m_text);
        }
    }
#endif 

#ifdef DEBUG_PATH
    for (auto vertex : m_path)
    {
        sf::RectangleShape path = sf::RectangleShape({ 30, 30 });

        path.setPosition(Map::GetInstance().getPositionFromTile(convertVertixToMapTile(vertex)));
        path.setFillColor(sf::Color::Yellow);

        window->draw(path);
    }
#endif
}

Graph AIMoveBestRouteComponent::buildGraph()
{
    const Map::TilesMapType& mapTiles = Map::GetInstance().getAllTiles();
    unsigned rows = mapTiles.size();
    unsigned cols = mapTiles[0].size();
    Graph graph(rows * cols);

    for (unsigned y = 0; y < rows; ++y)
    {
        for (unsigned x = 0; x < cols; ++x)
        {
            if (mapTiles[y][x] == 0)  
            {
                unsigned currentVertix = convertMapTileToVertix({ x, y });

                if (x > 0 && mapTiles[y][x - 1] == 0) // Left
                {
                    graph.addEdge(currentVertix, convertMapTileToVertix({ x - 1, y }));
                }
                if (x < cols - 1 && mapTiles[y][x + 1] == 0) // Right
                {
                    graph.addEdge(currentVertix, convertMapTileToVertix({ x + 1, y }));
                }
                if (y > 0 && mapTiles[y - 1][x] == 0) // Up
                {
                    graph.addEdge(currentVertix, convertMapTileToVertix({ x, y - 1 }));
                }
                if (y < rows - 1 && mapTiles[y + 1][x] == 0) // Down
                {
                    graph.addEdge(currentVertix, convertMapTileToVertix({ x, y + 1 }));
                }
            }
        }
    }

    return graph;
}

void AIMoveBestRouteComponent::updatePath(Graph& graph)
{
    const sf::Vector2u referenceTile = Map::GetInstance().getTileFromPosition(m_referenceObject->getPosition());
    const sf::Vector2u targetTile = Map::GetInstance().getTileFromPosition(m_targetObject->getPosition());

    const int start = convertMapTileToVertix(referenceTile);
    const int destination = convertMapTileToVertix(targetTile);

    std::vector<unsigned> path = graph.bfs(start, destination);

    m_path = path;
}

sf::Vector2u AIMoveBestRouteComponent::getNextTileToMove()
{
    if (m_path.size() < 2)
    {
        return Map::GetInstance().getTileFromPosition(m_referenceObject->getPosition());
    }

    return convertVertixToMapTile(m_path[1]);
}

sf::Vector2u AIMoveBestRouteComponent::convertVertixToMapTile(unsigned vertix) const
{
    unsigned cols = Map::GetInstance().getAllTiles()[0].size();
    return { vertix % cols, vertix / cols };
}

unsigned AIMoveBestRouteComponent::convertMapTileToVertix(sf::Vector2u mapTile) const
{
    unsigned cols = Map::GetInstance().getAllTiles()[0].size();
    return mapTile.y * cols + mapTile.x;
}
