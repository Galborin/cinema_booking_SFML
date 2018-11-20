#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include"Resources.h"
using namespace sf;

class OnScreen : 
	public Drawable, public Transformable
{
protected:
	virtual void draw(RenderTarget & target, RenderStates states) const override;
	RectangleShape m_rectangleshape;
	Text text;
	Font font;
	const Texture texture;
	sf::FileInputStream stream;
public:
	virtual void set_position(float x,float y);
	Vector2f get_position();
	virtual void set_size(float x, float y);
	Vector2f get_size() const;
	FloatRect getGlobalBounds() const;
	void setOutlineThickness(float thic);
	OnScreen();
	OnScreen(float size_x, float size_y);
	virtual ~OnScreen();
};

