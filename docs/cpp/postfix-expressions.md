---
title: Expressões pós-fixadas
ms.date: 11/04/2016
helpviewer_keywords:
- operators [C++], postfix
- postfix expressions
- expressions [C++], postfix
ms.assetid: 7ac62a57-06df-422f-b012-a75b37d7cb9b
ms.openlocfilehash: 897eb80c713f786ecf0f7e6c9cf24cd8bdfc0aa8
ms.sourcegitcommit: 89d9e1cb08fa872483d1cde98bc2a7c870e505e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "82032272"
---
# <a name="postfix-expressions"></a>Expressões pós-fixadas

As expressões pós-fixadas consistem em expressões primárias ou expressões nas quais operadores pós-fixados seguem uma expressão primária. Os operadores pós-fixados estão listados na tabela a seguir.

### <a name="postfix-operators"></a>Operadores pós-fixados

|Nome do operador|Notação do operador|
|-------------------|-----------------------|
|[Operador de subscritor](../cpp/subscript-operator.md)|**[ ]**|
|[Operador de chamada de função](../cpp/function-call-operator-parens.md)|**( )**|
|[Operador de conversão de tipo explícita](../cpp/explicit-type-conversion-operator-parens.md)|*nome de tipo* **( )**|
|[Operador de acesso de membro](../cpp/member-access-operators-dot-and.md)|**.** Ou**->**|
|[Operador de incremento pós-fixado](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|**++**|
|[Operador de decremento pós-fixado](../cpp/postfix-increment-and-decrement-operators-increment-and-decrement.md)|**--**|

A sintaxe a seguir descreve expressões pós-fixadas possíveis:

```
primary-expression
postfix-expression[expression]postfix-expression(expression-list)simple-type-name(expression-list)postfix-expression.namepostfix-expression->namepostfix-expression++postfix-expression--cast-keyword < typename > (expression )typeid ( typename )
```

A *expressão postfix* acima pode ser uma expressão primária ou outra expressão pós-fixação.  Veja **expressões primárias**.  As expressões pós-fixadas são agrupadas da esquerda para a direita; com isso, elas podem ser encadeadas da seguinte forma:

```cpp
func(1)->GetValue()++
```

Na expressão `func` acima, é uma `func(1)` expressão primária, é `func(1)->GetValue` uma expressão postfix de função, `func(1)->GetValue()` é uma expressão postfix especificando um membro da classe, é outra expressão postfix de função, e toda a expressão é uma expressão postfix incrementando o valor de retorno de GetValue.  O significado da expressão, no conjunto, é "função de chamada passando 1 como um argumento e obtendo um ponteiro para uma classe como um valor de retorno".  Em `GetValue()` seguida, chamar essa classe, em seguida, incrementar o valor devolvido.

As expressões listadas acima são expressões de atribuição, ou seja, o resultado dessas expressões deve ser um r-value.

O formato de expressão pós-fixada

```cpp
simple-type-name ( expression-list )
```

indica a invocação do construtor.  Caso simple-type-name seja um tipo fundamental, a lista de expressões deve ser formada por uma única expressão, a qual indica uma conversão do valor da expressão no tipo fundamental.  Esse tipo de expressão convertida imita um construtor.  Como esse formato permite que classes e tipos fundamentais sejam construídos usando a mesma sintaxe, ele é especialmente útil na definição de classes de modelo.

A *palavra-chave* é **uma de dynamic_cast**, **static_cast** ou **reinterpret_cast**.  Mais informações podem ser encontradas em **dynamic_cast,** **static_cast** e **reinterpet_cast**.

O operador **digitado** é considerado uma expressão postfix.  Consulte **o operador digitado**.

## <a name="formal-and-actual-arguments"></a>Argumentos formais e reais

Chamar programas transmite informações às funções chamadas em “argumentos reais”. As funções chamadas acessam as informações usando “argumentos formais” correspondentes.

Quando uma função for chamada, as seguintes tarefas serão executadas:

- Todos os argumentos reais (aqueles fornecidos pelo chamador) são avaliados. Não há nenhuma ordem implícita na qual esses argumentos são avaliados, mas todos os argumentos são avaliados e todos os efeitos colaterais são concluídos antes da entrada na função.

- Cada argumento formal é inicializado com seu argumento correspondente na lista de expressões. (Um argumento formal é um argumento que é declarado no cabeçalho da função e usado no corpo de uma função.) As conversões são feitas como se por inicialização — tanto conversões padrão quanto definidas pelo usuário sejam realizadas na conversão de um argumento real para o tipo correto. A inicialização executada é ilustrada de modo conceitual pelo seguinte código:

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

   A inicialização é executada como se estivesse usando a sintaxe de sinal de igualdade em vez de sintaxe de parênteses. Uma cópia de `i` é feita antes de transmitir o valor à função. (Para obter mais informações, consulte [Inicializadores](../cpp/initializers.md) e [Conversões](../cpp/user-defined-type-conversions-cpp.md)).

   Portanto, se o protótipo de função (declaração) exige um argumento de tipo **longo**, e se o programa de chamada fornece um argumento real de tipo **int,** o argumento real é promovido usando uma conversão de tipo padrão para digitar **long** (ver [Conversões Padrão](../cpp/standard-conversions.md)).

   É um erro fornecer um argumento real para o qual não há conversão padrão ou definida pelo usuário para o tipo de argumento formal.

   Para argumentos reais de tipos de classe, o argumento formal é inicializado chamando o construtor da classe. (Consulte [Construtores](../cpp/constructors-cpp.md) para saber mais sobre essas funções especiais de membro de classe.)

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

Quando `func` é chamado do principal, `param1` o parâmetro formal `i` é`i` inicializado com o valor de ( é convertido para tipo `param2` **longo** para corresponder ao tipo correto usando uma conversão padrão), e o parâmetro formal é inicializado com o valor de `j` (`j` é convertido para tipo **duplo** usando uma conversão padrão).

## <a name="treatment-of-argument-types"></a>Tratamento de tipos de argumentos

Os argumentos formais declarados como tipos const não podem ser alterados dentro do corpo de uma função. As funções podem alterar qualquer argumento que não seja do tipo **const**. No entanto, a alteração é local para a função e não afeta o valor real do argumento, a menos que o argumento real fosse uma referência a um objeto não de tipo **const**.

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

## <a name="ellipsis-and-default-arguments"></a>Elipses e argumentos padrão

As funções podem ser declaradas para aceitar menos argumentos do que o especificado na definição da função, usando um de dois métodos: reticências (`...`) ou argumentos padrão.

Ellipsis denota que os argumentos podem ser necessários, mas que o número e os tipos não estão especificados na declaração. Essa geralmente é uma prática inadequada de programação do C++ porque ela elimina um dos benefícios de segurança do tipo C++:. Diferentes conversões são aplicadas a funções declaradas com elipse do que às funções para as quais os tipos de argumento formal e real são conhecidos:

- Se o argumento real for de tipo **flutuante,** ele é promovido a digitar **o dobro** antes da chamada de função.

- Qualquer **char**assinado ou não assinado, **tipo curto**e enumerado ou bit é convertido em um **int** assinado ou não assinado usando promoção integral.

- Qualquer argumento de tipo de classe é passado por valor como estrutura de dados; a cópia é criada por cópia binário em vez de chamar o construtor de cópia de classe (se houver).

A ellipsis, se usada, deve ser declarada em último na lista de argumentos. Para obter mais informações sobre como passar um número variável de argumentos, consulte a discussão sobre [va_arg, va_start e va_list](../c-runtime-library/reference/va-arg-va-copy-va-end-va-start.md) na *Referência da Biblioteca em Tempo de Execução*.

Para obter informações sobre argumentos padrão na programação CLR, consulte [Listas de argumentos variáveis (...) (C++/CLI)](../extensions/variable-argument-lists-dot-dot-dot-cpp-cli.md).

Os argumentos padrão permitem que você especifique o valor que um argumento deverá assumir caso nenhum seja fornecido na chamada de função. O fragmento de código a seguir mostra como os argumentos padrão funcionam. Para obter mais informações sobre restrições à especificação de argumentos padrão, consulte [Argumentos padrão](../cpp/default-arguments.md).

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

O programa anterior declara uma função, `print`, que usa dois argumentos. No entanto, o segundo argumento, `"\n"` *exterminador,* tem um valor padrão, . Em `main`, as duas `print` primeiras chamadas para permitir que o segundo argumento padrão forneça uma nova linha para encerrar a seqüência impressa. A terceira chamada especifica um valor explícito para o segundo argumento. A saída do programa é

```Output
hello,
world!
good morning, sunshine.
```

## <a name="see-also"></a>Confira também

[Tipos de expressões](../cpp/types-of-expressions.md)
