#pragma once
#include "Hazel/Renderer/OrthographicCamera.h"
#include "Hazel/Core/Timestep.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/MouseEvent.h"

namespace Hazel 
{
	struct OrthographicCameraBounds
	{
		float Left, Right;
		float Bottom, Top;

		float GetWidth() { return  Right - Left; }
		float GetHeight() { return  Top - Bottom; }
	};

	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRatio,bool rotation=false);

		void OnUpdate(Timestep ts);
		void OnEvent(Event& e);

		const OrthographicCamera& GetCamera() const { return m_Camera; }
		OrthographicCamera& GetCamera(){ return m_Camera; }

		void SetZoomLevel(float level) { m_ZoomLevel = level; };
		float GetZoomLevel() const{return m_ZoomLevel;}

		const OrthographicCameraBounds& GetBounds() { return m_Bounds; }
	private:
		bool OnMouseScrolled(Hazel::MouseScrolledEvent& e);
		bool OnWindowResized(Hazel::WindowResizeEvnet& e);
	private:
		
		OrthographicCameraBounds m_Bounds;
		OrthographicCamera m_Camera;

		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
	
		bool m_Rotation;

		glm::vec3 m_CameraPosition = {0.0f,0.0f,0.0f};
		float m_CameraRotation = 0.0f;
		float m_CameraTranslationSpeed = 5.0f, m_CameraRotationSpeed = 180.0f;
	};
}
