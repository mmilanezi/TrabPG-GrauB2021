/*
Usando de base as classes da professora para executar a aplicação de edição de imagens.
Matheus Grassi Milanezi
*/

#include "SceneManager.h"
#include <iostream>
#include <string>

//static controllers for mouse and keyboard
static bool keys[1024];
static bool resized;
static GLuint width, height;




int SceneManager::getOp() {
	return op;
}
void SceneManager::setOp(int opcao) {
	op = opcao;
}

string SceneManager::getNomeFoto01() {
	return nomeFoto01;
}

string SceneManager::getNomeFoto02() {
	return nomeFoto02;
}

string SceneManager::getNomeFoto03() {
	return nomeFoto03;
}

void SceneManager::setNomeFoto01(string nomef) {
	nomeFoto01 = nomef;
}

void SceneManager::setNomeFoto02(string nomef) {
	nomeFoto02 = nomef;
}
void SceneManager::setNomeFoto03(string nomef) {
	nomeFoto03 = nomef;
}




SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::initialize(GLuint w, GLuint h)
{
	width = w;
	height = h;
	
	// GLFW - GLEW - OPENGL general setup -- TODO: config file
	initializeGraphics();

}

void SceneManager::initializeGraphics()
{
	// Init GLFW
	glfwInit();

	// Create a GLFWwindow object that we can use for GLFW's functions
	window = glfwCreateWindow(width, height, "Programa de edicao de imagens         version ALPHA 1.3.8 ", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);

	//Setando a callback de redimensionamento da janela
	glfwSetWindowSizeCallback(window, resize);
	
	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;

	}

	// Build and compile our shader program - aqui declarar outros shaders
	if (op == 0) {
		addShader00("../shaders/transformations.vs", "../shaders/filtroNormal.frag");
		cout << "entrou aqui";
	}
	if (op == 1) {
		addShader00("../shaders/transformations.vs", "../shaders/filtroRosa.frag");
	}
	if (op == 2) {
		addShader00("../shaders/transformations.vs", "../shaders/filtroAmarelo.frag");
	}
	if (op == 3) {
		addShader00("../shaders/transformations.vs", "../shaders/filtroCinza.frag");
	}
	if (op == 4) {
		addShader00("../shaders/transformations.vs", "../shaders/filtroVerde.frag");
	}
	if (op == 5) {
		addShader00("../shaders/transformations.vs", "../shaders/filtroLaranja.frag");
	}
	if (op == 6) {
		addShader00("../shaders/transformations.vs", "../shaders/filtroAzul.frag");
	}
	if (op == 7) {
		addShader00("../shaders/transformations.vs", "../shaders/filtroArcoIris.frag");
	}
	
	
	/*
	
	addShader01("../shaders/transformations.vs", "../shaders/filtroRosa.frag");
	addShader02("../shaders/transformations.vs", "../shaders/filtroAmarelo.frag");
	addShader03("../shaders/transformations.vs", "../shaders/filtroCinza.frag");
	addShader04("../shaders/transformations.vs", "../shaders/filtroVerde.frag");
	addShader05("../shaders/transformations.vs", "../shaders/filtroLaranja.frag");
	addShader06("../shaders/transformations.vs", "../shaders/filtroAzul.frag");
	addShader07("../shaders/transformations.vs", "../shaders/filtroArcoIris.frag");



	*/
	

	//setup the scene -- LEMBRANDO QUE A DESCRIÇÃO DE UMA CENA PODE VIR DE ARQUIVO(S) DE 
	// CONFIGURAÇÃO
	setupScene();

	resized = true; //para entrar no setup da câmera na 1a vez

}

void SceneManager::addShader00(string vFilename, string fFilename)
{
	shader00 = new Shader (vFilename.c_str(), fFilename.c_str());//normal
	

}
/*

void SceneManager::addShader01(string vFilename, string fFilename)
{

	shader01 = new Shader(vFilename.c_str(), fFilename.c_str());//rosa

}

void SceneManager::addShader02(string vFilename, string fFilename)
{

	shader02 = new Shader(vFilename.c_str(), fFilename.c_str());//amarelo

}

void SceneManager::addShader03(string vFilename, string fFilename)
{
	shader03 = new Shader(vFilename.c_str(), fFilename.c_str());//cinza


}

void SceneManager::addShader04(string vFilename, string fFilename)
{

	shader04 = new Shader(vFilename.c_str(), fFilename.c_str());//verde

}

void SceneManager::addShader05(string vFilename, string fFilename)
{

	shader05 = new Shader(vFilename.c_str(), fFilename.c_str());//laranja

}
void SceneManager::addShader06(string vFilename, string fFilename)
{
	shader06 = new Shader(vFilename.c_str(), fFilename.c_str());//azul


}

void SceneManager::addShader07(string vFilename, string fFilename)
{

	shader07 = new Shader(vFilename.c_str(), fFilename.c_str());//arco-iris

}



*/




