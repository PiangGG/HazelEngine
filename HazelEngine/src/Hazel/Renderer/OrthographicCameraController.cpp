#include "hzpch.h"
#include "Hazel/Renderer/OrthographicCameraController.h"
#include "Hazel/Core/Input.h"
#include "Hazel/Core/KeyCodes.h"
namespace Hazel 
{
	OrthographicCameraController::OrthographicCameraController(float aspectRatio,bool rotation)
		:m_AspectRatio(aspectRatio), m_Bounds({ -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel }), m_Camera(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top), m_Rotation(rotation)
	{

	}
	void OrthographicCameraController::OnUpdate(Timestep ts)
	{
		HZ_PROFILE_FUNCTION();

		//HZ_CORE_TRACE("Delta time:{0}s ({1}ms)",ts.GetSeconds(),ts.GetMillseconds());
		if (Input::IsKeyPressed(HZ_KEY_A))
			m_CameraPosition.x -= m_CameraTranslationSpeed * ts;
		else if (Hazel::Input::IsKeyPressed(HZ_KEY_D))
			m_CameraPosition.x += m_CameraTranslationSpeed * ts;

		if (Input::IsKeyPressed(HZ_KEY_W))
			m_CameraPosition.y -= m_CameraTranslationSpeed * ts;
		else if (Input::IsKeyPressed(HZ_KEY_S))
			m_CameraPosition.y += m_CameraTranslationSpeed * ts;

		if (m_Rotation)
		{
			if (Input::IsKeyPressed(HZ_KEY_Q))
				m_CameraRotation += m_CameraRotationSpeed * ts;
			if (Input::IsKeyPressed(HZ_KEY_E))
				m_CameraRotation -= m_CameraRotationSpeed * ts;
			m_Camera.SetRotation(m_CameraRotation);
		}
		
		//

		m_Camera.SetPosition(m_CameraPosition);
		m_CameraTranslationSpeed = m_ZoomLevel;
	}
	void OrthographicCameraController::OnEvent(Event& e)
	{
		HZ_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(HZ_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvnet>(HZ_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));

		dispatcher.Dispatch<MouseButtonPressedEvent>(HZ_BIND_EVENT_FN(OrthographicCameraController::OnMouseButtonPresseded));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(HZ_BIND_EVENT_FN(OrthographicCameraController::OnMouseButtonReleaseded));
		dispatcher.Dispatch<MouseMovedEvent>(HZ_BIND_EVENT_FN(OrthographicCameraController::OnMouseMovedCameraController));
	}
	void OrthographicCameraController::OnResize(float width, float height)
	{
		m_AspectRatio = width / height;
		m_Bounds = { -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel };
		m_Camera.SetProjection(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top);
	}
	bool OrthographicCameraController::OnMouseScrolled(Hazel::MouseScrolledEvent& e)
	{
		HZ_PROFILE_FUNCTION();

		m_ZoomLevel -= e.GetYOffset()*0.5f;
		m_ZoomLevel = std::max(m_ZoomLevel,0.25f);
		m_Bounds = { -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel };
		m_Camera.SetProjection(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top); 
		return false;
	}
	bool OrthographicCameraController::OnWindowResized(Hazel::WindowResizeEvnet& e)
	{
		HZ_PROFILE_FUNCTION();

		OnResize((float)e.GetWidth(),(float)e.GetHeight());
		return false;
	}
	bool OrthographicCameraController::OnMouseButtonReleaseded(Hazel::MouseButtonReleasedEvent& e)
	{
		MouseLeftButtonPressed = false;
		return false;
	}
	bool OrthographicCameraController::OnMouseMovedCameraController(Hazel::MouseMovedEvent& e)
	{
		if (MouseLeftButtonPressed)
		{
			//m_CameraPosition.x += (m_Bounds.GetWidth());
			//m_CameraPosition.y += (m_Bounds.GetHeight());
			//HZ_CORE_INFO("{0}{1}", m_CameraPosition.x, m_CameraPosition.y);
		}
		return false;
	}
	bool OrthographicCameraController::OnMouseButtonPresseded(Hazel::MouseButtonPressedEvent& e)
	{
		MouseLeftButtonPressed = true;
		return false;
	}
}