/* 
@gnu PART 1
author: José Cutileiro
source: thinking in java, Bruce Eckel
java --version: openjdk 16.0.1
javac --version: javac 11.0.11
laguage: Portuguese
*/

import java.util.*;
import javax.swing.text.Style;

/* tipos primitivos
boolean     char       byte     short
int         long       float    double
void
||||||||||||||||||||||||||||||||||||||||||||
array (mudanças entre c e c++) 
     *em java a memoria vem inicializada
    *nao pode ser acessada fora do seu range 
||||||||||||||||||||||||||||||||||||||||||||
*em java não precisamos de destroir os objetos
*o scope é definido como em c ou c++ "{}"
*a indentação também não afeta o código
*/

class Hello{
    public static void main(String[] args){
        System.out.println("Hello world");
        System.out.println(new Date());
    }
}

class Ex1{
    public static void main(String[] args){
        int val=10;
        char let = 'a';
        System.out.println(val);
        System.out.println(let);
        System.out.println("Hello world");
    }
}

class Tank{
    int nivel;
}

class Ini{
    public static void main(String[] args){
        Tank t1 = new Tank();
        Tank t2 = new Tank();
        t1.nivel = 5;
        t2.nivel = 3;
        System.out.print("t1: "+ t1.nivel + " ||| t2: " + t2.nivel + '\n');
    }
    // O print de java é ≃ printf de C
}

class Math_Test{
    public static void main(String[] args){
        int i=10;
        System.out.println(9%2);
        System.out.println(9/2);
        i*= 10;
        System.out.println(i);
    }
}

class Random{
    public static void main(String[] args){
        Date d1 = new Date();
        long r = d1.getTime();
        r %= 10;
        System.out.println(r);
    }
}

/* Tabela de operadores
math: Trivial
logica: ||, &&,>,== ...
Bin: &,|, ^(XOR), ~(NOT),SHIFTS
        SHIFTS: >>, <<, ex: >>>=10;
*/

class URSHIFT{
    public static void main(String[] args){
        int i = -1;
        System.out.println(Integer.toBinaryString(i));
        i >>>= 10; // 10 shifts para a direita
        System.out.println(Integer.toBinaryString(i)); 
        i = i<<10; // 10 shifts para a esquerda, a outra notacao nao é permitida
        System.out.println(Integer.toBinaryString(i));
    }
}

// Operador ternario: ->  bool-val ? v1 : v2; (igual a C)
// if e else é igual a C também
class Ternario{
    static int test(int i){
        return i<10 ? i*100 : i*10;
    }
    public static void main(String[] args)
    {
        int i=190;
        System.out.println(test(i));
        i = 9;
        System.out.println(test(i));
    }
}
// O casting é igual a C também
// (o rounding é muito diferente)

class RoundingNumbers{
    public static void main(String[] args)
    {
        double a = 0.7,b = 0.4;
        // Rounding
        System.out.println("Round a: " + Math.round(a));
        System.out.println("Round b: " + Math.round(b));

        // floor and ceiling
        System.out.println("floor a: " + Math.floor(a));
        System.out.println("ceil b: " + Math.ceil(b));
    }
}
// Nota: não existe sizeof em Java dado que o tamanho de cada 
// tipo é CONSTANTE em todas as máquinas

/* Controlo de execução
Java utiliza todo o controlo de execucao de C,
while,
do-while,
for,
return,
break,

true and false;
    *Em java isto não existe:
        -> int i=0;
           if (i) -> errado em java
           ***************************
           if (i!=0) -> correto em java
(os numeros nao tem valor booleano)*/

/* Relembrar formato de iteração

1) do-while
do
    statement
while(Boolean-exp)

2) for
for(inits;Boolean-exp;step)
 statment

3) while (Boolean-exp)
     statment
*/

class Ex2{
    public static void main(String[] args){
        int i=1,h;
        while(i<=100){
            System.out.println(" # " + i + " # ");
            i +=1;
        }
        
        double j;
        for (j=Math.random(),h=1;h<=25;h++,j=Math.random()){
            i = (int)(j*100); // Random 0-100
            System.out.println("R" + i);
        }
    }
}
/* NEW: foreach
        formato:
                    for(float x : f){}
                                  ^
                              container (de floats neste caso)*/

