// @gnu license
// Description: c++ (part 1)
// author: José Cutileiro
// Source: freeCodeCamp.org

#include <iostream>
#include <cmath>      // math functions
#include <string>

using namespace std;

int Hello() 
{
    cout << "Hello :D" << endl;
    return 0;
}

int shapes()
{
    cout << "   /|" << endl;
    cout << "  / |" << endl;
    cout << " /  |" << endl;
    cout << "/___|" << endl;
    return 0;
}

int built_in_types()
{
    char c = 'A';
    string frase = "Hello world";
    int i = 0;
    float pi = 3.14;
    double pi2 = 3.14159;
    bool isIST = true, isNova = false;
    return 0;
}

int strings_basic()
{
    string frase = "Hello world";
    cout << "Hello" << endl;
    cout << "world" << endl;
    cout << frase << endl;
    cout << frase.length() << endl;               // built in attribute
    cout << frase[0] << endl;                     // 0 <-> H
    frase[0] = 'B';                               // editar
    cout << frase << endl;
    cout << frase.find("world",0) << endl;     // world começa na posição 6
                                               // pode ser util para fazer filtragens
    string sub;

    sub = frase.substr(2,4);
    cout << sub << endl;

    return 0;
}

// o ordem de op é seguida como habitualmente
int numbers_basic()
{
    double val = 99.0;
    cout << 42 << endl;
    cout << 20%10 << endl;   // faz a op aritmética
    cout << val++ << endl;
  //       =/=            //
    cout << ++val << endl;

    return 0;
}


// testar: cmath
// check more info: https://www.cplusplus.com/reference/cmath/
int cmath_test()
{
    cout << pow(2,5) << endl;
    cout << sqrt(36) << endl;
    cout << round(2.1) << endl;
    cout << round(2.5) << endl;
    // ceil && floor tb podem ser uteis
    cout << fmax(2,10) << endl;    // devolve o maior
    cout << fmin(2,10) << endl;    // devolve o menor

    return 0;
}

int user_input()
{
    // integers (o mesmo para char e float)
    int age;
    cout << "A tua idade: ";
    cin >> age;
    cout << "Tu tens " << age << " anos" << endl;

    // strings
    string nome;
    cout << "O teu nome: ";
    cin >> nome;
    getline(cin, nome);
    cout << "O teu nome é " << nome << endl;
}

int basic_calculator()
{
    double x,y;
    cout << "//Calculadora básica//" << endl;
    cout << "\n>>>> X op Y <<<<" << endl;
    cout << "Valor do X: ";
    cin >> x;
    cout << "Valor do Y: ";
    cin >> y;

    cout << "Soma: " << x+y << endl;
    cout << "Subtração: " << x-y << endl;
    cout << "Multiplicação: " << x*y << endl;
    cout << "Divisão: " << x/y << endl;
}

int multi_lines()
{
    string cor,local,amigo;
    int i;

                                  cout << "Uma cor: ";
    getline(cin,cor);             cout << "Um local:";
    getline(cin,local);           cout << "Um amigo teu:";
    getline(cin,amigo);

    cout << cor << local << amigo;

    return 0;
}


int basic_array()
{
    int grupo[] = {1,2,3,4};
    cout << grupo[2] << endl; // == 3

    int g2[100]; // array de 100 inteiros, g2[100]
                 // está fora do scope
}

void dizOla(){
    cout << "Olá :D" << endl;
}

int teste_func()
{
    int i;
    for(i=0;i<40;i++)
        dizOla();
    return 0;
}

int calculator_2()
{
   cout << ">> Calculadora 2 <<" << endl;
   cout << "::: X op Y :::, define op" << endl;

    int x,y;
    char op;

    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    cout << "op: ";
    cin >> op;
    cout << "Resultado: ";
    switch (op)
    {
    case '+':cout << x+y; break;
    case '-':cout << x-y; break;
    case '%':cout << x%y; break;
    case '*':cout << x*y; break;
    case '^':cout << pow(x,y); break;
    case '/':cout << x/y; break;
    }
    cout << endl;
}