void SceneManager::key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			keys[key] = true;
		else if (action == GLFW_RELEASE)
			keys[key] = false;
	}
}

void SceneManager::resize(GLFWwindow * window, int w, int h)
{
	width = w;
	height = h;
	resized = true;

	// Define the viewport dimensions
	glViewport(0, 0, width, height);
}


void SceneManager::update()
{
	if (keys[GLFW_KEY_ESCAPE])
		glfwSetWindowShouldClose(window, GL_TRUE);


	//AQUI aplicaremos as transformações nos sprites
	
	//altera o angulo do segundo objeto
	objects[1]->setAngle((float)glfwGetTime());
}

void SceneManager::render()
{
	// Clear the colorbuffer
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	if (resized) //se houve redimensionamento na janela, redefine a projection matrix
	{
		setupCamera2D();
		resized = false;
	}

	//atualiza e desenha os Sprites

	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->update();
		objects[i]->draw();
	}
	

}

void SceneManager::run()
{
	//GAME LOOP
	while (!glfwWindowShouldClose(window))
	{
		
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		//Update method(s)
		update();

		//Render scene
		render();
		
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
}

void SceneManager::finish()
{
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
}


void SceneManager::setupScene()
{
	


	

	//Criação dos Sprites iniciais -- pode-se fazer métodos de criação posteriormente
	
	//Mínimo: posicao e escala e ponteiro para o shader
	Sprite* obj = new Sprite;
	obj->setPosition(glm::vec3(200.0f, 300.0f, 0.0));
	obj->setDimension(glm::vec3(200.0f, 200.0f, 1.0f)); //note que depois podemos reescalar conforme tamanho da sprite
	obj->setShader(shader00);
	objects.push_back(obj); //adiciona o primeiro obj

	//Adicionando mais um
	obj = new Sprite;
	obj->setPosition(glm::vec3(400.0f, 300.0f, 0.0));
	obj->setDimension(glm::vec3(200.0f, 200.0f, 1.0f));
	obj->setShader(shader00);
	objects.push_back(obj); //adiciona o segundo obj

	//Adicionando mais um
	obj = new Sprite;
	obj->setPosition(glm::vec3(600.0f, 300.0f, 0.0));
	obj->setDimension(glm::vec3(200.0f, 200.0f, 1.0f));
	obj->setShader(shader00);
	objects.push_back(obj); //adiciona o terceiro obj

	//chamada de menu para inserção de fotos.

	

	//Carregamento das texturas (pode ser feito intercalado na criação)
	//Futuramente, utilizar classe de materiais e armazenar dimensoes, etc
	unsigned int texID;
	texID = loadTexture("../textures/" + nomeFoto01);
	objects[0]->setTexture(texID);
	texID = loadTexture("../textures/" + nomeFoto02);
	objects[1]->setTexture(texID);
	texID = loadTexture("../textures/" + nomeFoto03);
	objects[2]->setTexture(texID);

	//Definindo a janela do mundo (ortho2D)
	ortho2D[0] = 0.0f; //xMin
	ortho2D[1] = 800.0f; //xMax
	ortho2D[2] = 0.0f; //yMin
	ortho2D[3] = 600.0f; //yMax

	//Habilita transparência
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void SceneManager::setupCamera2D() //TO DO: parametrizar aqui
{
	float zNear = -1.0, zFar = 1.0; //estão fixos porque não precisamos mudar

	projection = glm::ortho(ortho2D[0], ortho2D[1], ortho2D[2], ortho2D[3], zNear, zFar);


	//Obtendo o identificador da matriz de projeção para enviar para o shader
	GLint projLoc = glGetUniformLocation(shader00->ID, "projection");
	
	//Enviando a matriz de projeção para o shader
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

unsigned int SceneManager::loadTexture(string filename)
{
	unsigned int texture;

	// load and create a texture 
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
										   // set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// load image, create texture and generate mipmaps
	int width, height, nrChannels;
	
	unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);

	//criar aqui o for para percorrer a foto
	
	if (data)
	{
		//int size = width * height * nrChannels;

		//for (int i = 0; i < size; i += nrChannels) {

		//	data[i] = 255; //canal R
		//	data[i + 1] = 0; //canal G
		//	data[i + 2] = 0; // canal B
		//	//data[i + 3] = 0; // canal alpha caso tenha


		//}



		if (nrChannels == 3) //jpg, bmp
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
		else //png
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

	glActiveTexture(GL_TEXTURE0);

	return texture;
}


