#include "pch.h"
#include "Game.h"

using namespace utils;

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0.8f, 0.8f, 0.8f);

	#pragma region Green Border
	SetColor(g_ColorGreen);
	DrawRect(g_OriginPoint, g_WindowWidth, g_WindowHeight, 2.0f);
	#pragma endregion

	#pragma region Red Diagonal Lines
	SetColor(g_ColorRed);
	DrawLine(g_OriginPoint, Point2f{ g_WindowWidth, g_WindowHeight });
	DrawLine(Point2f{ 0.0f, g_WindowHeight }, Point2f{ g_WindowWidth, 0.0f });
	#pragma endregion

	#pragma region Blue Center Dot
	SetColor(g_ColorBlue);
	FillEllipse(g_WindowWidth / 2.0f, g_WindowHeight / 2.0f, 4.0f, 4.0f);
	#pragma endregion

	#pragma region White Horizontal and Vertical Lines
	SetColor(g_ColorWhite);
	for (char i = 1; i <= g_NumHorizontalLines; i++)
	{
		DrawLine(Point2f(0.0f, g_HorLineDistance * i), Point2f(g_WindowWidth, g_HorLineDistance * i));
	}

	for (char i = 1; i <= g_NumVerticalLines; i++)
	{
		DrawLine(Point2f(g_VerLineDistance * i, 0.0f), Point2f(g_VerLineDistance * i, g_WindowHeight));
	}
	#pragma endregion
}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions