#pragma once

#include "Shader.h"
#include "Sprite.h" 

#include <iostream>
#include <string>


// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

using namespace std;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	
	//GLFW callbacks - PRECISAM SER EST?TICAS
	//Para isso, as vari?veis que modificamos dentro deles
	//tamb?m precisam ser e est?o no in?cio do SceneManager.cpp
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
	static void resize(GLFWwindow* window, int width, int height);

	//M?todos pricipais
	void initialize(GLuint width, GLuint height);
	void run();
	void finish();

	//M?todos chamados no run (ciclo)
	void update();
	void render();

	//M?todos para configura??o e carregamento dos elementos da cena
	void initializeGraphics();
	void addShader00(string vFilename, string fFilename);
	void addShader01(string vFilename, string fFilename);
	void addShader02(string vFilename, string fFilename);
	void addShader03(string vFilename, string fFilename);
	void addShader04(string vFilename, string fFilename);
	void addShader05(string vFilename, string fFilename);
	void addShader06(string vFilename, string fFilename);
	void addShader07(string vFilename, string fFilename);

	int getOp();
	void setOp(int op);
	
	string getNomeFoto01();
	string getNomeFoto02();
	string getNomeFoto03();
	void setNomeFoto01(string nome);
	void setNomeFoto02(string nome);
	void setNomeFoto03(string nome);


	void setupScene(); //antigo setupGeometry
	void setupCamera2D();
	unsigned int loadTexture(string filename); 

private:
	
	//Janela GLFW (por enquanto, assumimos apenas 1 inst?ncia)
	GLFWwindow *window;

	//Programa de shader (por enquanto, assumimos apenas 1 inst?ncia)
	//aqui da pra por mais shaders
	Shader * shader00;
	Shader * shader01;
	Shader * shader02;
	Shader * shader03;
	Shader * shader04;
	Shader * shader05;
	Shader * shader06;
	Shader * shader07;
	
	//variaveis privadas de carregamento de nome de foto
	//const char * caminhoFoto;
	string nomeFoto01;
	string nomeFoto02;
	string nomeFoto03;
	
	string nomeShader01;
	
	int op;

	//C?mera 2D - Matriz de proje??o (ortogr?fica) com os limites em x,y
	glm::vec4 ortho2D; //xmin, xmax, ymin, ymax
	glm::mat4 projection;
	glm::mat4 projection01;

	//Nossos objetos (sprites) da cena
	vector <Sprite*> objects;

};