class Foreach_test{
    public static void main(String[] args){
        float f[] = new float[10];
        f[4] = 2;
        f[9] = 10;
        for (float x : f)
            System.out.println(x);

    }
}

/* break -> pára o ciclo e quebra a ciclagem
   continue -> pára o ciclo mas continua a ciclagem 
   goto -> não é usado em java
   switch -> igual a C; 
        relembra o formato:
            switch(seletor){
                case C1 : statment; break;
                case C2 : statment; break;
                ...
                default: statment;
            }
*/

class Fib{
    public static void main(String[] args)
    {
        int p=0,f=1,prox=1,iter;
        for (iter=0;iter<10;iter++){
            prox = p+f;
            p = f;
            f = prox;
            System.out.println("#" + iter + " :" + p);
        }

    }
}

class Leitura{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String Nome = scanner.nextLine();
        int idade = scanner.nextInt();
        double peso = scanner.nextDouble();
        System.out.println(Nome + idade + peso);
        scanner.close();
    }
}

class Pedra{
    // Construtor
    Pedra(){ 
        System.out.println("Foi criada uma nova pedra");
    }
}

class Pedra2{
    Pedra2(int i){
        System.out.println("#"+ i +": Foi criada uma nova pedra");
    }
}

class Testar_Pedra_e2{
    public static void main(String[] args)
    {
        int i;
        for (i=0;i<10;i++)
            new Pedra();
        for (i=0;i<10;i++)
            new Pedra2(i);
    }
}

/*
Overloading de metodos:
    **Dependendo do numero de argumentos
      que damos a funcoes ou construtores
      podemos fazer coisas diferentes**

    **Dependendo da ORDEM dos argumentos
      que damos a funcoes ou construtores
      podemos fazer coisas diferentes**
*/

class Tree{
    int height;
    // Construtor por definição
    Tree(){
        System.out.println("Arvore plantada");
        height = 0;
    }
    Tree(int i_height)
    {
        System.out.println("Arvore inserida");
        height = i_height;
    }

    void info()
    {
        System.out.println("Info: A arvore selecionada tem " + height + " metros.");
    }
}

class Testar_tree{
    public static void main(String[] args)
    {
        Tree a1 = new Tree(), a2 = new Tree(10);
        a1.info();
        a2.info();
    }
}

class Livro{
    int pag;
    String author;
    Livro(int i_pag,String i_author){
        pag = i_pag;
        author = i_author;
        System.out.println("new-->Páginas: " + pag);
    }
    Livro(String i_author,int i_pag){
        pag = i_pag;
        author = i_author;
        System.out.println("new-->Autor: " + author);
    }

    void info(){
        System.out.println("Paginas: " + pag);
        System.out.println("Autor: " + author);
    }
}

class Testa_livro{
    public static void main(String[] args){
        Livro l1 = new Livro("JOSÉ",630),l2 = new Livro(842,"REIS");
        l1.info();
        l2.info();
    }
}

/* This keyword
    *É usada muitas vezes secretamente pelo compilador;
    *Pode ser importante para valores de retorno
ou até mesmo para passar para funções
    *Construtor dentro de Construtor (ver exemplo: CiC*)

ex: Folha func(){ | func2(f2);
    ...           | 
    ...           | func2(Folha f){
    return f1;    |  ... }
}
*/
// EXEMPLO CiC*

class Flor{
    int pet;
    String nome;
    Flor(int i_pet){
        pet = i_pet;
        nome = "SEM NOME";
    }
    Flor(String i_nome){
        nome = i_nome;     
        pet = 0;      
    }
    Flor(int i_pet,String i_nome){
        this.pet = i_pet;
        this.nome = i_nome;
        System.out.println("Dupla inserção");
    }
    void info(){
        System.out.println("NUMERO DE PETALAS: " + pet);
        System.out.println("NOME: " + nome);
    }
}

class Testa_flor{
    public static void main(String[] args){
        Flor f1 = new Flor(10),f2 = new Flor("Cresália"),f3 = new Flor(10,"Cresália");
        f1.info();
        f2.info();
        f3.info();
    }
}

