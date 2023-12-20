/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PatycleSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:34:35 by janhan            #+#    #+#             */
/*   Updated: 2023/12/20 20:35:11 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Vertex.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>
#include "GravitySource.hpp"

class PatycleSource
{

	public:
		PatycleSource(float pos_x, float pos_y, float vel_x, float vel_y, sf::Color color);
		void	render(sf::RenderWindow& window);
		void	update_physics(GravitySource s);
		void	set_color(sf::Color col);
		void 	setSize();
	private:
		sf::Vector2f pos;
		sf::Vector2f vel;
		sf::CircleShape ball;
		sf::Color	color;
};
