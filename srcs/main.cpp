/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:16:18 by janhan            #+#    #+#             */
/*   Updated: 2023/12/21 10:23:21 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <SFML/Graphics.hpp>
#include <random>
#include <regex>
#include "PatycleSource.hpp"
#include "GravitySource.hpp"
#include "Gui.hpp"

// random RGB value
sf::Color map_val_to_color(float value)
{
	int r = 0, g = 0, b = 0;

	if (value < 0.0f) value = 0;
	if (value > 1.0f) value = 1;
	if (value < 0.5f)
	{
		b = 255 * (1.0f - 2 * value);
		g = 255 *  2 * value;
	}
	else {
		g = 255 * (2.0f - 2 * value);
		r = 255 * (2 * value - 1);
	}
	return (sf::Color(r, g, b));
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "PlanetGravity"); // 윈도우 사이즈 이름
	window.setFramerateLimit(60); // 윈도우 프레임 설정
	std::vector<GravitySource> gravityPoint; // vector 값으로 중럭 포인터 생성
	std::vector<PatycleSource> particle;
	UI sizeUpButtom(sf::Vector2f(100,100), sf::Vector2f(50, 50), std::string("size up"), sf::Color::Blue);
	UI clearButton(sf::Vector2f(160, 100), sf::Vector2f(50, 50), "Clear", sf::Color::Red);
	UI trajectoryButtom(sf::Vector2f(220, 100), sf::Vector2f(50, 50), "traject", sf::Color::Green);
	bool isDragging0 = false;
	bool isDragging1 = false;
	bool isTrajectroty = false;
	int num_particle = 2000; // 초기 파티클 개수

	gravityPoint.push_back(GravitySource((window.getSize().x / 3.f), (window.getSize().y / 2.f), 7000));
	gravityPoint.push_back(GravitySource((window.getSize().x / 1.5f), (window.getSize().y / 2.f), 7000));
	for (int i = 0; i < num_particle; i++) // 초기 파티클 색상 및 위치 설정
	{
		float val = (float)i / (float)num_particle;
		sf::Color col = map_val_to_color(val);
		particle.push_back(PatycleSource(600, 700, 4, 0.2 + (0.1 / num_particle) * i, col));
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) // 이벤트 관리
		{
			if (event.type == sf::Event::Closed) window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isDragging0)
			{
				if (!sizeUpButtom.isMouseOver(window) && !gravityPoint[0].isMouseOver(window) && !clearButton.isMouseOver(window) && !isDragging0 && !isDragging1) // 마우스 Left 클릭으로 새로운 파티클 생성
				{
					sf::Color randomColor(std::rand() % 256, std::rand() % 256, std::rand() % 256);
					particle.push_back(PatycleSource(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y,4.0f,3.0f, randomColor));
				}
				if(sizeUpButtom.isMouseOver(window) && !gravityPoint[0].isMouseOver(window) && !clearButton.isMouseOver(window)) // 파티클 크기 증가
					for(int i = 0; i < particle.size(); i++)
						particle[i].setSize();

				if (!sizeUpButtom.isMouseOver(window) && gravityPoint[0].isMouseOver(window) && !clearButton.isMouseOver(window)) // 중력 포인트 이동
					if (event.type == sf::Event::MouseButtonPressed)
						if (event.mouseButton.button == sf::Mouse::Left)
							isDragging0 = true;

				if (!sizeUpButtom.isMouseOver(window) && !gravityPoint[0].isMouseOver(window) && gravityPoint[1].isMouseOver(window)) // 중력 포인트 1 이동
					if (event.type == sf::Event::MouseButtonPressed)
						if (event.mouseButton.button == sf::Mouse::Left)
							isDragging1 = true;

				if (!sizeUpButtom.isMouseOver(window) && !gravityPoint[0].isMouseOver(window) && clearButton.isMouseOver(window)) // 파티클 초기화
					particle.clear();

				if (!sizeUpButtom.isMouseOver(window) && !gravityPoint[0].isMouseOver(window) && !clearButton.isMouseOver(window) && trajectoryButtom.isMouseOver(window))
					isTrajectroty = !isTrajectroty;
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					isDragging0 = false;
					isDragging1 = false;
				}
			}
		}
		window.clear(); // 윈도우 지우기
		// 파티클 추적 및 업데이트
		for(int j = 0;  j < particle.size(); j++) // 파티클 렌더
		{
			if (isTrajectroty)
				particle[j].renderTrajectory(window);
			particle[j].render(window);
		}
		// 파티클 업데이트
		for (int i = 0; i < gravityPoint.size(); i++){
			for(int j = 0;  j < particle.size(); j++)
			{
				particle[j].update_physics(gravityPoint[i]);
			}
		}
		sizeUpButtom.draw(window); // 사이즈 업 버튼 확인
		clearButton.draw(window);
		trajectoryButtom.draw(window);
		if (isDragging0) // 중력 포인트 드래그 드로우
			gravityPoint[0].isMouseEvent(window);
		if (isDragging1)
			gravityPoint[1].isMouseEvent(window);
		for (int i = 0; i < gravityPoint.size(); i++) // 중력 포인트 드로우
		{
			gravityPoint[i].render(window);
			// gravityPoint[i].drawGravityRange(window);
		}
		window.display();
	}
	return (0);
}
