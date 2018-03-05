---
title: "Operador de chamada de função: () | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- ( ) function call operator
- function calls, C++ functions
- () function call operator
- postfix operators [C++]
- function calls, operator
- functions [C++], function-call operator
- function call operator ()
ms.assetid: 50c92e59-a4bf-415a-a6ab-d66c679ee80a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6aa2a61dff4f20c5da7157a8a60700d9a8a10c06
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="function-call-operator-"></a>Operador de chamada da função: ()
Uma expressão de sufixo seguida pelo operador de chamada de função, **()**, especifica uma chamada de função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
postfix-expression   
( [argument-expression-list ] )  
```  
  
## <a name="remarks"></a>Comentários  
 Os argumentos para o operador de chamada de função são zero ou mais expressões separadas por vírgulas — os argumentos reais para a função.  
  
 O *sufixo expressão* devem ser avaliadas como o endereço de uma função (por exemplo, um identificador de função ou o valor de um ponteiro de função), e *lista de expressões de argumento* é uma lista de expressões (separados por vírgulas) cujos valores (argumentos) são passados para a função. O argumento *argument-expression-list* pode estar vazio.  
  
 O *sufixo expressão* deve ser um destes tipos:  
  
-   Tipo de retorno de função `T`. Uma declaração de exemplo é  
  
    ```  
    T func( int i )  
    ```  
  
-   Tipo de retorno de ponteiro para uma função `T`. Uma declaração de exemplo é  
  
    ```  
    T (*func)( int i )  
    ```  
  
-   Tipo de retorno de referência para uma função `T`. Uma declaração de exemplo é  
  
    ```  
    T (&func)(int i)  
    ```  
  
-   Tipo de retorno de desreferência de ponteiro para função de membro `T`. As chamadas de função de exemplo são  
  
    ```  
    (pObject->*pmf)();  
    (Object.*pmf)();  
    ```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir chama a função de biblioteca padrão `strcat_s` com três argumentos:  
  
```  
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
 Uma chamada de função é avaliada como um r-value, a menos que a função seja declarada como do tipo referência. As funções com o tipo de retorno de referência são avaliadas como l-values e podem ser usadas no lado esquerdo de uma instrução de atribuição, como segue:  
  
```  
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
  
 O código anterior define uma classe chamada `Point`, que contém dados particulares objetos que representam *x* e *y* coordenadas. Esses objetos de dados devem ser alterados e seus valores recuperados. Esse programa é apenas um de vários projetos para essa classe; o uso das funções `GetX` e `SetX` ou `GetY` e `SetY` é outro projeto possível.  
  
 As funções que retornam tipos de classe, os ponteiros para tipos de classe ou referências a tipos de classe podem ser usados como o operando à esquerda para operadores de seleção de membros. Portanto, o código a seguir é válido:  
  
```  
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
  
 As funções podem ser chamadas recursivamente. Para obter mais informações sobre declarações de função, consulte [funções](functions-cpp.md). Material relacionado está em [programa e ligação](../cpp/program-and-linkage-cpp.md).  
  
## <a name="see-also"></a>Consulte também  
 [Expressões pós-fixadas](../cpp/postfix-expressions.md)   
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Chamada de função](../c-language/function-call-c.md)   
