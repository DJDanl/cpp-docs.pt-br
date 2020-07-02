---
title: 'Operador de chamada de função: ()'
ms.date: 06/11/2020
helpviewer_keywords:
- ( ) function call operator
- function calls, C++ functions
- () function call operator
- postfix operators [C++]
- function calls, operator
- functions [C++], function-call operator
- function call operator ()
ms.assetid: 50c92e59-a4bf-415a-a6ab-d66c679ee80a
no-loc:
- opt
ms.openlocfilehash: 5bb87795d3e91d853dc0d269ee9d2aa3ba025c0e
ms.sourcegitcommit: 83ea5df40917885e261089b103d5de3660314104
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/01/2020
ms.locfileid: "85813544"
---
# <a name="function-call-operator-"></a>Operador de chamada da função: ()

Uma chamada de função é um tipo de *`postfix-expression`* , formada por uma expressão que é avaliada como uma função ou um objeto que possa ser chamado, seguido pelo operador de chamada de função, **`()`** . Um objeto pode declarar uma `operator ()` função, que fornece semântica de chamada de função para o objeto.

## <a name="syntax"></a>Syntax

> *`postfix-expression`*:\
> &emsp;*`postfix-expression`* **`(`** *`argument-expression-list`* <sub>opt</sub> **`)`**

## <a name="remarks"></a>Comentários

Os argumentos para o operador de chamada de função são provenientes de uma *`argument-expression-list`* lista de expressões separadas por vírgulas. Os valores dessas expressões são passados para a função como argumentos. A *lista de expressão de argumento* pode estar vazia. Antes do C++ 17, a ordem de avaliação da expressão de função e as expressões de argumento não são especificadas e podem ocorrer em qualquer ordem. No C++ 17 e posteriores, a expressão de função é avaliada antes de qualquer expressão de argumento ou argumentos padrão. As expressões de argumento são avaliadas em uma sequência indeterminada.

O *`postfix-expression`* é avaliado para a função a ser chamada. Ele pode ter várias formas:

- um identificador de função, visível no escopo atual ou no escopo de qualquer um dos argumentos de função fornecidos,
- uma expressão que é avaliada como uma função, um ponteiro de função, um objeto que possa ser chamado ou uma referência a uma,
- um acessador de função membro, explícito ou implícito,
- um ponteiro de referência para uma função de membro.

O *`postfix-expression`* pode ser um identificador de função sobrecarregado ou um acessador de função de membro sobrecarregado. As regras para resolução de sobrecarga determinam a função real a ser chamada. Se a função de membro for virtual, a função a ser chamada será determinada em tempo de execução.

Algumas declarações de exemplo:

- Tipo de retorno de função `T`. Uma declaração de exemplo é

    ```cpp
    T func( int i );
    ```

- Tipo de retorno de ponteiro para uma função `T`. Uma declaração de exemplo é

    ```cpp
    T (*func)( int i );
    ```

- Tipo de retorno de referência para uma função `T`. Uma declaração de exemplo é

    ```cpp
    T (&func)(int i);
    ```

- Tipo de retorno de desreferência de ponteiro para função de membro `T`. As chamadas de função de exemplo são

    ```cpp
    (pObject->*pmf)();
    (Object.*pmf)();
    ```

## <a name="example"></a>Exemplo

O exemplo a seguir chama a função de biblioteca padrão `strcat_s` com três argumentos:

```cpp
// expre_Function_Call_Operator.cpp
// compile with: /EHsc

#include <iostream>
#include <string>

// C++ Standard Library name space
using namespace std;

int main()
{
    enum
    {
        sizeOfBuffer = 20
    };

    char s1[ sizeOfBuffer ] = "Welcome to ";
    char s2[ ] = "C++";

    strcat_s( s1, sizeOfBuffer, s2 );

    cout << s1 << endl;
}
```

```Output
Welcome to C++
```

## <a name="function-call-results"></a>Resultados da chamada de função

Uma chamada de função é avaliada como um Rvalue, a menos que a função seja declarada como um tipo de referência. As funções com tipos de retorno de referência são avaliadas como lvalue. Essas funções podem ser usadas no lado esquerdo de uma instrução de atribuição, como visto aqui:

```cpp
// expre_Function_Call_Results.cpp
// compile with: /EHsc
#include <iostream>
class Point
{
public:
    // Define "accessor" functions as
    // reference types.
    unsigned& x() { return _x; }
    unsigned& y() { return _y; }
private:
    unsigned _x;
    unsigned _y;
};

using namespace std;
int main()
{
    Point ThePoint;

    ThePoint.x() = 7;           // Use x() as an l-value.
    unsigned y = ThePoint.y();  // Use y() as an r-value.

    // Use x() and y() as r-values.
    cout << "x = " << ThePoint.x() << "\n"
         << "y = " << ThePoint.y() << "\n";
}
```

O código anterior define uma classe chamada `Point` , que contém objetos de dados privados que representam coordenadas *x* e *y* . Esses objetos de dados devem ser alterados e seus valores recuperados. Esse programa é apenas um de vários projetos para essa classe; o uso das funções `GetX` e `SetX` ou `GetY` e `SetY` é outro projeto possível.

As funções que retornam tipos de classe, os ponteiros para tipos de classe ou referências a tipos de classe podem ser usados como o operando à esquerda para operadores de seleção de membros. O código a seguir é legal:

```cpp
// expre_Function_Results2.cpp
class A {
public:
   A() {}
   A(int i) {}
   int SetA( int i ) {
      return (I = i);
   }

   int GetA() {
      return I;
   }

private:
   int I;
};

A func1() {
   A a = 0;
   return a;
}

A* func2() {
   A *a = new A();
   return a;
}

A& func3() {
   A *a = new A();
   A &b = *a;
   return b;
}

int main() {
   int iResult = func1().GetA();
   func2()->SetA( 3 );
   func3().SetA( 7 );
}
```

As funções podem ser chamadas recursivamente. Para obter mais informações sobre declarações de função, consulte [funções](functions-cpp.md). O material relacionado está em [unidades de tradução e vinculação](../cpp/program-and-linkage-cpp.md).

## <a name="see-also"></a>Veja também

[Expressões pós-fixadas](../cpp/postfix-expressions.md)<br/>
[Operadores, precedência e Associação internos do C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Chamada de função](../c-language/function-call-c.md)
