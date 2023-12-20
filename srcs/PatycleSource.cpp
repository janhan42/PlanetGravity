/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PatycleSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:35:26 by janhan            #+#    #+#             */
/*   Updated: 2023/12/20 20:40:53 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PatycleSource.hpp"
#include "SFML/Graphics/Color.hpp"
#include <atomic>
#include <vector>

PatycleSource::PatycleSource(float pos_x, float pos_y, float vel_x, float vel_y, sf::Color color){
	pos.x = pos_x;
	pos.y = pos_y;
	vel.x = vel_x;
	vel.y = vel_y;

	ball.setPosition(pos);
	ball.setFillColor(color);
	// 파티클 사이즈
	ball.setRadius(2);
}

void PatycleSource::render(sf::RenderWindow &window){
	ball.setPosition(pos);
	window.draw(ball);
}

void PatycleSource::set_color(sf::Color col)
{
	ball.setFillColor(col);
}

void PatycleSource::setSize()
{
	ball.setRadius(ball.getRadius() + 1);
	ball.setOrigin(ball.getRadius(), ball.getRadius());
}

//뉴턴의 법칙
void PatycleSource::update_physics(GravitySource s){
	float distance_x = s.get_pos().x - pos.x;
	//중심 물체(중력 포인트)와 대상 물체 의 x 좌표 차이를 계산
	float distance_y = s.get_pos().y - pos.y;
	//중심 물체(중력 포인트)와 대상 물체 의 y 좌표 차이를 계산
	float distance = sqrt(distance_x * distance_x + distance_y * distance_y);
	//두 물체간의 거리를 계산
	float inverse_distance = 1.f / distance;
	//거리의 역수를 계산, 거리가 0에 가까워 질수록 커지고 거리가 멀수록 작아짐
	float nomalized_x = inverse_distance * distance_x;
	float nomalized_y = inverse_distance * distance_y;
	// x.y 의 정규화 벡터 계산
	float inverse_square_dropoff = inverse_distance * inverse_distance;
	// 거리의 제곱에 역수를 취한 값 계산
	float acceleration_x = nomalized_x * s.get_strengeth() * inverse_square_dropoff;
	float acceleration_y = nomalized_y * s.get_strengeth() * inverse_square_dropoff;
	// x.y 의 중력 가속도 계산$
	vel.x += acceleration_x;
	vel.y += acceleration_y;
	// 파티클의 x.y 속도에 중력가속도를 더하기
	pos.x += vel.x;
	pos.y += vel.y;
	// 속도를 변경후 위치를 업데이트
}
