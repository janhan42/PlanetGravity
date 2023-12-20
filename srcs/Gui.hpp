/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gui.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:48:09 by janhan            #+#    #+#             */
/*   Updated: 2023/12/20 20:38:04 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "PatycleSource.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class UI
{
	public:
		UI(sf::Vector2f position, sf::Vector2f size, std::string text, sf::Color Color);
		void	draw(sf::RenderWindow& window);
		bool isMouseOver(const sf::RenderWindow& window);
	private:
		sf::Vector2f position;
		sf::Vector2f size;
		std::string text;
		sf::RectangleShape uiShape;
		sf::Text uiText;
		sf::Font font;
};
