#include "CShader.h"



CShader::CShader()
{
	vertexShader = 0;
	fragShader = 0;
	geometryShader = 0;
}

CShader::CShader(const char * vertextFile, const char * fragmentFile)
{
	this->vertextFile = vertextFile;
	this->fragmentFile = fragmentFile;
}

CShader::CShader(const char * vertextFile, const char* geometryFile, const char * fragmentFile)
{
	this->vertextFile = vertextFile;
	this->geometryFile = geometryFile;
	this->fragmentFile = fragmentFile;

	vertexShader = LoadShader(GL_VERTEX_SHADER, vertextFile);

	if (geometryFile != "")
		geometryShader = LoadShader(GL_GEOMETRY_SHADER, geometryFile);

	fragShader = LoadShader(GL_FRAGMENT_SHADER, fragmentFile);

	this->LinkToPrograma(vertexShader, geometryShader, fragShader);
	
	
	DeleteShader(vertexShader);
	DeleteShader(fragShader);
	DeleteShader(geometryShader);
	
}


CShader::~CShader()
{
	DeleteProgram(CreateProgram());
}

string CShader::LoadFileName(const char * filename)
{
	char infoLog[512];
	GLint sucess;
	string temp = "";
	string src = "";

	ifstream in_file;

	// vertex 
	in_file.open(filename);

	if (in_file.is_open())
	{
		while (getline(in_file, temp))
		{
			src += temp + "\n";
		}
	}
	else
	{
		cout << " ERROR::LOADSHADERS::COULD_NOT_OPEN_FILE" << filename << "\n";

	}
	in_file.close();


	return src;
}

GLuint CShader::LoadShader(GLenum type, const char * fileName)
{	
	

	char infoLog[512];
	GLint sucess;


	GLuint shader = CreateShader(type);
	string str_src = this->LoadFileName(fileName);
	const GLchar* src = str_src.c_str();
	ShaderSource(shader, 1, &src, NULL);
	CompileShader(shader);

	
	GetShaderiv(shader, GL_COMPILE_STATUS, &sucess);

	if (!sucess)
	{
		GetShaderInfoLog(shader, 512, NULL, infoLog);
		cout << " ERROR::SHADERS::COULD_NOT_COMPILE_SHADER" << fileName << "\n";
		cout << infoLog << "\n";
		
	}

	return shader;
}

void CShader::LinkToPrograma(GLuint vertexShader, GLuint geometryShader, GLuint fragmentShader)
{
	char infoLog[512];
	GLint sucess;

	CreateProgram();
	/*this->id = glCreateProgram();*/
	
	UsePrograma();
	/*glUseProgram(this->id);*/
	
	AttachShader(CreateProgram(), vertexShader);

	if (geometryShader)
		AttachShader(CreateProgram(), geometryShader);

	AttachShader(CreateProgram(), fragmentShader);
	
	LinKPrograma(CreateProgram());

	GetProgramiv(CreateProgram(), GL_LINK_STATUS, sucess);

	if (!sucess)
	{
		GetProgramInfoLog(CreateProgram(), 512, NULL, infoLog);
		cout << " ERROR::LOADSHADERS::COULD_NOT_LINK_PROGRAM" << "\n";
		cout << infoLog << "\n";
	}

	/*glUseProgram(0);*/
	UnUsed();
}

GLuint CShader::CreateProgram()
{
	this->id = glCreateProgram();
	return this->id;
}

bool CShader::AttachShader(GLuint id, GLuint shader)
{
	this->id = id;
	m_vertex = shader;

	glAttachShader(this->id, m_vertex);
	return true;
}

void CShader::LinKPrograma(GLuint id)
{
	this->id = id;
	glLinkProgram(this->id);
}

void CShader::UsePrograma()
{
	/*glUseProgram(this->id);*/
	glUseProgram(CreateProgram());
}

void CShader::UnUsed()
{
	glUseProgram(0);
}

void CShader::GetProgramiv(GLuint program, GLenum pname, GLint& param)
{
	glGetProgramiv(program, pname, &param);
}


void CShader::GetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog)
{
	glGetProgramInfoLog(program, bufSize, length, infoLog);
}

void CShader::GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog)
{
	glGetShaderInfoLog(shader, bufSize, length, infoLog);
}

void CShader::GetShaderiv(GLuint shader, GLenum pname, GLint * param)
{
	glGetShaderiv(shader, pname, param);
}

void CShader::CompileShader(GLuint shader)
{
	glCompileShader(shader);
}

void CShader::ShaderSource(GLuint shader, GLsizei count, const GLchar * const * string, const GLint * length)
{
	glShaderSource(shader, count, string, length);
}

GLuint CShader::CreateShader(GLenum shaderType)
{
	this->m_shader = shaderType;
	glCreateShader(this->m_shader);

	return this->m_shader;
}

void CShader::DeleteShader(GLuint shader)
{
	glDeleteShader(shader);
}

void CShader::DeleteProgram(GLuint id)
{
	glDeleteProgram(id);
}
