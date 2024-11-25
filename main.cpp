#include <iostream>
#include <complex>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ComplexPlane.h"

using namespace sf;
using namespace std;


int main()
{
	int gyattWidth = VideoMode::getDesktopMode().width / 2;
	int gyattHeight = VideoMode::getDesktopMode().height / 2;

	VideoMode sigma(gyattWidth, gyattHeight);

	RenderWindow hawk(sigma, "Mandelbrot", Style::Default);
	ComplexPlane tuah(gyattWidth, gyattHeight);

	Text livvyDunne;
	Font babyGronk;
	if (!babyGronk.loadFromFile("comicSans.ttf"))
	{
		// error...
	}


	while (hawk.isOpen())
	{
		Event skibidi;

		livvyDunne.setFont(babyGronk);

		//livvyDunne.setString("fanum tax my bacon egg n cheese on a roll");

		livvyDunne.setCharacterSize(24);

		livvyDunne.setFillColor(sf::Color::Blue);

		while (hawk.pollEvent(skibidi))
		{
			//Vector2i sussyBaka;

			if (skibidi.type == Event::Closed)
			{
				hawk.close();
			}

			if (skibidi.type == Event::MouseButtonPressed)
			{
				if (skibidi.mouseButton.button == Mouse::Left)
				{
					//Left click will zoomIn and call setCenter on the ComplexPlane object with the(x, y) pixel location of the mouse click
					tuah.zoomIn();
					tuah.setCenter(Vector2i(skibidi.mouseButton.x, skibidi.mouseButton.y));
					//livvyDunne.setString(to_string(sussyBaka.x));
					//cout << "x: " << sussyBaka.x << endl;
					//cout << "y: " << sussyBaka.y << endl;
				}
				
				if (skibidi.mouseButton.button == Mouse::Right)
				{
					//Right click will zoomOut and call setCenter on the ComplexPlane object with the (x,y) pixel location of the mouse click
					tuah.zoomOut();
					tuah.setCenter(Vector2i(skibidi.mouseButton.x, skibidi.mouseButton.y));

				}

				

			}

			if (skibidi.type == Event::MouseMoved)
			{
				//Call setMouseLocation on the ComplexPlane object to store the (x,y) pixel location of the mouse click
				tuah.setMouseLocation(Vector2i(skibidi.mouseButton.x, skibidi.mouseButton.y));
			}



		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			hawk.close();
		}

		tuah.updateRender();

		tuah.loadText(livvyDunne);

		

		hawk.clear();

		tuah.draw(hawk, RenderStates()); //fix this


		hawk.draw(livvyDunne);

		

		hawk.display();

	}


	return 1;
}