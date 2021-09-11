/*  Author: José Cutileiro
    License: @gnu
    "Curso prático de JAVA" - Carla Jesus @FCA
*/

import java.util.Scanner;       // Leitura terminal
import javax.swing.JOptionPane; // Leitura modo gráfico


/* CAPITULO 1 - Introdução a OOP*/

/* TEORIA-I - Paradigmas da programação

Estruturada (C) -> Procedimentos e funções
OOP (JAVA) -> Objetos autónomos

JAVA    > Linguagem
        > Ambiente de desenvolvimento, execução e distribuição

Nota:  BlueJ > IDE de java
Nota: O java têm um garbage collector (a memória é libertada automaticamente)
Nota: Java é muito portável, qualquer máquina pode executar .java se possuir JRE
*/


class HELLO {
    public static void main(String[] args){
        System.out.println("HELLO!");
    }
}

/* Teoria-II - Tipos de dados

Primitivos > boolean,char,bytre,short,int,long,float,double
Referência > Arrays, Classes, Interfaces

(ex) Cast:

    int x = 3;
    long y = (long)x
                ^
               cast


*/

class TipoRefArray1{
    public static void main(String[] args){
        int[] nums = new int[10];
        for (int i=0;i<10;i++){
            nums[i] = i;
            System.out.println("nums["+i+"] = "+nums[i]);
        }
    }
}

class TipoRefArray2{
    public static void main(String[] args){
        int[] nums = {2,10,3,7,200,2003,334,4234,5435,1};
        for (int i=0;i<10;i++){
            System.out.println("nums["+i+"] = "+nums[i]);
        }
    }
}

/* TEORIA-III - Operadores (igual a C) e Controlo (igual a C)

    Atritméticos: ++,--,+,-,*,/,%
    Relação: >,<,>=,<=,==,!=,?:,Instanceof
                        Nota: ?: <=> Ternário <=> (Condição) ? (A) : (B)
                        (executa A se condição é verdadeira,B caso contrário)
                        Nota: Insteof <=> Devolve true se o objeto da esquerda é
                        uma instância do da direita
    
    Controlo:

    > if: if (cond) {intruções}
    > if-else: if(cond1){
                instruções
                }
                else if(cond2){
                instruções
                }
                [...]
    > while: while(cond){
                instruções;
             }
    > do-while: do{
                    instruões;
                } while (cond);
    (executa pelo menos uma vez)
    > for: for(init;conds;iter) {instruções}
    > break:
                ciclo{
                    if (cond)
                        break > > > > V
                }                     V
                 <  <  <  <  <  <  <  V
    (Termina o ciclo)
    > continue:
                ciclo{   <  <  < ^
                    if (cond)    ^
                        continue ^
                    (resto)
                }
    (continua o ciclo mas termina aquela iteração)
    > switch: switch(valor){
            case valor1: [...] break;
            case valor2: [...] break;
            ...
            default: [...]
            }
    (só funciona com ints e chars)
*/

class Leitura1{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        String phrase;
        int num;
        System.out.print("Insert phrase: ");
        phrase = s.nextLine();
        System.out.println("Inserted: "+phrase);
        System.out.print("Insert number: ");
        num = s.nextInt();
        num *= 2;
        System.out.println("Your number multiplied by 2: "+num);
    }
}

class Leitura2{
    public static void main(String[] args){
        String nome;
        nome = JOptionPane.showInputDialog("Your name: ");
        String mensagem = "Nome inserido foi "+nome;
        JOptionPane.showMessageDialog(null, mensagem);
    }
}

/* CAPITULO 2 - Fundamentos da programação em OOP */

/* Teoria-I - Objetos e classes

:def: Os objetos são coisas que existem num mundo real e são de certo modo
      abstraídas para um mundo virtual.
      No mundo real os objetos têm estados -> Atributos
                                   e comportamentos -> métodos

    :ex: Objeto -> pessoa
         Atributos -> nome, idade
         Métodos -> falar, andar

:def: Uma classe é uma especificação para um tipo de objeto (uma receita para que o objeto exista)

Nota: Construtor - Não é um método mas um bloco de código que é executado sempre que 
                   utilizamos a palavra reservada 'new'

                   Construtor default: public Pessoa(){}
*/

class Pessoa{

    //Atributos
    String nome;
    int idade;
    char genero; // (M ou F)

    //Métodos
    void falar(){
        System.out.println("Hello my friend");
    }

    //Construtor
    public Pessoa(String nome,int idade,char genero){
        this.nome = nome;
        this.idade = idade;
        this.genero = genero;
    }

}

class TestaPessoa{
    public static void main(String[] args){
        Pessoa p1 = new Pessoa("José", 19, 'M');
        Pessoa p2 = new Pessoa("Camila",20, 'F');

        p1.falar();
        System.out.println("Olá "+p2.nome+" aposto que tu tens "+p2.idade+" anos");
    }
}

/* Teoria-II - Encapsulamento (modificadores de acesso)

    public - classes atributos e métodos visiveis para todos
    package - visisvies no mesmo pacote da classe mas não em subclasse
    protected - visiveis na classe e subclasse
    private - visiveis so na mesma classe

    Getters & Setters

        Getters - retorna o valor do atributo
                :ex: getSalario()  <->  get[nome do atributo]
                     isMale() <-> convenção para boolean
        
        Setters - modifica o valor do atributo
                :ex: setIdade(int Idade) <-> set[nome do atributo]
        
        Nota: Palavra this para imputar ao atributo o valor que é passado como
              parâmetro
    
    :Herança: Superclasse e subclasse
        Todos os atributos e métodos da superclasse 'funcionam' na subclasse
        já a subclasse poderá ter os seus métodos e atributos 'pessoais'
    
    :OverRide: (ex) escrever na subclasse um método já existente na super

    :OverLoad: (ex) Assinaturas diferentes do mesmo método prevendo a
                    quantidade se argumentos inseridos para cada situção
    
    :final: (ex) public final class Carro -> Impede que carro tenha subclasses
            (ex) public final void buzinar() -> Impede que o método buzinar seja
                                                sobrescrito pelas subclasses
    
    :Polimorfismo: Responder de várias formas usando as definições anteriores

*/