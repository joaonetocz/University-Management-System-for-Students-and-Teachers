//-------------------------------------------------------------------------//
// JOAO SOARES FARIAS NETO;
// PROJETO DA DISCIPLINA TÉCNICAS DE PROGRAMAÇÃO - UNIDADE 3;
// MATRÍCULA: ********;
// UNIVERSIDADE FEDERAL DA PARAÍBA - UFPB;
//-------------------------------------------------------------------------//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>

using namespace std;

void print_status(int);
void print_tipo_estagio(int);
void print_mes();
void print_top_cadastro();
void print_top_estagio();
void print_main_busca();
void print_top_busca();
void creditos();

//criação da struc aluno para cadastro das seguintes informações: nome, matricula e periodo letivo;
class aluno
{
	//declaração de membros publicos para que possam ser alterados em qualquer escopo que a classe
	//eh visivel. Assim, sera possivel alterar os dados cadastrados.
	public:
		char nome_aluno[100];
		long int matricula;
		int periodo_letivo;
		int pendencia;
		float ch_semanal;
		float ch_diaria;
		int dd_inicio, mm_inicio, aa_inicio;
		int dd_fim, mm_fim, aa_fim;
		int tipo_estagio;
		char local_estagio[50];
		char orientador[100];
		int status_estagio;

		aluno *anterior;
};

class estagio : public aluno
{
	public:

};

class ListaLigada
{
	private:
		aluno *fim;

	public:
		ListaLigada()		//função construtora;
		{
			fim = (aluno *)NULL;	//instancia do ponteiro aluno como vazio;
		}

	void novoaluno();
	void print();
	void salvar();
	aluno *busca(char nome[]);
	aluno *busca_mes(int mes);
	aluno *busca_mes_fim(int mes);
};

