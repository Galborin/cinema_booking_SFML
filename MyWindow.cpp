#include "pch.h"
#include "MyWindow.h"


MyWindow::MyWindow() 
{
	create(sf::VideoMode(1024, 768, 32), "MyWindow");
	setFramerateLimit(60);
}


MyWindow::~MyWindow()
{
}
