/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GravitySource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:20:21 by janhan            #+#    #+#             */
/*   Updated: 2023/12/21 10:18:09 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GravitySource.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/NonCopyable.hpp"
#include "SFML/Window/Mouse.hpp"

GravitySource::GravitySource(float pos_x, float pos_y, float strength){
	pos.x = pos_x;
	pos.y = pos_y;
	this->strength = strength;
	s.setPosition(pos);
	s.setFillColor(sf::Color::White);
	s.setRadius(15);
	s.setOrigin(s.getRadius(), s.getRadius());
}

void GravitySource::render(sf::RenderWindow &window){
	window.draw(s);
}

sf::Vector2f GravitySource::get_pos(){
	return pos;
}

float GravitySource::get_strengeth(){
	return strength;
}

bool GravitySource::isMouseOver(const sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	return (s.getGlobalBounds().contains(static_cast<float>(mousePos.x),
											static_cast<float>(mousePos.y)));
}

void GravitySource::isMouseEvent(const sf::RenderWindow& window) {
	pos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
	s.setPosition(pos);
}

void GravitySource::drawGravityRange(sf::RenderWindow& window) const {
    sf::CircleShape gravityRange(100);
	gravityRange.setPosition(pos);
	gravityRange.setOrigin(gravityRange.getRadius(), gravityRange.getRadius());
    gravityRange.setFillColor(sf::Color(0, 128, 255, 50)); // 파란색 원
    window.draw(gravityRange);
}
