---
title: "Express&#245;es p&#243;s-fixadas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "expressões [C++], sufixo"
  - "operadores [C++], sufixo"
  - "expressões de sufixo"
ms.assetid: 7ac62a57-06df-422f-b012-a75b37d7cb9b
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Express&#245;es p&#243;s-fixadas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As expressões pós\-fixadas consistem em expressões primárias ou expressões nas quais operadores pós\-fixados seguem uma expressão primária.  Os operadores pós\-fixados estão listados na tabela a seguir.  
  
### Operadores pós\-fixados  
  
|Nome do operador|Notação do operador|  
|----------------------|-------------------------|  
|[Operador de subscrito](../Topic/Subscript%20Operator:.md)|**\[ \]**|  
|[Operador de chamada de função](../cpp/function-call-operator-parens.md)|**\( \)**|  
|[Operador de conversão de tipo explícita](../Topic/Explicit%20Type%20Conversion%20Operator:%20\(\).md)|*type\-name* **\( \)**|  
|[Operador de acesso de membro](../Topic/Member%20Access%20Operators:%20.%20and%20-%3E.md)|**.** or **–\>**|  
|[Operador de incremento pós\-fixado](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|`++`|  
|[Operador de decremento pós\-fixado](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|**––**|  
  
 A sintaxe a seguir descreve expressões pós\-fixadas possíveis:  
  
```  
  
          primary-expression   
postfix-expression [ expression ]  
postfix-expression ( expression-list)  
simple-type-name ( expression-list)  
postfix-expression . name  
postfix-expression –> name  
postfix-expression ++  
postfix-expression ––  
cast-keyword < typename > (expression ) typeid ( typename )  
```  
  
 No código acima, *postfix\-expression* pode ser uma expressão primária ou outra expressão pós\-fixada.  Consulte o tópico sobre **expressões primárias**.  As expressões pós\-fixadas são agrupadas da esquerda para a direita; com isso, elas podem ser encadeadas da seguinte forma:  
  
```  
func(1)->GetValue()++  
```  
  
 Na expressão acima, func é uma expressão primária, func\(1\) é uma expressão pós\-fixada de função, func\(1\)\-\>GetData é uma expressão pós\-fixada que especifica um membro da classe, func\(1\)\-\>GetData\(\) é outra expressão pós\-fixada de função, e a expressão inteira é uma expressão pós\-fixada que incrementa o valor de retorno de GetData.  O significado da expressão, no conjunto, é "função de chamada passando 1 como um argumento e obtendo um ponteiro para uma classe como um valor de retorno".  Em seguida, GetValue\(\) é chamada nessa classe, e o valor retornado é incrementado.  
  
 As expressões listadas acima são expressões de atribuição, ou seja, o resultado dessas expressões deve ser um r\-value.  
  
 O formato de expressão pós\-fixada  
  
```  
simple-type-name ( expression-list )  
```  
  
 indica a invocação do construtor.  Caso simple\-type\-name seja um tipo fundamental, a lista de expressões deve ser formada por uma única expressão, a qual indica uma conversão do valor da expressão no tipo fundamental.  Esse tipo de expressão convertida imita um construtor.  Como esse formato permite que classes e tipos fundamentais sejam construídos usando a mesma sintaxe, ele é especialmente útil na definição de classes de modelo.  
  
 *cast\-keyword* é uma destas opções: `dynamic_cast`, `static_cast` ou `reinterpret_cast`.  Mais informações podem ser encontradas em **dynamic\_cast**, **static\_cast** e **reinterpet\_cast**.  
  
 O operador `typeid` é considerado uma expressão pós\-fixada.  Consulte o tópico sobre o **operador typeid**.  
  
## Argumentos formais e reais  
 Chamar programas transmite informações às funções chamadas em “argumentos reais”. As funções chamadas acessam as informações usando “argumentos formais” correspondentes.  
  
 Quando uma função for chamada, as seguintes tarefas serão executadas:  
  
-   Todos os argumentos reais \(aqueles fornecidos pelo chamador\) são avaliados.  Não há nenhuma ordem implícita na qual esses argumentos são avaliados, mas todos os argumentos são avaliados e todos os efeitos colaterais são concluídos antes da entrada na função.  
  
-   Cada argumento formal é inicializado com seu argumento correspondente na lista de expressões.  \(O argumento formal é um argumento declarado no cabeçalho da função e usado no corpo de uma função.\) As conversões são realizadas como se a inicialização — conversões padrão e definidas pelo usuário são executadas na conversão de um argumento real para o tipo correto.  A inicialização executada é ilustrada de modo conceitual pelo seguinte código:  
  
    ```  
    void Func( int i ); // Function prototype  
    ...  
    Func( 7 );          // Execute function call  
    ```  
  
     As inicializações conceituais antes da chamada são:  
  
    ```  
    int Temp_i = 7;  
    Func( Temp_i );  
    ```  
  
     A inicialização é executada como se estivesse usando a sintaxe de sinal de igualdade em vez de sintaxe de parênteses.  Uma cópia de `i` é feita antes de transmitir o valor à função.  \(Para obter mais informações, consulte [Inicializadores](../cpp/initializers.md) e [Conversões](../cpp/user-defined-type-conversions-cpp.md), [Inicialização usando as funções de membro especiais](http://msdn.microsoft.com/pt-br/82223d73-64cb-4923-b678-78f9568ff3ca) e [Inicialização explícita](http://msdn.microsoft.com/pt-br/c89724f8-ddd3-4d77-b86d-77fcd8bd8595).  
  
     Portanto, se as chamadas de protótipo de função \(declaração\) para um argumento de tipo **long**, e se o programa de chamada fornece um argumento real do tipo `int`, o argumento real será promovido usando uma conversão de tipo padrão para o tipo **long** \(consulte [Conversões padrão](../cpp/standard-conversions.md)\).  
  
     É um erro fornecer um argumento real para o qual não há conversão padrão ou definida pelo usuário para o tipo de argumento formal.  
  
     Para argumentos reais de tipos de classe, o argumento formal é inicializado chamando o construtor da classe.  \(Consulte [Construtores](../cpp/constructors-cpp.md) para obter mais informações sobre essas funções de membro de classe especiais.\)  
  
-   A chamada de função é executada.  
  
 O seguinte fragmento de programa demonstra uma chamada de função:  
  
```  
// expre_Formal_and_Actual_Arguments.cpp  
void func( long param1, double param2 );  
  
int main()  
{  
    long i = 1;  
    double j = 2;  
  
    // Call func with actual arguments i and j.  
    func( i, j );  
}  
  
// Define func with formal parameters param1 and param2.  
void func( long param1, double param2 )  
{  
}  
```  
  
 Quando `func` é chamado de main, o parâmetro formal `param1` é inicializado com o valor de `i` \(`i` é convertido no tipo **long** para corresponder ao tipo correto usando uma conversão padrão\), e o parâmetro formal `param2` é inicializado com o valor de `j` \(`j` é convertido no tipo **double** usando uma conversão padrão\).  
  
## Tratamento de tipos de argumento  
 Os argumentos formais declarados como tipos const não podem ser alterados dentro do corpo de uma função.  As funções podem alterar qualquer argumento que não seja do tipo **const**.  No entanto, a alteração é local para a função e não afeta o valor real do argumento, a menos que o argumento real seja uma referência a um objeto e não a um tipo **const**.  
  
 As seguintes funções ilustram alguns desses conceitos:  
  
```  
// expre_Treatment_of_Argument_Types.cpp  
int func1( const int i, int j, char *c ) {  
   i = 7;   // C3892 i is const.  
   j = i;   // value of j is lost at return  
   *c = 'a' + j;   // changes value of c in calling function  
   return i;  
}  
  
double& func2( double& d, const char *c ) {  
   d = 14.387;   // changes value of d in calling function.  
   *c = 'a';   // C3892 c is a pointer to a const object.  
    return d;  
}  
```  
  
## Reticências e argumentos padrão  
 As funções podem ser declaradas para aceitar menos argumentos do que o especificado na definição da função, usando um de dois métodos: reticências \(`...`\) ou argumentos padrão.  
  
 As reticências denotam que os argumentos podem ser necessários, mas que o número e os tipos não estão especificados na declaração.  Essa geralmente é uma prática inadequada de programação do C\+\+ porque ela elimina um dos benefícios de segurança do tipo C\+\+:.  Conversões diferentes são aplicadas às funções declaradas com reticências do que nas funções para as quais os tipos de argumento formal e real são conhecidos:  
  
-   Se o argumento real for do tipo **float**, ele será promovido para o tipo **double** antes da chamada de função.  
  
-   Qualquer tipo enumerado `char`, **short** com sinal ou sem sinal, ou campo de bits, é convertido em `int` com sinal ou sem sinal usando a promoção de integral.  
  
-   Qualquer argumento de tipo de classe é passado por valor como estrutura de dados; a cópia é criada por cópia binário em vez de chamar o construtor de cópia de classe \(se houver\).  
  
 As reticências, se usadas, deverão ser declaradas por último na lista de argumentos.  Para obter mais informações sobre como passar um número variável de argumentos, consulte os tópicos sobre [va\_arg, va\_start e va\_list](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md) na *Referência da biblioteca em tempo de execução*.  
  
 Para obter informações sobre os argumentos padrão na programação CLR, consulte [Variable Argument Lists \(...\) \(C\+\+\/CLI\)](../windows/variable-argument-lists-dot-dot-dot-cpp-cli.md).  
  
 Os argumentos padrão permitem que você especifique o valor que um argumento deverá assumir caso nenhum seja fornecido na chamada de função.  O fragmento de código a seguir mostra como os argumentos padrão funcionam.  Para obter mais informações sobre as restrições na especificação de argumentos padrão, consulte [Argumentos padrão](../Topic/Default%20Arguments.md).  
  
```  
// expre_Ellipses_and_Default_Arguments.cpp  
// compile with: /EHsc  
#include <iostream>  
  
// Declare the function print that prints a string,  
// then a terminator.  
void print( const char *string,  
            const char *terminator = "\n" );  
  
int main()  
{  
    print( "hello," );  
    print( "world!" );  
  
    print( "good morning", ", " );  
    print( "sunshine." );  
}  
  
using namespace std;  
// Define print.  
void print( const char *string, const char *terminator )  
{  
    if( string != NULL )  
        cout << string;  
  
    if( terminator != NULL )  
        cout << terminator;  
}  
```  
  
 O programa anterior declara uma função, `print`, que usa dois argumentos.  No entanto, o segundo argumento, `terminator`, tem um valor padrão, `"\n"`.  Em **main**, as duas primeiras chamadas a `print` permitem que o segundo argumento padrão forneça uma nova linha para finalizar a cadeia de caracteres impressa.  A terceira chamada especifica um valor explícito para o segundo argumento.  A saída do programa é  
  
```  
hello,  
world!  
good morning, sunshine.  
```  
  
## Consulte também  
 [Tipos de expressões](../cpp/types-of-expressions.md)