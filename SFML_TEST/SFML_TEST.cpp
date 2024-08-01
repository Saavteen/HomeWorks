#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>

const float FIELD_WIDTH = 3440.0f;
const float FIELD_HEIGHT = 1440.0f;

bool checkCollision(sf::Sprite& object1, sf::Sprite& object2)
{
	const sf::FloatRect& boundingBox1 = object1.getGlobalBounds();
	const sf::FloatRect& boundingBox2 = object2.getGlobalBounds();

	return boundingBox1.intersects(boundingBox2);
}

void handleCollision(sf::Sprite& object1, sf::Sprite& object2)
{
	if (checkCollision(object1, object2))
	{
		object1.setColor(sf::Color::Red);
		object2.setColor(sf::Color::Red);
	}
	else
	{
		object1.setColor(sf::Color::White);
		object2.setColor(sf::Color::White);
	}
}

void handleScale(sf::Sprite& gameObject)
{
	const float ScaleSpeed = 0.05f;

	float Scale = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		Scale = ScaleSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		Scale = -ScaleSpeed;
	}

	gameObject.setScale({ gameObject.getScale().x +Scale,gameObject.getScale().y +Scale });
}

void handleRotation(sf::Sprite& gameObject)
{
	const float RotationSpeed = 1;

	float DeltaRotation = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		DeltaRotation = RotationSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		DeltaRotation = -RotationSpeed;
	}
	
	gameObject.setRotation(gameObject.getRotation() + DeltaRotation);
}

void handleMovement(sf::Sprite& gameObject)
{
	float DeltaX = 0.0f;
	float DeltaY = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		DeltaY = -10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		DeltaY = 10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		DeltaX = -10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		DeltaX = 10.0f;
	}

	sf::Vector2f oldPosition = gameObject.getPosition();
	gameObject.setPosition({ oldPosition.x + DeltaX,oldPosition.y + DeltaY });

}

sf::FloatRect getTransformedBounds(const sf::Sprite& sprite)
{
	sf::Transform transform = sprite.getTransform();
	sf::FloatRect bounds = sprite.getLocalBounds();
	return transform.transformRect(bounds);
}

void checkBoundaries(sf::Sprite& gameObject)
{
	sf::FloatRect bounds = getTransformedBounds(gameObject);

	// Враховуємо відступи від країв
	if (bounds.left < 0) {
		gameObject.setPosition(gameObject.getPosition().x - bounds.left, gameObject.getPosition().y);
	}
	if (bounds.top < 0) {
		gameObject.setPosition(gameObject.getPosition().x, gameObject.getPosition().y - bounds.top);
	}
	if (bounds.left + bounds.width > FIELD_WIDTH) {
		gameObject.setPosition(gameObject.getPosition().x - (bounds.left + bounds.width - FIELD_WIDTH), gameObject.getPosition().y);
	}
	if (bounds.top + bounds.height > FIELD_HEIGHT) {
		gameObject.setPosition(gameObject.getPosition().x, gameObject.getPosition().y - (bounds.top + bounds.height - FIELD_HEIGHT));
	}
}



int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Homework 25 SFML");

	//sf::Font defaultGameFont;
	//defaultGameFont.loadFromFile(""); // .ttf шрифт

	//sf::Text myText;

	//myText.setFont(defaultGameFont);
	//myText.setString("HEllo WORLD");
	//myText.setCharacterSize(48);
	//myText.setColor(sf::Color::Blue);

	sf::Texture playerTexture;
	playerTexture.loadFromFile("sprite2.png");

	sf::Sprite player;
	player.setTexture(playerTexture);

	sf::Vector2f centerPoint = { window.getSize().x / 2.0f,window.getSize().y / 2.0f };
	player.setPosition(centerPoint);
	player.setOrigin({ player.getGlobalBounds().getSize().x / 2.0f, player.getGlobalBounds().getSize().y / 2.0f });

	sf::Texture boxTexture;
	boxTexture.loadFromFile("Box.png");

	sf::Sprite box;
	box.setTexture(boxTexture);
	box.setOrigin({ box.getGlobalBounds().getSize().x / 1.5f, box.getGlobalBounds().getSize().y / 1.5f });
	box.setPosition(centerPoint);

	window.setFramerateLimit(60);

	while (window.isOpen())
	{

		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		handleMovement(player); 
		handleRotation(player);
		handleScale(player);
		handleCollision(player, box);
		checkBoundaries(player);

		window.clear(sf::Color{ 0, 0, 0 });

		window.draw(player);
		window.draw(box);
		//window.draw(myText);

		window.display();
	}
}
