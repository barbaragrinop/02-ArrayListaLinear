
#include <iostream>
using namespace std;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void buscarElemento();
bool verificaSeExiste(int num);
//--------------------------

const int MAX = 5;
int lista[MAX]{};
int nElementos = 0;
int opcaoEscolhida;

int main()
{
	menu();


}

bool verificaSeExiste(int num) {
	for (int x = 0; x <= MAX; x++) {
		if (num == lista[x]) {
			return true;
		}
	}
	return false;
}

void menu()
{
	int op = 0;
	while (op != 7)
	{
		system("cls"); // somente no windows
		cout << "Menu Lista Linear";
		cout << endl
			 << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1:
			inicializar();
			break;
		case 2:
			exibirQuantidadeElementos();
			break;
		case 3:
			exibirElementos();
			break;
		case 4:
			buscarElemento();
			break;
		case 5:
			inserirElemento();
			break;
		case 6:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	nElementos = 0;
	cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos()
{

	cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos()
{
	if (nElementos == 0)
	{
		cout << " A lista esta vazia \n";
	}
	else
	{
		cout << "Elementos: \n";
		for (int n = 0; n < nElementos; n++)
		{
			cout << lista[n] << endl;
		}
	}
}

void inserirElemento()
{
	if (nElementos < MAX)
	{
		int valorInserido = 0;
		int posicao = -1;
		cout << "Digite o elemento: ";
		cin >> valorInserido;
		if (!verificaSeExiste(valorInserido)) {
			lista[nElementos] = valorInserido;
			nElementos++;
		}
		else {
			cout << "\n\nVALOR JA EXISTENTE NA LISTA. Por favor, insira outro.\n\n";
			inserirElemento();
		}
	}
	else
	{
		cout << "Lista cheia";
	}
}

void buscarElemento()
{
	cout << "Digite o elemento a ser buscado: ";
	cin >> opcaoEscolhida;
	bool existe = false;
	int posicao = -1;
	for (int x = 0; x < MAX; x++)
	{
		if (opcaoEscolhida == lista[x])
		{
			existe = true;
			posicao = x;
		}
	}

	if (existe)
	{
		cout << "\n\nValor " << opcaoEscolhida << " existe na lista\n\n";
		cout << "Posicao: " << posicao << endl;
	}
	if (!existe)
		cout << "\n\nValor " << opcaoEscolhida << " nao existe na lista\n\n";
}

