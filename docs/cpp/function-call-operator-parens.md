---
title: "Operador de chamada da fun&#231;&#227;o: () | Microsoft Docs"
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
  - "Operador de chamada de função ( )"
  - "Operador de chamada de função ()"
  - "Operador de chamada de função ( )"
  - "chamadas de função, funções C++"
  - "chamadas de função, operator"
  - "funções [C++], Operador de chamada de função"
  - "operadores de sufixo"
ms.assetid: 50c92e59-a4bf-415a-a6ab-d66c679ee80a
caps.latest.revision: 14
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador de chamada da fun&#231;&#227;o: ()
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma expressão de sufixo seguida pelo operador de chamada de função, **\( \)**, especifica uma chamada de função.  
  
## Sintaxe  
  
```  
  
postfix-expression   
( [argument-expression-list ] )  
```  
  
## Comentários  
 Os argumentos para o operador de chamada de função são zero ou mais expressões separadas por vírgulas — os argumentos reais para a função.  
  
 O elemento *postfix\-expression* deve ser avaliado no endereço de uma função \(por exemplo, um identificador de função ou o valor de um ponteiro de função\), e o elemento *argument\-expression\-list* é uma lista de expressões \(separadas por vírgulas\) cujos valores \(argumentos\) são passados para a função.  O argumento *argument\-expression\-list* pode estar vazio.  
  
 O elemento *postfix\-expression* deve ser de um destes tipos:  
  
-   Tipo de retorno de função `T`.  Uma declaração de exemplo é  
  
    ```  
    T func( int i )  
    ```  
  
-   Tipo de retorno de ponteiro para uma função `T`.  Uma declaração de exemplo é  
  
    ```  
    T (*func)( int i )  
    ```  
  
-   Tipo de retorno de referência para uma função `T`.  Uma declaração de exemplo é  
  
    ```  
    T (&func)(int i)  
    ```  
  
-   Tipo de retorno de desreferência de ponteiro para função de membro `T`.  As chamadas de função de exemplo são  
  
    ```  
    (pObject->*pmf)();  
    (Object.*pmf)();  
    ```  
  
## Exemplo  
 O exemplo a seguir chama a função de biblioteca padrão `strcat_s` com três argumentos:  
  
```  
// expre_Function_Call_Operator.cpp  
// compile with: /EHsc  
  
#include <iostream>  
#include <string>  
  
// STL name space  
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
  
  **Bem\-vindo ao C\+\+**   
## Resultados da chamada de função  
 Uma chamada de função é avaliada como um r\-value, a menos que a função seja declarada como do tipo referência.  As funções com o tipo de retorno de referência são avaliadas como l\-values e podem ser usadas no lado esquerdo de uma instrução de atribuição, como segue:  
  
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
  
 O código anterior define uma classe chamada `Point`, que contém os objetos de dados privados que representam as coordenadas *x* e *y*.  Esses objetos de dados devem ser alterados e seus valores recuperados.  Esse programa é apenas um de vários projetos para essa classe; o uso das funções `GetX` e `SetX` ou `GetY` e `SetY` é outro projeto possível.  
  
 As funções que retornam tipos de classe, os ponteiros para tipos de classe ou referências a tipos de classe podem ser usados como o operando à esquerda para operadores de seleção de membros.  Portanto, o código a seguir é válido:  
  
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
  
 As funções podem ser chamadas recursivamente.  Para obter mais informações sobre declarações de função, consulte [Especificadores de função](../misc/function-specifiers.md) e [Funções membro](../Topic/Member%20Functions%20\(C++\).md).  O material relacionado está em [Programa e vinculação](../cpp/program-and-linkage-cpp.md).  
  
## Consulte também  
 [Expressões pós\-fixadas](../cpp/postfix-expressions.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Chamada de função](../c-language/function-call-c.md)   
 [\(NOTINBUILD\) Function Declarations](http://msdn.microsoft.com/pt-br/3f9b4e14-60d2-47c1-acd8-4fa8fc988be7)