//Esta função membro é utilizada para cadastrar as novas informações dos alunos no programa;
void ListaLigada::novoaluno()
{
	aluno *novo_aluno = new aluno;
	cout<<endl;

	system("cls");
	print_top_cadastro();
	cout<<" Digite o nome do aluno: "<<endl;
	cin.getline(novo_aluno->nome_aluno,100);
	//cin.ignore();

	system("cls");
	print_top_cadastro();
	cout<<" Digite a matricula do aluno: "<<endl;
	cin>>novo_aluno->matricula;
	cout<<endl;
	cin.ignore();

	system("cls");
	print_top_cadastro();
	cout<<" Digite o periodo letivo do aluno: "<<endl;
	cin>>novo_aluno->periodo_letivo;
	cout<<endl;
	cin.ignore();

	system("cls");
	print_top_estagio();
	cout<<" Digite o tipo de estagio do aluno:"<<endl<<endl;
	cout<<" 1. Obrigatorio;"<<endl;
	cout<<" 2. Nao Obrigatorio;"<<endl;
	cin>>novo_aluno->tipo_estagio;
	cin.ignore();
	cout<<endl;

	system("cls");
	print_top_cadastro();
	cout<<" O aluno concluiu todas as disciplinas da graduacao?"<<endl<<endl;
	cout<<" 1. Sim, nao existem pendencias."<<endl;
	cout<<" 2. Nao, o aluno ainda esta matriculado em disciplinas."<<endl;
	cin>>novo_aluno->pendencia;
	cin.ignore();

	if(novo_aluno->pendencia == 1)
	{
		do
		{
			system("cls");
			print_top_estagio();
			cout<<" Digite a carga horaria SEMANAL do estagio (horas): "<<endl;
			cout<<" Obs.: A CH semanal nao deve exceder 40 horas."<<endl;
			cin>>novo_aluno->ch_semanal;
			cin.ignore();
			cout<<endl;

			if(novo_aluno->ch_semanal > 40)
			{
				system("cls");
				print_top_estagio();
				cout<<endl;
				cout<<" Carga Horaria Invalida! A CH maxima permitida eh de 40 horas semanais."<<endl<<endl;
				system("pause");
			}


		}while(novo_aluno->ch_semanal > 40);
	}

	if(novo_aluno->pendencia == 2)
	{
		do
		{
			system("cls");
			print_top_estagio();
			cout<<" O aluno ainda possui pendencias na graduacao. A CH maxima permitida e de 30 horas semanais."<<endl<<endl;
			cout<<"Digite a carga horaria semanal do aluno: "<<endl;
			cin>>novo_aluno->ch_semanal;
			cin.ignore();

				if(novo_aluno->ch_semanal > 30)
				{
					system("cls");
					print_top_estagio();
					cout<<endl;
					cout<<" Carga Horaria Invalida! A CH maxima para este aluno e 30 horas semanais."<<endl<<endl;
					system("pause");
				}

			cout<<endl;
		}while(novo_aluno->ch_semanal > 30);
	}

	do
	{
		system("cls");
		print_top_estagio();
		cout<<" Digite a carga horaria DIARIA do estagio (horas): "<<endl;
		cout<<" Obs.: A CH minima e de 4 horas diarias e maxima de 6 horas diarias."<<endl;
		cin>>novo_aluno->ch_diaria;
		cin.ignore();
		if(novo_aluno->ch_diaria < 4 || novo_aluno->ch_diaria >6)
		{
			system("cls");
			print_top_estagio();
			cout<<endl;
			cout<<" Carga Horaria diaria nao permitida! Os requisitos para CH sao:"<<endl;
			cout<<" CH Minima: 4 horas diarias."<<endl;
			cout<<" CH Maxima: 6 horas diarias."<<endl<<endl;
			system("pause");
		}

		cout<<endl;
	}while(novo_aluno->ch_diaria < 4 || novo_aluno->ch_diaria > 6);

	system("cls");
	print_top_estagio();
	cout<<" Digite o local do estagio (cidade): "<<endl;
	cin.getline(novo_aluno->local_estagio,50);
	//cin.ignore();
	cout<<endl;

	system("cls");
	print_top_estagio();
	cout<<" Digite o nome do orientador do aluno estagiario: "<<endl;
	cin.getline(novo_aluno->orientador,100);

	system("cls");
	print_top_estagio();
	cout<<" Digite o DIA (numero) de INICIO do estagio: "<<endl;
	cin>>novo_aluno->dd_inicio;
	cin.ignore();
	cout<<endl;

	system("cls");
	print_top_estagio();
	cout<<" Digite o MES de INICIO do estagio: "<<endl<<endl;
	print_mes();
	cin>>novo_aluno->mm_inicio;
	cin.ignore();
	cout<<endl;

	system("cls");
	print_top_estagio();
	cout<<" Digite o ano de INICIO do estagio: "<<endl;
	cin>>novo_aluno->aa_inicio;
	cin.ignore();
	cout<<endl;

	system("cls");
	print_top_estagio();
	cout<<" Digite o dia do FIM do estagio: "<<endl;
	cin>>novo_aluno->dd_fim;
	cin.ignore();
	cout<<endl;

	system("cls");
	print_top_estagio();
	cout<<" Digite o MES do FIM do estagio: "<<endl<<endl;
	print_mes();
	cin>>novo_aluno->mm_fim;
	cin.ignore();
	cout<<endl;

	system("cls");
	print_top_estagio();
	cout<<" Digite o ano do FIM do estagio:"<<endl;
	cin>>novo_aluno->aa_fim;
	cin.ignore();
	cout<<endl;

	system("cls");
	print_top_estagio();
	cout<<" Digite o status do estagio:"<<endl<<endl;
	cout<<" 1. Aguardando Assinatura;"<<endl;
	cout<<" 2. Ativo;"<<endl;
	cout<<" 3. Concluido;"<<endl;
	cout<<" 4. Cancelado;"<<endl;
	cin>>novo_aluno->status_estagio;
	cin.ignore();

	novo_aluno->anterior = fim;
	fim = novo_aluno;
}

aluno * ListaLigada::busca_mes(int mes)
{
	aluno *atual = fim;
	aluno *busca_mes_OK = NULL;

	while(atual != NULL)
	{
		if(atual->mm_inicio == mes)
		{
			busca_mes_OK = atual;
		}

		atual = atual->anterior;

	}
	return busca_mes_OK;
}

aluno * ListaLigada::busca_mes_fim(int mes_fim_es)
{
	aluno *atual = fim;
	aluno *busca_mes_fim_OK = NULL;

	while(atual != NULL)
	{
		if(atual->mm_inicio == mes_fim_es)
		{
			busca_mes_fim_OK = atual;
		}

		atual = atual->anterior;

	}
	return busca_mes_fim_OK;
}

aluno * ListaLigada::busca(char nome[])
{
	aluno *atual = fim;
	aluno *buscaOK = NULL;

	while(atual != NULL)
	{
		if(strcmp(nome,atual->nome_aluno) == 0)
		{
			buscaOK = atual;
		}

		atual = atual->anterior;
	}

	return buscaOK;
}

