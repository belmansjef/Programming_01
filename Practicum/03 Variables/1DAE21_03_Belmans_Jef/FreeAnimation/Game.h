#pragma once
using namespace utils;
using namespace std;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Free Animation - Belmans, Jef - 1DAE21" };

// Change the window dimensions here
float g_WindowWidth{ 1024 };
float g_WindowHeight{ 576 };
#pragma endregion gameInformation



#pragma region ownDeclarations
enum class ProjectileDirection { up, down, left, right };

class Projectile
{
private:
	unsigned int m_ID{};

	bool m_InRenderView{ true };
	int m_NrFramesAlive{ 0 };
	float m_Radius{ 20.0f };
	float m_Speed{ 5.0f };
	Point2f m_StartPos{ 0.0f, 0.0f };
	Point2f m_CurrentPos{ 0.0f, 0.0f };
	ProjectileDirection m_Direction{ ProjectileDirection::up };

public:

	Projectile(Point2f startPos, int id);

	int GetId();

	bool IsInRenderView();
	Point2f GetPosition();

	void Update();
	void Draw();
};
class ProjectileManager
{
private:
	signed int m_LastID{ 0 };
	vector<Projectile> m_Projectiles{};

public:
	
	ProjectileManager();

	int GetProjectileCount();

	void AddProjectile(Point2f startPos);
	void UpdateProjectiles();
	void DrawProjctiles();
	void RemoveProjectile(Projectile projectile);
};

bool g_IsCharging{ false };
bool g_IsFullyCharged{};
unsigned int g_NrFrames{};
unsigned int g_NrFramesSinceReleaseLMB{};
unsigned int g_ChargeTimer{};

Point2f g_MousePos{};
ProjectileManager g_ProjectileManager{};

void ChargeShot();
void ReleaseShot();
#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
