#pragma once
#include <glm/glm.hpp>
// #include <gl\GL.h>
#include <gl3w\gl3w.h>
#include <glm\gtc\matrix_transform.hpp>

enum ECameraMovementType
{
	UNKNOWN,
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};


class Camera
{
private:
	// Default camera values
	const float zNEAR = 0.1f;
	const float zFAR = 500.f;
	const float YAW = -90.0f;
	const float PITCH = 0.0f;
	const float FOV = 45.0f;
	glm::vec3 startPosition;

	const float cameraSpeedFactor = 2.5f;
	const float mouseSensitivity = 0.1f;

	// Perspective properties
	float zNear;
	float zFar;
	float FoVy;
	int width;
	int height;
	bool isPerspective;

	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 right;
	glm::vec3 up;
	glm::vec3 worldUp;

	// Euler Angles
	float yaw;
	float pitch;

	bool bFirstMouseMove = true;
	float lastX = 0.f, lastY = 0.f;

public:
	Camera(const int width, const int height, const glm::vec3& position);
	void Set(const int width, const int height, const glm::vec3& position);

	void Reset(const int width, const int height);

	void Reshape(int windowWidth, int windowHeight);

	const glm::vec3 GetPosition() const;

	const glm::mat4 GetViewMatrix() const;

	const glm::mat4 GetProjectionMatrix() const;

	void ProcessKeyboard(ECameraMovementType direction, float deltaTime);

	void MouseControl(float xPos, float yPos, bool leftPress);

	void ProcessMouseScroll(float yOffset);

	void screen(int width, int height);


	const glm::vec2 screenSize() const { return _screenSize; }
	const glm::vec2 renderSize() const { return _renderSize; }

private:
	void ProcessMouseMovement(float xOffset, float yOffset, bool constrainPitch = true);

	void UpdateCameraVectors();

	// Screen size
	glm::vec2 _screenSize;
	// Size use for render targets.
	glm::vec2 _renderSize;

	int _verticalResolution;
	
};