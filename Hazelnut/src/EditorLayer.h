#pragma once

#include <Hazel.h>
#include "Hazel/Renderer/EditorCamera.h"
#include "Panels/SceneHierarchyPanel.h"
#include "Panels/ContentBrowserPanel.h"

namespace Hazel
{

	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;
		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		void OnImGuiRender() override;
		void OnEvent(Event& event) override;
	private:
		bool OnMouseButtonPressed(MouseButtonPressedEvent& event);
		bool OnKeyPressed(KeyPressedEvent& event);

		void OnScenePlay();
		void OnSceneStop();
		void OnSceneSimulate();

		void OnDuplicateEntity();
		void OnOverlayRender();

		// UI Panels
		void UI_ToolBar();

		void NewScene();
		void OpenScene();
		void OpenScene(const std::filesystem::path& path);
		void SerializeScene(const std::filesystem::path& path);
		void Save();
		void SaveAs();
	private:
		OrthographicCameraController m_CameraController;

		// Temp
		Ref<Framebuffer> m_Framebuffer;

		Ref<Scene> m_ActiveScene;
		Ref<Scene> m_EditorScene;

		Entity m_SquareEntity;
		Entity m_CameraEntity;
		Entity m_SecondCamera;
		Entity m_HoveredEntity;

		EditorCamera m_EditorCamera;

		bool m_PrimaryCamera = true;
		bool m_ShowPhysicsColliders = false;

		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };
		glm::vec2 m_ViewportBounds[2];
		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

		bool m_ViewportFocused = false, m_ViewportHovered = false;

		int m_GizmoType = -1;

		std::filesystem::path m_ActiveScenePath;

		enum class SceneState
		{
			Edit = 0,
			Play = 1,
			Simulate = 2
		};

		SceneState m_SceneState = SceneState::Edit;

		// Panels
		SceneHierarchyPanel m_SceneHierarchyPanel;
		ContentBrowserPanel m_ContentBrowserPanel;

		// Editor resources
		Ref<Texture2D> m_IconPlay;
		Ref<Texture2D> m_IconStop;
		Ref<Texture2D> m_IconSimulate;
	};

}