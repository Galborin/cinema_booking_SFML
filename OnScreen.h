#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class OnScreen : 
	public Drawable, public Transformable
{
protected:
	virtual void draw(RenderTarget & target, RenderStates states) const override;
	RectangleShape m_rectangleshape;
	Text m_text;
	Font m_font;
	const Texture m_texture;

public:
	virtual void set_position(float x,float y);
	virtual void set_size(float x, float y);
	Vector2f get_size() const;
	FloatRect getGlobalBounds();
	void setOutlineThickness(float thic);
	OnScreen();
	OnScreen(float size_x, float size_y);
	~OnScreen();
};

