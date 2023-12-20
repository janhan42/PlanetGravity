/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GravitySource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:20:33 by janhan            #+#    #+#             */
/*   Updated: 2023/12/20 19:45:36 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class GravitySource
{
	public:
		GravitySource(float pos_x, float pos_y, float strength);
		void	render(sf::RenderWindow& window);
		sf::Vector2f get_pos();
		float get_strengeth();
		bool isMouseOver(const sf::RenderWindow& window);
		void isMouseEvent(const sf::RenderWindow& window);
		bool isDragging;;
	private:
		sf::Vector2f pos;
		float strength;
		sf::CircleShape s;

		sf::Vector2f offset;
};
