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
	float constant;
	float linear;
	float quadratic;

public:
	PointLight(glm::vec3 position, float intensity = 1.f, glm::vec3 color = glm::vec3(1.f),
		float constant = 1.f, float linear = 0.045f, float quadratic = 0.0075f)
		: Light(intensity, color)
	{
		this->position = position;
		this->constant = constant;
		this->linear = linear;
		this->quadratic = quadratic;
	}

	~PointLight()
	{

	}

	void setPosition(const glm::vec3 position)
	{
		this->position = position;
	}

	void sendToShader(Shader& program)
	{
		program.setVec3f(this->position, "pointLight.position");
		program.set1f(this->intensity, "pointLight.intensity");
		program.setVec3f(this->color, "pointLight.color");
		program.set1f(this->constant, "pointLight.constant");
		program.set1f(this->linear, "pointLight.linear");
		program.set1f(this->quadratic, "pointLight.quadratic");
	}
};