void ListaLigada::salvar()
{
	aluno *atual = fim;

	fstream arquivo;
	arquivo.open("Aluno_Info.csv", ios::out | ios::app);
	arquivo<<"\n"<<atual->nome_aluno<<";"<<atual->matricula<<";"<<atual->periodo_letivo<<";"<<atual->tipo_estagio;
	arquivo.close();
}


//função criada para mostrar na tela todos os alunos cadastrados no sistema;
void ListaLigada::print()
{
	aluno *atual = fim;
	system("cls");
	cout<<endl;
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"                     >>> ALUNOS CADASTRADOS <<<                     "<<endl;
	cout<<"--------------------------------------------------------------------"<<endl<<endl;
	if(atual == NULL)
	{
		cout<<" Nao existem alunos cadastrados!"<<endl;
	}

	while(atual != NULL)
	{
		cout<<" Nome: "<<atual->nome_aluno<<"."<<endl;
		cout<<" Matricula: "<<atual->matricula<<"."<<endl;
		cout<<" Periodo Letivo: "<<atual->periodo_letivo<<"."<<endl;

		cout<<" Tipo de Estagio: ";
		print_tipo_estagio(atual->tipo_estagio);

		cout<<" CH Semanal: "<<atual->ch_semanal<<" Horas."<<endl;
		cout<<" CH Diaria: "<<atual->ch_diaria<<" Horas."<<endl;
		cout<<" Inicio da Vigencia: "<<atual->dd_inicio<<"/"<<atual->mm_inicio<<"/"<<atual->aa_inicio<<"."<<endl;
		cout<<" Fim da Vigencia: "<<atual->dd_fim<<"/"<<atual->mm_fim<<"/"<<atual->aa_fim<<"."<<endl;

		cout<<" Status do Estagio: ";
		print_status(atual->status_estagio);

		cout<<endl;
		atual = atual->anterior;

	}
	system("pause");
}

