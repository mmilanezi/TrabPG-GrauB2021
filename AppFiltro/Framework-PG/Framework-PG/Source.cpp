/* Hello Transforms - código inicial fornecido em https://learnopengl.com/#!Getting-started/Hello-Triangle 
 *
 * Adaptado por Rossana Baptista Queiroz
 * para a disciplina de Computação Gráfica - Jogos Digitais - Unisinos
 * Versão inicial: 7/4/2017
 * Última atualização em 14/03/2018
 *
 */

using namespace std;

#include "SceneManager.h"
#include <string>
int op;
string nomeFoto01;
string nomeFoto02;
string nomeFoto03;

// The MAIN function, from here we start the application and run the game loop
int main()
{
	//menu de interação com o usuario via console.

	cout << "\n AppFiltro \n" << endl;
	cout << "Desenvolvido por Matheus Milanezi \n" << endl;
	cout << "Version Alpha 1.4.2\n" << endl;
	cout << "Instrucoes de uso: \n" << endl;
	cout << "Insira o nome da foto a ser modificada!\n" << endl;
	cout << "A foto deve estar dentro da pasta 'textures' antes da execucao do app.\n" << endl;
	cout << "O nome deve ser escrito junto do tipo.\n" << endl;
	cout << "Exemplo: mario.png \n" << endl;
	cout << "Exemplo: lena.png \n" << endl;

	cout << "Digite o nome da primeira foto \n" << endl;
	std::cin >> nomeFoto01;
	cout << "\nDigite o nome da segunda foto \n" << endl;
	std::cin >> nomeFoto02;
	cout << "\nDigite o nome da terceira foto \n" << endl;
	std::cin >> nomeFoto03;

	cout << "\nAgora vamos selecionar um filtro na imagem.\n Digite o numero do filtro sendo 0 sem filtro ou um dos 7 disponiveis" << endl;
	cout << "\nDigite o numero do filtro. \n" << endl;

	cout << "Filtros disponiveis:. \n 0 - sem filtro \n 1 - filtro rosa \n 2 - filtro amarelo \n 3 - filtro cinza\n 4 - filtro verde \n 5 - filtro laranja \n 6 - filtro azul \n 7 - filtro Arco-Iris " << endl;

	std::cin >> op;
	
	

	SceneManager *scene = new SceneManager;
	scene->setOp(op);
	scene->setNomeFoto01(nomeFoto01);
	scene->setNomeFoto02(nomeFoto02);
	scene->setNomeFoto03(nomeFoto03);


	scene->initialize(800, 600);

	scene->run();

	scene->finish();
	
	return 0;
}


