#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include<glew.h>
#include<glfw3.h>

#include<glm.hpp>
#include<vec2.hpp>
#include<vec3.hpp>
#include<vec4.hpp>
#include<mat4x4.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>

#include<SOIL2.h>

#include"Shader.h"

struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 texcoord;
	glm::vec3 normal;
};