int main()
{
	ListaLigada li;
	char opcao;
	int op, op2, retornar, saida, dd, mm, aa, mes, MesFimEst;
	char aluno_teste[100];
	char busca[100];

	fstream arquivo;

	arquivo.open("Aluno_Info.csv",ios::in);

	do{
		system("cls");
		cout<<"--------------------------------------------------------------------"<<endl;
		cout<<"               UNIVERSIDADE FEDERAL DA PARAIBA - UFPB               "<<endl;
		cout<<"        CENTRO DE ENERGIAS ALTERNATIVAS E RENOVAVEIS - CEAR         "<<endl;
		cout<<"             DEPARTAMENTO DE ENGENHARIA ELETRICA - DEE              "<<endl;
		cout<<"            -GERENCIAMENTO DE ESTAGIOS SUPERVISIONADOS-             "<<endl;
		cout<<"--------------------------------------------------------------------"<<endl<<endl;
		cout<<" >>> MENU PRINCIPAL"<<endl<<endl;
		cout<<" 1. Buscar Aluno;"<<endl;
		cout<<" 2. Cadastrar Aluno;"<<endl;
		cout<<" 3. Editar Informacoes do Aluno;"<<endl;
		cout<<" 4. Visualizar Alunos Cadastrados;"<<endl;
		cout<<" 5. Sair do programa;"<<endl<<endl;
		cout<<"--------------------------------------------------------------------"<<endl<<endl;
		cout<<" Operacao: ";
		cin>>op;
		cin.ignore();

		switch(op)
		{
			case 1:
			do{
				system("cls");
				print_main_busca();
				cout<<" Realizar busca do aluno por: "<<endl<<endl;
				cout<<" 1. Nome;"<<endl;
				cout<<" 2. Mes de Inicio do Estagio;"<<endl;
				cout<<" 3. Mes de Fim do Estagio;"<<endl;
				cout<<" 4. Retornar ao Menu Principal;"<<endl<<endl;
				cout<<" Opcao: ";
				cin>>op2;
				cin.ignore();

				switch(op2)
				{
					case 1:
						system("cls");
						print_top_busca();
						cout<<" Digite o nome do aluno: "<<endl;
						cin.getline(busca,100);
						//cin.ignore();

						aluno *PtrBusca;
						PtrBusca = li.busca(busca);

						if(PtrBusca != NULL)
						{
							system("cls");
							print_top_busca();
							cout<<" Aluno: "<<PtrBusca->nome_aluno<<endl;
							cout<<" Matricula: "<<PtrBusca->matricula<<endl;
							cout<<" Periodo Letivo: "<<PtrBusca->periodo_letivo<<endl;
							cout<<" Tipo de Estagio: ";
							print_tipo_estagio(PtrBusca->tipo_estagio);

							cout<<" CH Semanal: "<<PtrBusca->ch_semanal<<" Horas."<<endl;
							cout<<" CH Diaria: "<<PtrBusca->ch_diaria<<" Horas."<<endl;
							cout<<" Inicio da Vigencia: "<<PtrBusca->dd_inicio<<"/"<<PtrBusca->mm_inicio<<"/"<<PtrBusca->aa_inicio<<"."<<endl;
							cout<<" Fim da Vigencia: "<<PtrBusca->dd_fim<<"/"<<PtrBusca->mm_fim<<"/"<<PtrBusca->aa_fim<<"."<<endl;

							cout<<" Status do Estagio: ";
							print_status(PtrBusca->status_estagio);

							cout<<endl<<endl;
							system("pause");
						}

						else
						{
							system("cls");
							cout<<""<<endl;
							cout<<" Aluno nao Cadastrado! Tente digitar o nome completo."<<endl;
							cout<<" Caso a busca resulte em falha, cadastre um novo aluno."<<endl<<endl;
							system("pause");
						}
					break;

					case 2:
						system("cls");
						print_top_busca();
						cout<<" Digite o mes de inicio (ex.: 07):"<<endl;
						cin>>mm;
						cin.ignore();

						aluno *PtrBuscaMes;
						PtrBuscaMes = li.busca_mes(mm);

						print_top_busca();
						cout<<" Busca de alunos com inicio de estagio no mes "<<mm<<":"<<endl<<endl;
						cout<<" Aluno: "<<PtrBuscaMes->nome_aluno<<endl;
						cout<<" Matricula: "<<PtrBuscaMes->matricula<<endl;
						cout<<" Periodo Letivo: "<<PtrBuscaMes->periodo_letivo<<endl;
						cout<<" Tipo de Estagio: ";
						print_tipo_estagio(PtrBuscaMes->tipo_estagio);

						cout<<" CH Semanal: "<<PtrBuscaMes->ch_semanal<<" Horas."<<endl;
						cout<<" CH Diaria: "<<PtrBuscaMes->ch_diaria<<" Horas."<<endl;
						cout<<" Inicio da Vigencia: "<<PtrBuscaMes->dd_inicio<<"/"<<PtrBuscaMes->mm_inicio<<"/"<<PtrBuscaMes->aa_inicio<<"."<<endl;
						cout<<" Fim da Vigencia: "<<PtrBuscaMes->dd_fim<<"/"<<PtrBuscaMes->mm_fim<<"/"<<PtrBuscaMes->aa_fim<<"."<<endl;

						cout<<" Status do Estagio: ";
						print_status(PtrBuscaMes->status_estagio);

						cout<<endl<<endl;

						system("pause");

						if(PtrBuscaMes == NULL)
						{
							system("cls");
							cout<<""<<endl;
							cout<<" Nenhum aluno cadastrado para este mes!"<<endl;
							cout<<" Cadastre um novo aluno."<<endl<<endl;
							system("pause");
						}
					break;

					case 3:
						system("cls");
						print_top_busca();
						cout<<" Digite o mes final do estagio (ex.: 07):"<<endl;
						cin>>MesFimEst;
						cin.ignore();

						aluno *PtrBuscaMesFim;
						PtrBuscaMesFim = li.busca_mes_fim(MesFimEst);

						print_top_busca();
						cout<<" Busca de alunos com inicio de estagio no mes "<<MesFimEst<<":"<<endl<<endl;
						cout<<" Aluno: "<<PtrBuscaMesFim->nome_aluno<<endl;
						cout<<" Matricula: "<<PtrBuscaMesFim->matricula<<endl;
						cout<<" Periodo Letivo: "<<PtrBuscaMesFim->periodo_letivo<<endl;
						cout<<" Tipo de Estagio: ";
						print_tipo_estagio(PtrBuscaMesFim->tipo_estagio);

						cout<<" CH Semanal: "<<PtrBuscaMesFim->ch_semanal<<" Horas."<<endl;
						cout<<" CH Diaria: "<<PtrBuscaMesFim->ch_diaria<<" Horas."<<endl;
						cout<<" Inicio da Vigencia: "<<PtrBuscaMesFim->dd_inicio<<"/"<<PtrBuscaMesFim->mm_inicio<<"/"<<PtrBuscaMesFim->aa_inicio<<"."<<endl;
						cout<<" Fim da Vigencia: "<<PtrBuscaMesFim->dd_fim<<"/"<<PtrBuscaMesFim->mm_fim<<"/"<<PtrBuscaMesFim->aa_fim<<"."<<endl;

						cout<<" Status do Estagio: ";
						print_status(PtrBuscaMesFim->status_estagio);

						cout<<endl<<endl;

						system("pause");

						if(PtrBuscaMesFim == NULL)
						{
							system("cls");
							cout<<""<<endl;
							cout<<" Nenhum aluno cadastrado para este mes!"<<endl;
							cout<<" Cadastre um novo aluno."<<endl<<endl;
							system("pause");
						}
					break;

					case 4:
						retornar = 4;
					break;

					default:
						system("cls");
						cout<<endl;
						cout<<" Opcao Invalida."<<endl;
						system("pause");
					break;


				}
			}while(retornar != 4);
			break;

			case 2:
				do{
					system("cls");
					print_top_cadastro();
					li.novoaluno();
					cout<<endl;
					cout<<" Cadastrar outro aluno? (s/n)"<<endl;
					cin>>opcao;
					cin.ignore();

				}while(opcao == 's');
			break;

			case 3:

			break;

			case 4:
				li.print();
			break;

			case 5:
				saida = 5;
			break;

			default:
				system("cls");
				cout<<" Opcao Invalida! Retorne ao menu e escolha uma operacao valida!"<<endl;
				system("pause");
			break;
		}

	}while(saida != 5);
	if(saida == 5)
	{
		creditos();
	}
}


