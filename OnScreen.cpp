#include "pch.h"
#include "OnScreen.h"


void OnScreen::draw(RenderTarget & target, RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_rectangleshape,states);
	target.draw(text, states);
}

void OnScreen::set_position(float x, float y)
{
	m_rectangleshape.setPosition(x, y);
	text.setPosition(x + 10.f, y + 10.f);
}

Vector2f OnScreen::get_position()
{
	return m_rectangleshape.getPosition();
}

void OnScreen::set_size(float x, float y)
{
	m_rectangleshape.setSize(Vector2f(x, y));
}

Vector2f OnScreen::get_size() const
{
	return m_rectangleshape.getSize();
}

FloatRect OnScreen::getGlobalBounds() const
{
	return m_rectangleshape.getGlobalBounds();
}

void OnScreen::setOutlineThickness(float thic)
{
	m_rectangleshape.setOutlineThickness(thic);
}

OnScreen::OnScreen()
{
	m_rectangleshape.setOutlineColor(Color::Magenta);
	m_rectangleshape.setFillColor(Color::Blue);
	text.setFont(resources.font);
	text.setCharacterSize(26);
	text.setFillColor(Color::Black);
}

OnScreen::OnScreen(float size_x, float size_y)
{
	m_rectangleshape.setOutlineColor(Color::Magenta);
	m_rectangleshape.setFillColor(Color::Blue);
	m_rectangleshape.setSize(Vector2f(size_x, size_y));
	text.setFont(resources.font);
	text.setCharacterSize(26);
	text.setFillColor(Color::Black);
}

OnScreen::~OnScreen() 
{
}
