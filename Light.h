#pragma once

#include"libs.h"

class Light
{
protected:
	float intensity;
	glm::vec3 color;

public:
	Light(float intensity, glm::vec3 color)
	{
		this->intensity = intensity;
		this->color = color;
	}
	
	~Light()
	{

	}

	//Functions
	virtual void sendToShader(Shader& program) = 0;
};

class PointLight : public Light
{
protected:
	glm::vec3 position;

public:
	PointLight(glm::vec3 position, float intensity, glm::vec3 color)
		: Light(intensity, color)
	{
		this->position = position;
	}

	~PointLight()
	{

	}

	void sendToShader(Shader& program)
	{
		program.setVec3f(this->position, "pointlight.position");
		program.set1f(this->intensity, "pointlight.intensity");
		program.setVec3f(this->color, "pointlight.color");
	}
};