void print_status(int)
{
	if(1) cout<<"Aguardando Assinatura."<<endl;
	else if(2) cout<<"Ativo."<<endl;
	else if(3) cout<<"Concluido."<<endl;
	else if(4) cout<<"Cancelado."<<endl;
}

void print_tipo_estagio(int)
{
	if(1) cout<<"Obrigatorio."<<endl;
	else if(2) cout<<"Nao Obrigatorio."<<endl;
}

void print_mes()
{
	cout<<"01. Janeiro;"<<endl;
	cout<<"02. Fevereiro;"<<endl;
	cout<<"03. Marco;"<<endl;
	cout<<"04. Abril;"<<endl;
	cout<<"05. Maio;"<<endl;
	cout<<"06. Junho;"<<endl;
	cout<<"07. Julho;"<<endl;
	cout<<"08. Agosto;"<<endl;
	cout<<"09. Setembro;"<<endl;
	cout<<"10. Outubro;"<<endl;
	cout<<"11. Novembro;"<<endl;
	cout<<"12. Dezembro;"<<endl<<endl;
}

void print_top_cadastro()
{
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"                     >>> CADASTRO DE ALUNOS <<<                     "<<endl;
	cout<<"--------------------------------------------------------------------"<<endl<<endl;
}

void print_top_estagio()
{
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"                   >>> INFORMACOES DO ESTAGIO <<<                   "<<endl;
	cout<<"--------------------------------------------------------------------"<<endl<<endl;
}

void print_main_busca()
{
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"                       >>> BUSCA DE ALUNOS <<<                      "<<endl;
	cout<<"--------------------------------------------------------------------"<<endl<<endl;
}

void print_top_busca()
{
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"                  >>> BUSCA POR NOME DE ALUNOS <<<                  "<<endl;
	cout<<"--------------------------------------------------------------------"<<endl<<endl;
}

void creditos()
{
	system("cls");
	cout<<"                           >> CREDITOS <<                           "<<endl;
	cout<<" Programa desenvolvido para avaliacao da unidade 3 da disciplina de "<<endl;
	cout<<" Tecnicas de programacao.                                           "<<endl<<endl;
	cout<<"--------------------------------------------------------------------"<<endl;
	cout<<"                Universidade Federal da Paraiba, UFPB.              "<<endl;
	cout<<"                   Joao Pessoa, 06 de maio de 2019.                 "<<endl;
	cout<<"                         Paraiba - Brasil.                          "<<endl;
	cout<<"--------------------------------------------------------------------"<<endl<<endl;
	system("pause");
	system("cls");
}
