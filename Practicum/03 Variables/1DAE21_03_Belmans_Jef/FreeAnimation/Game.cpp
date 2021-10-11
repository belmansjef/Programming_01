#include "pch.h"
#include "Game.h"

#pragma region gameFunctions										
void Start()
{

}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	ChargeShot();
	g_ProjectileManager.DrawProjctiles();
}

void Update(float elapsedSec)
{
	++g_NrFrames;
	++g_NrFramesSinceReleaseLMB;

	g_ProjectileManager.UpdateProjectiles();
}

void End()
{

}
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
		case SDL_BUTTON_RIGHT:
			g_IsCharging = true;
			break;
		default:
			break;
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
		case SDL_BUTTON_RIGHT:
			if (g_IsFullyCharged)
			{
				ReleaseShot();
			}

			g_IsCharging = g_IsFullyCharged = false;

			g_ChargeTimer = 0;
			g_NrFramesSinceReleaseLMB = 0;
			break;
		default:
			break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
void ChargeShot()
{
	const float radius{ 30.0f };
	const float angle{ (270 + g_ChargeTimer) % 360 * (g_Pi / 180.0f) };

	g_IsFullyCharged |= angle <= g_Pi;

	const float warmupSine{ (sinf(angle) + 1.0f) };
	const float chargedSine{ (sinf(5.0f * angle) + 5.0f) / 5.0f };
	const float secondaryWarmupSine{ sinf(2.5f * angle) + 1.0f };
	const float secondaryChargedSine{ (sinf(5.0f * angle + 1.5f) + 6.0f) / 6.0f };

	const Ellipsef ellipseChargeVFX
	{
		g_MousePos,
		(radius / 1.75f) * (g_IsFullyCharged ? chargedSine : warmupSine),
		(radius / 1.75f) * (g_IsFullyCharged ? chargedSine : warmupSine) 
	};

	const Ellipsef secondaryEllipseVFX
	{
		g_MousePos,
		radius * (g_IsFullyCharged ? secondaryChargedSine : secondaryWarmupSine),
		radius * (g_IsFullyCharged ? secondaryChargedSine : secondaryWarmupSine)
	};

	if (g_IsCharging)
	{
		++g_ChargeTimer;

		SetColor(0.8f, 0.25f, 0.8f);
		DrawEllipse(ellipseChargeVFX);
		SetColor(0.8f, 0.8f, 0.0f);
		DrawEllipse(secondaryEllipseVFX);
	}
}

void ReleaseShot()
{
	int maxProjectiles{ int(RandomRange(2, 8)) };

	for (int i = 0; i < maxProjectiles; i++)
	{
		g_ProjectileManager.AddProjectile(g_MousePos);
	}
}

Projectile::Projectile(Point2f startPos, int id)
{
	m_ID = id;
	m_StartPos = startPos;
	m_CurrentPos = m_StartPos;
	m_Direction = ProjectileDirection(RandomRange(0, 4));
	m_Speed = RandomRange(1.0f, 5.0f);
	m_Radius = RandomRange(10.0f, 20.0f);
}

int Projectile::GetId()
{
	return m_ID;
}

bool Projectile::IsInRenderView()
{
	return m_InRenderView;
}

Point2f Projectile::GetPosition()
{
	return m_CurrentPos;
}

void Projectile::Update()
{
	++m_NrFramesAlive;

	switch (m_Direction)
	{
		case ProjectileDirection::up:
			m_CurrentPos.y += m_Speed;
			break;
		case ProjectileDirection::down:
			m_CurrentPos.y -= m_Speed;
			break;
		case ProjectileDirection::left:
			m_CurrentPos.x -= m_Speed;
			break;
		case ProjectileDirection::right:
			m_CurrentPos.x += m_Speed;
			break;
		default:
			cout << "Error updating position for " << this << endl;
			break;
	}

	m_InRenderView =
		!((m_CurrentPos.x + m_Radius <= 0.0f) ||
		(m_CurrentPos.x - m_Radius >= g_WindowWidth) ||
		(m_CurrentPos.y + m_Radius <= 0.0f) ||
		(m_CurrentPos.y - m_Radius >= g_WindowHeight));
}

void Projectile::Draw()
{
	SetColor(0.8f, 0.25f, 0.8f);
	FillEllipse(m_CurrentPos, m_Radius, m_Radius);
}

ProjectileManager::ProjectileManager()
{
	m_Projectiles.reserve(255);
}

int ProjectileManager::GetProjectileCount()
{
	return int(m_Projectiles.size());
}

void ProjectileManager::AddProjectile(Point2f startPos)
{
	m_Projectiles.push_back(Projectile(startPos, ++m_LastID));
}

void ProjectileManager::UpdateProjectiles()
{
	for (Projectile &projectile: m_Projectiles)
	{
		projectile.Update();
		if (!projectile.IsInRenderView())
		{
			g_ProjectileManager.RemoveProjectile(projectile);
		}
	}
}

void ProjectileManager::DrawProjctiles()
{
	for (Projectile projectile : m_Projectiles)
	{
		projectile.Draw();
	}
}

void ProjectileManager::RemoveProjectile(Projectile projectile)
{
	for (int i = 0; i < g_ProjectileManager.GetProjectileCount(); i++)
	{
		if (g_ProjectileManager.m_Projectiles[i].GetId() == projectile.GetId())
		{
			g_ProjectileManager.m_Projectiles.erase(m_Projectiles.begin() + i);
		}
	}
}
#pragma endregion ownDefinitions