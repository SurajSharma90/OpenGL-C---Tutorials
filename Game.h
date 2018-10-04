#pragma once

#include "libs.h"

//ZOOOOOOOOOOOM IN BEFORE RECORDING!

//ENUMERATIONS
enum shader_enum { SHADER_CORE_PROGRAM = 0 };
enum texture_enum { TEX_PUSHEEN0 = 0, TEX_CONTAINER1 };
enum material_enum { MAT_1 = 0 };
enum mesh_enum { MESH_QUAD = 0 };

class Game
{
private:
//Variables
	//Window
	GLFWwindow* window;
	const int WINDOW_WIDTH;
	const int WINDOW_HEIGHT;
	int framebufferWidth;
	int framebufferHeight;

	//OpenGL Context
	const int GL_VERSION_MAJOR;
	const int GL_VERSION_MINOR;

	//Matrices
	glm::mat4 ViewMatrix;
	glm::vec3 camPosition;
	glm::vec3 worldUp;
	glm::vec3 camFront;

	glm::mat4 ProjectionMatrix;
	float fov;
	float nearPlane;
	float farPlane;

	//Shaders
	std::vector<Shader*> shaders;

	//Textures
	std::vector<Texture*> textures;

	//Materials
	std::vector<Material*> materials;

	//Meshes
	std::vector<Mesh*> meshes;

	//Lights
	std::vector<glm::vec3*> lights;

//Private functions
	void initGLFW();
	void initWindow(
		const char* title,
		bool resizable
	);
	void initGLEW(); //AFTER CONTEXT CREATION!!!
	void initOpenGLOptions();
	void initMatrices();
	void initShaders();
	void initTextures();
	void initMaterials();
	void initMeshes();
	void initLights();
	void initUniforms();

	void updateUniforms();

//Static variables

public:
//Constructors / Destructors
	Game(
		const char* title,
		const int WINDOW_WIDTH, const int WINDOW_HEIGHT,
		const int GL_VERSION_MAJOR, const int GL_VERSION_MINOR,
		bool resizable
	);
	virtual ~Game();

//Accessors
	int getWindowShouldClose();

//Modifiers
	void setWindowShouldClose();

//Functions
	void update();
	void render();

//Static functions
	static void framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH);
	static void updateInput(GLFWwindow* window);
	static void updateInput(GLFWwindow* window, Mesh &mesh);
};