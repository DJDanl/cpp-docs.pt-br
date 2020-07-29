---
title: Expressões pós-fixadas
ms.date: 11/04/2016
helpviewer_keywords:
- operators [C++], postfix
- postfix expressions
- expressions [C++], postfix
ms.assetid: 7ac62a57-06df-422f-b012-a75b37d7cb9b
ms.openlocfilehash: 9a5c99c78623f2192b59a73f270f3ad5d2a34516
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231163"
---
# <a name="postfix-expressions"></a>Expressões pós-fixadas

As expressões pós-fixadas consistem em expressões primárias ou expressões nas quais operadores pós-fixados seguem uma expressão primária. Os operadores pós-fixados estão listados na tabela a seguir.

### <a name="postfix-operators"></a>Operadores pós-fixados

|Nome do operador|Notação do operador|
|-------------------|-----------------------|
|[Operador subscrito](../cpp/subscript-operator.md)|**[ ]**|
|[Operador de chamada de função](../cpp/function-call-operator-parens.md)|**( )**|
|[Operador de conversão de tipo explícita](../cpp/explicit-type-conversion-operator-parens.md)|*tipo-nome* **()**|
|[Operador de acesso de membro](../cpp/member-access-operators-dot-and.md)|**.** or**->**|
|[Operador de incremento pós-fixado](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|**++**|
|[Operador de decremento pós-fixado](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|**--**|

A sintaxe a seguir descreve expressões pós-fixadas possíveis:

```
primary-expression
postfix-expression[expression]postfix-expression(expression-list)simple-type-name(expression-list)postfix-expression.namepostfix-expression->namepostfix-expression++postfix-expression--cast-keyword < typename > (expression )typeid ( typename )
```

A *expressão de sufixo* acima pode ser uma [expressão primária](primary-expressions.md) ou outra expressão de sufixo. As expressões pós-fixadas são agrupadas da esquerda para a direita; com isso, elas podem ser encadeadas da seguinte forma:

```cpp
func(1)->GetValue()++
```

Na expressão acima, é uma expressão `func` primária, `func(1)` é uma expressão de sufixo de função, `func(1)->GetValue` é uma expressão de sufixo que especifica um membro da classe, `func(1)->GetValue()` é outra expressão de sufixo de função, e a expressão inteira é uma expressão de sufixo que aumenta o valor de retorno de GetValue.  O significado da expressão, no conjunto, é "função de chamada passando 1 como um argumento e obtendo um ponteiro para uma classe como um valor de retorno".  Em seguida `GetValue()` , chame essa classe e, em seguida, aumente o valor retornado.

As expressões listadas acima são expressões de atribuição, ou seja, o resultado dessas expressões deve ser um r-value.

O formato de expressão pós-fixada

```cpp
simple-type-name ( expression-list )
```

indica a invocação do construtor.  Caso simple-type-name seja um tipo fundamental, a lista de expressões deve ser formada por uma única expressão, a qual indica uma conversão do valor da expressão no tipo fundamental.  Esse tipo de expressão convertida imita um construtor.  Como esse formato permite que classes e tipos fundamentais sejam construídos usando a mesma sintaxe, ele é especialmente útil na definição de classes de modelo.

A *palavra-chave Cast* é um de **`dynamic_cast`** , **`static_cast`** ou **`reinterpret_cast`** .  Mais informações podem ser encontradas em [`dynamic_cast`](dynamic-cast-operator.md) [`static_cast`](static-cast-operator.md) e [`reinterpet_cast`](reinterpret-cast-operator.md) .

O **`typeid`** operador é considerado uma expressão de sufixo.  Consulte o **operador typeid**.

## <a name="formal-and-actual-arguments"></a>Argumentos formais e reais

Chamar programas transmite informações às funções chamadas em “argumentos reais”. As funções chamadas acessam as informações usando “argumentos formais” correspondentes.

Quando uma função for chamada, as seguintes tarefas serão executadas:

- Todos os argumentos reais (aqueles fornecidos pelo chamador) são avaliados. Não há nenhuma ordem implícita na qual esses argumentos são avaliados, mas todos os argumentos são avaliados e todos os efeitos colaterais são concluídos antes da entrada na função.

- Cada argumento formal é inicializado com seu argumento correspondente na lista de expressões. (Um argumento formal é um argumento declarado no cabeçalho da função e usado no corpo de uma função.) As conversões são feitas como se fosse por inicialização – as conversões padrão e definidas pelo usuário são executadas na conversão de um argumento real para o tipo correto. A inicialização executada é ilustrada de modo conceitual pelo seguinte código:

    ```cpp
    void Func( int i ); // Function prototype
    ...
    Func( 7 );          // Execute function call
    ```

   As inicializações conceituais antes da chamada são:

    ```cpp
    int Temp_i = 7;
    Func( Temp_i );
    ```

   A inicialização é executada como se estivesse usando a sintaxe de sinal de igualdade em vez de sintaxe de parênteses. Uma cópia de `i` é feita antes de transmitir o valor à função. (Para obter mais informações, consulte [inicializadores](../cpp/initializers.md) e [conversões](../cpp/user-defined-type-conversions-cpp.md)).

   Portanto, se o protótipo de função (declaração) chamar um argumento do tipo **`long`** e se o programa de chamada fornecer um argumento real do tipo **`int`** , o argumento real será promovido usando uma conversão de tipo padrão para tipo **`long`** (consulte [conversões padrão](../cpp/standard-conversions.md)).

   É um erro fornecer um argumento real para o qual não há conversão padrão ou definida pelo usuário para o tipo de argumento formal.

   Para argumentos reais de tipos de classe, o argumento formal é inicializado chamando o construtor da classe. (Consulte [construtores](../cpp/constructors-cpp.md) para obter mais informações sobre essas funções de membros de classe especiais.)

- A chamada de função é executada.

O seguinte fragmento de programa demonstra uma chamada de função:

```cpp
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

Quando `func` é chamado de Main, o parâmetro formal `param1` é inicializado com o valor de `i` ( `i` é convertido em Type **`long`** para corresponder ao tipo correto usando uma conversão padrão) e o parâmetro formal `param2` é inicializado com o valor de `j` ( `j` é convertido para o tipo **`double`** usando uma conversão padrão).

## <a name="treatment-of-argument-types"></a>Tratamento de tipos de argumento

Argumentos formais declarados como **`const`** tipos não podem ser alterados no corpo de uma função. As funções podem alterar qualquer argumento que não seja do tipo **`const`** . No entanto, a alteração é local para a função e não afeta o valor do argumento real, a menos que o argumento real tenha sido uma referência a um objeto que não seja do tipo **`const`** .

As seguintes funções ilustram alguns desses conceitos:

```cpp
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

## <a name="ellipsis-and-default-arguments"></a>Reticências e argumentos padrão

As funções podem ser declaradas para aceitar menos argumentos do que o especificado na definição da função, usando um de dois métodos: reticências (`...`) ou argumentos padrão.

Reticências indica que os argumentos podem ser necessários, mas que o número e os tipos não são especificados na declaração. Essa geralmente é uma prática inadequada de programação do C++ porque ela elimina um dos benefícios de segurança do tipo C++:. Conversões diferentes são aplicadas a funções declaradas com reticências do que às funções para as quais os tipos de argumento formal e real são conhecidos:

- Se o argumento real for do tipo **`float`** , ele será promovido para **`double`** o tipo antes da chamada de função.

- Qualquer **`signed char`** **`unsigned char`** campo ou, **`signed short`** ou **`unsigned short`** , tipo enumerado ou de bits é convertido em uma **`signed int`** promoção do ou do **`unsigned int`** usando integral.

- Qualquer argumento de tipo de classe é passado por valor como estrutura de dados; a cópia é criada por cópia binário em vez de chamar o construtor de cópia de classe (se houver).

Reticências, se usadas, devem ser declaradas por último na lista de argumentos. Para obter mais informações sobre como passar um número variável de argumentos, consulte a discussão sobre [va_arg, va_start e va_list](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md) na *referência da biblioteca de tempo de execução*.

Para obter informações sobre argumentos padrão na programação CLR, consulte [listas de argumentos variáveis (...) (C++/CLI)](../extensions/variable-argument-lists-dot-dot-dot-cpp-cli.md).

Os argumentos padrão permitem que você especifique o valor que um argumento deverá assumir caso nenhum seja fornecido na chamada de função. O fragmento de código a seguir mostra como os argumentos padrão funcionam. Para obter mais informações sobre restrições na especificação de argumentos padrão, consulte [argumentos padrão](../cpp/default-arguments.md).

```cpp
// expre_Ellipsis_and_Default_Arguments.cpp
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

O programa anterior declara uma função, `print`, que usa dois argumentos. No entanto, o segundo argumento, *terminador*, tem um valor padrão, `"\n"` . No `main` , as duas primeiras chamadas para `print` permitir que o segundo argumento padrão forneça uma nova linha para encerrar a cadeia de caracteres impressa. A terceira chamada especifica um valor explícito para o segundo argumento. A saída do programa é

```Output
hello,
world!
good morning, sunshine.
```

## <a name="see-also"></a>Confira também

[Tipos de expressões](../cpp/types-of-expressions.md)