int while_test()
{
    int i = 0;

    while (i<100)
    {
        cout << i << endl;
        i++;
    }
    i = 0; // reset i

    do{
        cout << i << endl;
        i++;
    }while(i<100);

    return 0;
}

int pass_system_basic()
{
    int num = 10, guess;

    while (num != guess)
    {
        cout << "Number: ";
        cin >> guess;
    }

    cout << "Well played :D" << endl;
}

// devolve x^y
int custom_pow()
{
    int res,x,y;
    cout << "Valor de x: ";
    cin >> x;
    cout << "Valor de y:";
    cin >> y;
    
    for(res=1;y>0;y--)
        res*=x;
    
    cout << "Res: " << res;

    return 0;
}

int simple_pointers()
{
    int age = 10;
    int *pAge = &age;

    cout << &age << endl;
    cout << pAge << endl;
    cout << *pAge << endl;
    // * -> o valor de...
    // & -> o endereço de...
}
// --------Teoria de classes---------
// class -> novo tipo de data
// é uma especificação do obj
// o objeto é a própria instancia
// Contrutor: chamamos quando: novo objeto
class Livro{
    public:
        string titulo;
        string autor;
        int num_paginas;
        Livro(){
            cout << "Novo livro criado" << endl;
        }
};

int class_intro()
{
    Livro CDI2GP,Editora[4];
    CDI2GP.autor = "Gabriel Pires";
    CDI2GP.titulo = "Calculo em Rn";
    CDI2GP.num_paginas = 556;
    Editora[0] = CDI2GP;

    cout << "Primeiro autor da editora: " << Editora[0].autor << endl;

    // Tal como um tipo de dados normal
    // Podemos criar um grupo de objetos
}

// pequeno upgrade da anterior
class Book{
    public:
        string title="Sem titulo";
        string author="Nao atribuido";
        int pages=0;
        //                ^
        //             default 

        Book(string aTitle,string aAuthor,int aPages)
        {
            title = aTitle;
            author = aAuthor;
            pages = aPages;
        }
};

int class_contrutor_intro()
{
    Book book1("Era do futuro","Sirkazzio",10);
    cout << "Autor: "<<book1.author << endl;
    return 0;
}

class Student{
    public:
        string nome = "Secreto";
        string grau = "Secreto";
        double media = 0;
        //Construtor
        Student(string aNome, string aGrau, double aMedia)
        {
            nome = aNome;
            grau = aGrau;
            media = aMedia;
        }

        bool Quadro_excelencia(){
            return media>18.5;
        }
};

int obj_func()
{
    Student S1("José","Primeiro",17),S2("Cris","Terceiro",18.9);
    cout << "0->False//1->True: "<<S1.Quadro_excelencia() << endl;
    return 0;
}

class Movie{
    // apenas o código em movie pode acessar o rating
    // util para restringir o utilizador
    private:
        int rating;

    public:
        string title;
        string author;

        Movie(string aTitle,string aAuthor,int aRating){
            title = aTitle;
            author = aAuthor;
            setRating(aRating);
        }

        void setRating(int aRating){
            if (0<=aRating && aRating<=100)
                rating = aRating;
            else
                {
                rating = 0;     // 0 by defenition
                cout << "Invalid rating, atributed 0 instead" << endl;
                }
        }

        int getRating()
        {
            return rating;
        }
};

int r_user()
{
    Movie m1("Vingadores","Joss",87);

    //m1.rating = 99;
    m1.setRating(199);

    //cout << m1.rating << endl;
    cout << m1.getRating() << endl;
    return 0;
}

class Chef{
    public:
        void faz_frango(){
            cout << "tou a fazer frango" << endl;
        }
        void faz_salada(){
            cout << "tou a fazer salada" << endl;
        }
        void prato_especial(){
            cout << "arroz com feijão" << endl;
        }
};

class ItalianChef : public Chef{
    public:
        void faz_pizza(){
            cout << "vou fazer pizza" << endl;
        }
        void prato_especial(){
            cout << "gelado de limão" << endl;
        }
};

int main()
{
    ItalianChef C1;
    Chef C2;
    C1.faz_salada();
    C1.prato_especial();
    C2.prato_especial();
    return 0;
}