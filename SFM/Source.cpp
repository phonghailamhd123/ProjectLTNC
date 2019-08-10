#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include"NODE.h"
#include<iostream>
using namespace std ;
using namespace sf;


void PlayGame(RenderWindow &window)
{
	
	Texture Node, Node0, Node1, Node2, Node3, Node4, Node5, Node6, Node7, Node8, simle, Flag, Mine;

	Node.loadFromFile("Node.png");
	Node0.loadFromFile("0.png");
	Node1.loadFromFile("1.png");
	Node2.loadFromFile("2.png");
	Node3.loadFromFile("3.png");
	Node4.loadFromFile("4.png");
	Node5.loadFromFile("5.png");
	Node6.loadFromFile("6.png");
	Node7.loadFromFile("7.png");
	Node8.loadFromFile("8.png");
	
	simle.loadFromFile("ClickSmile.png");
	Flag.loadFromFile("Flag.png");
	Mine.loadFromFile("Mine.png");

	

	Sprite Simle(simle);
	Simle.setOrigin(16, 16);
	Simle.setPosition(200, 50);

	
	NODE Button[12][8];



	for (int i = 0; i < 12; i++)
	{
		Button[i][0].kinds = 0;
		Button[i][11].kinds = 0;
	}

	for (int j = 0; j < 8; j++)
	{
		Button[0][j].kinds = 0;
		Button[7][j].kinds = 0;
	}

	for (int i = 1; i <= 10; i++){

		for (int j = 1; j <= 6; j++)
			if ((rand() % 5 - 3) == -1)
			{
				Button[i][j].kinds = -1;
				Button[i][j].LastLayer.setTexture(Mine);
			}
			else {
				Button[i][j].kinds = NULL;
				Button[i][j].LastLayer.setTexture(Node0);
			}
	}
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			cout << Button[i][j].kinds <<" " ;
		}
		cout << endl;
	}



	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 6; j++)
		{
			Button[i][j].setData(Node);
			Button[i][j].x = i * 32 +6;// +40;
			Button[i][j].y = j * 32 +68;// +100;
			Button[i][j].FirstLayer.setPosition(Button[i][j].x, Button[i][j].y);
			Button[i][j].LastLayer.setPosition(Button[i][j].x, Button[i][j].y);
			if (Button[i][j].kinds == NULL)
			{
				if ((i >= 1) && (i <= 10) && (j >= 1) && (j <= 6))
				{
					int count = 0;
					if (Button[i - 1][j].kinds == -1)count++;
					if (Button[i + 1][j].kinds == -1)count++;
					if (Button[i][j - 1].kinds == -1)count++;
					if (Button[i][j + 1].kinds == -1)count++;
					if (Button[i - 1][j - 1].kinds == -1)count++;
					if (Button[i - 1][j + 1].kinds == -1)count++;
					if (Button[i + 1][j - 1].kinds == -1)count++;
					if (Button[i + 1][j + 1].kinds == -1)count++;
					Button[i][j].kinds = count;
					switch (Button[i][j].kinds)
					{
					case 0:
						Button[i][j].LastLayer.setTexture(Node0);
						break;
					case 1:
						Button[i][j].LastLayer.setTexture(Node1);
						break;
					case 2:
						Button[i][j].LastLayer.setTexture(Node2);
						break;
					case 3:
						Button[i][j].LastLayer.setTexture(Node3);
						break;
					case 4:
						Button[i][j].LastLayer.setTexture(Node4);
						break;
					case 5:
						Button[i][j].LastLayer.setTexture(Node5);
						break;
					case 6:
						Button[i][j].LastLayer.setTexture(Node6);
						break;
					case 7:
						Button[i][j].LastLayer.setTexture(Node7);
						break;
					case 8:
						Button[i][j].LastLayer.setTexture(Node8);
						break;
					}
				}
			}
		}
	
	// KHỞI TẠO ẢNH NỀN

	Texture background;
	background.loadFromFile("Play_Background.png");
	Sprite Background(background);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
		}
		window.clear();
		window.draw(Background);
		window.draw(Simle);
		
		if (Mouse::isButtonPressed(Mouse::Left))
		{
		
			//cout << "click";
			int x = int((Mouse::getPosition(window).x -8) / 32);
			int y = int((Mouse::getPosition(window).y -68) / 32 );
			if (x <= 10 && y <= 6 && x>= 1 && y>=1)
			{
				Button[x][y].lat = true;
				//cout << "true";
				if (Button[x][y].kinds == -1) break;
			}
		}
		if (Mouse::isButtonPressed(Mouse::Right))
		{
			//cout << "click";
			int x = int((Mouse::getPosition(window).x -6) / 32 );
			int y = int((Mouse::getPosition(window).y -68) / 32);
			if (x <= 10 && y <= 6 && x >= 1 && y >= 1)
			{
				if (Button[x][y].flag == false)
				{
					Button[x][y].FirstLayer.setTexture(Flag);
					Button[x][y].flag = true;
					//cout << "Flag";
				}
				else
				{
					Button[x][y].FirstLayer.setTexture(Node);
					Button[x][y].flag = false;
				}
			}
		}
		
		
		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 6; j++)
			{
				window.draw(Button[i][j].LastLayer);
			}
		
		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 6; j++)
			{
				if (!Button[i][j].lat)window.draw(Button[i][j].FirstLayer);
			}
		
		window.display();
	}
	
	simle.loadFromFile("LoserSmile.png");
	Simle.setTexture(simle);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)window.close();
		}
		window.clear();
		window.draw(Background);
		window.draw(Simle);
		
		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 6; j++)
			{
				window.draw(Button[i][j].LastLayer);
			}
		
		window.display();
	}
	
	
}
int main()
{
	RenderWindow window(VideoMode(400,340),"LAM HAI PHONG");
	Texture back , play , exit, name ;
	back.loadFromFile("back.png");
	play.loadFromFile("Play.png");
	exit.loadFromFile("Exit.png");
	name.loadFromFile("CoolText.png"); 
	Sprite Back(back), Play(play), Exit(exit),Name(name) ;

	Play.setOrigin(20,20) ;
	Play.setPosition(170,170);

	Exit.setOrigin(20,20);
	Exit.setPosition(165,250);

	Name.setOrigin(20,20);
	Name.setPosition(70,305);
	Music music ;
	music.openFromFile("Main.wav");
	music.play();
	music.setLoop(true);

	while (window.isOpen())
	{
		Event e ;
		while (window.pollEvent(e))
		{
			if(e.type == Event::Closed) window.close();
		}

		int x = Mouse::getPosition(window).x ;
		int y = Mouse::getPosition(window).y;
		cout << x <<" " << y << endl;
		if(Mouse::getPosition(window).x >= 170 && Mouse::getPosition(window).x <= 220 && Mouse::getPosition(window).y >= 153 && Mouse::getPosition(window).y <= 177)
		{
			Play.setColor(Color::Blue);

			if(Mouse::isButtonPressed(Mouse::Left)){
				PlayGame(window);
			}


		}else {
			Play.setColor(Color::Red);
		}

		if(Mouse::getPosition(window).x >= 170 && Mouse::getPosition(window).x <= 215 && Mouse::getPosition(window).y >= 240 && Mouse::getPosition(window).y <= 256)
		{
			Exit.setColor(Color::Blue);
			if(Mouse::isButtonPressed(Mouse::Left)) window.close();
		}else {
			Exit.setColor(Color::Red);
		}
		//Name.setColor(Color::Yellow);
		window.clear();
		window.draw(Back);
		window.draw(Play);
		window.draw(Exit);
		window.draw(Name); 
		window.display();
	}
	return 0 ;
}

