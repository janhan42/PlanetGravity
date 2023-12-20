/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gui.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:48:02 by janhan            #+#    #+#             */
/*   Updated: 2023/12/20 20:39:16 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Gui.hpp"
#include "SFML/System/Vector2.hpp"

UI::UI(sf::Vector2f position, sf::Vector2f size, std::string text, sf::Color Color)
	: position(position), size(size), text(text) {
	font.loadFromFile("arial.ttf");
	uiShape.setSize(size);
	uiShape.setPosition(position);
	uiShape.setFillColor(Color);
	uiText.setFont(font);
	uiText.setString(text);
	uiText.setCharacterSize(200000);
	uiText.setFillColor(sf::Color::White);
	sf::FloatRect textBounds = uiText.getGlobalBounds();
	uiText.setOrigin(textBounds.left + textBounds.width / 2.0f,
						textBounds.top + textBounds.height / 2.0f);
	uiText.setPosition(position.x + size.x / 2.0f,
						position.y + size.y / 2.0f);
}

void UI::draw(sf::RenderWindow& window)
{
	window.draw(uiShape);
	window.draw(uiText);
}

bool UI::isMouseOver(const sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	return (uiShape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))));
}
