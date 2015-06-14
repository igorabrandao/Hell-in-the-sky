#include "MenuManager.h"

/********************************************//**
* \class constructor
***********************************************/
MenuManager::MenuManager( void )
{	
	/* Empty */
}

/********************************************//**
* \class destructor
***********************************************/
MenuManager::~MenuManager( void )
{
	/* Empty */
}

/********************************************//**
* \parametrize the menu's element to have
	equals attributes
***********************************************/
void MenuManager::EqualizeMenuItems()
{
	for ( int unsigned i = 0; i < menuItems.size(); i++ )
	{
		if ( menuImages.size() == i )
		{
			menuImages.push_back(null);
		}
	}

	for ( int unsigned i = 0; i < menuImages.size(); i++ )
	{
		if ( menuItems.size() == i )
		{
			menuItems.push_back("");
		}
	}
}

/********************************************//**
* \set manu animation
***********************************************/
void MenuManager::SetAnimations()
{
	for ( int unsigned i = 0; i < menuItems.size(); i++ )
	{
		for ( int unsigned j = 0; j < animationTypes.size(); j++ )
		{
			if ( animationTypes[j] == "Fade" )
			{
				tempAnimation.push_back(new FadeAnimation);
				tempAnimation[tempAnimation.size()-1]->LoadContent(
					menuItems[i], menuImages[i], position);
			}
		}
		animation.push_back(tempAnimation);
		tempAnimation.clear();
	}
}

/********************************************//**
* \set menu position
***********************************************/
void MenuManager::SetPositions()
{
	sf::Vector2f pos = position;
	for ( int unsigned i = 0; i < animation.size(); i++ )
	{
		for ( int unsigned j = 0; j < animation[i].size(); j++ )
		{
			animation[i][j]->SetValue(animation[i][j]->GetPosition(), pos);
		}

		float width = menuImages[i].getSize().x + animation[i][0]->GetText().getLocalBounds().width;
		float height = menuImages[i].getSize().y + animation[i][0]->GetText().getLocalBounds().height;

		if ( axis == 1 )
			pos.x += 10 + width;
		else
			pos.y += 10 + height;
	}
}

/********************************************//**
* \load content on screen
***********************************************/
void MenuManager::LoadContent( std::string menuID )
{
	null.loadFromFile("assets/images/general/not_found.png");
	itemNumber = 0;

	file.LoadContent("assets/settings/menus.hell", attributes, contents, menuID);

	for ( int unsigned i = 0; i < attributes.size(); i++ )
	{
		for ( int unsigned j = 0; j < attributes[i].size(); j++ )
		{
			std::string att = attributes[i][j];
			std::string con = contents[i][j];

			if ( att == "Item" )
			{
				menuItems.push_back(con);
			}
			else if ( att == "Image" )
			{
				image.loadFromFile(con);
				menuImages.push_back(image);
			}
			else if ( att == "Position" )
			{
				std::string pos[2];
				pos[0] = con.substr(0, con.find(','));
				pos[1] = con.substr(con.find(',') + 1);

				position.x = std::stod(pos[0]);
				position.x = std::stod(pos[1]);

				std::cout << "Pos: " << position.x << " " << position.y << std::endl;
			}
			else if ( att == "Align" )
			{
				align = con;
			}
			else if ( att == "Axis" )
			{
				axis = std::stoi(con);
			}
			else if ( att == "Animation" )
			{
				animationTypes.push_back(con);
			}
		}
	}

	EqualizeMenuItems();
	SetAnimations();
	SetPositions();
}

/********************************************//**
* \unload menu content
***********************************************/
void MenuManager::UnloadContent()
{
	menuItems.clear();
	menuImages.clear();

	for ( int unsigned i = 0; i < animation.size(); i++ )
	{
		for ( int unsigned j = 0; j < animation[i].size(); j++ )
		{
			delete animation[i][j];
		}
	}

	animation.clear();
	animationTypes.clear();

	attributes.clear();
	contents.clear();
}

/********************************************//**
* \update menu content
***********************************************/
void MenuManager::Update( sf::RenderWindow &Window, InputManager input )
{
	/*! Check navigation direction
	 * Axis = 0 -> vertical
	 * Axis = 1 -> horizontal
	*/
	if ( axis == 1 )
	{
		/* Check which key is pressed */
		if ( input.KeyPressed(sf::Keyboard::Right) || input.KeyPressed(sf::Keyboard::D) )
			itemNumber++;
		else if ( input.KeyPressed(sf::Keyboard::Left) || input.KeyPressed(sf::Keyboard::A) )
			itemNumber--;
	}
	else
	{
		/* Check which key is pressed */
		if ( input.KeyPressed(sf::Keyboard::Down) || input.KeyPressed(sf::Keyboard::S) )
			itemNumber++;
		else if ( input.KeyPressed(sf::Keyboard::Up) || input.KeyPressed(sf::Keyboard::W) )
			itemNumber--;
	}

	/*! Handle menu items number */
	if ( itemNumber < 0 )
		itemNumber = 0;
	else if ( itemNumber > menuItems.size() - 1 )
		itemNumber = menuItems.size() - 1;

	for ( int unsigned i = 0; i < animation.size(); i++ )
	{
		for ( int unsigned j = 0; j < animation[i].size(); j++ )
		{
			animation[i][j]->SetValue(animation[i][j]->GetActive(), false);

			if ( i == itemNumber )
				animation[i][j]->SetValue(animation[i][j]->GetActive(), true);

			animation[i][j]->Update(Window);
		}
	}
}

/********************************************//**
* \draw menu content
***********************************************/
void MenuManager::Draw( sf::RenderWindow &Window )
{
	for ( int unsigned i = 0; i < animation.size(); i++ )
	{
		for ( int unsigned j = 0; j < animation[i].size(); j++ )
		{
			animation[i][j]->Draw(Window);
		}
	}
}