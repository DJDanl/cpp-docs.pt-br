---
title: "decltype (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "decltype"
  - "decltype_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador decltype"
  - "operadores [C++], decltype"
  - "operadores [C++], tipo de expressão deduce"
  - "operadores [C++], tipo de uma expressão"
ms.assetid: 6dcf8888-8196-4f13-af50-51e3797255d4
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# decltype (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O especificador de tipo `decltype` produz o tipo de uma expressão especificada.  O especificador de tipo `decltype`, juntamente com a [palavra\-chave auto](../cpp/auto-cpp.md), é útil principalmente para desenvolvedores que escrevem bibliotecas de modelos.  Use `auto` e `decltype` para declarar uma função de modelo cujo tipo de retorno dependa dos tipos dos argumentos de modelo.  Ou então, use `auto` e `decltype` para declarar uma função de modelo que encapsule uma chamada para outra função e depois retorne o tipo de retorno da função encapsulada.  
  
## Sintaxe  
  
```  
decltype( expression )  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`expression`|Uma expressão.  Para obter mais informações, consulte [Expressões](../cpp/expressions-cpp.md).|  
  
## Valor de retorno  
 O tipo do parâmetro `expression`.  
  
## Comentários  
 O especificador de tipo `decltype` tem suporte no Visual C\+\+ 2010 e em versões posteriores, e pode ser usado com código nativo ou gerenciado.  `decltype(auto)` \(C \+ \+ 14\) tem suporte no Visual Studio de 2015 e versões posteriores.  
  
 O compilador usa as regras a seguir para determinar o tipo do parâmetro `expression`.  
  
-   Se o parâmetro `expression` é um identificador ou um [acesso de membro de classe](../Topic/Member%20Access%20Operators:%20.%20and%20-%3E.md), `decltype(``expression``)` é o tipo da entidade nomeada por `expression`.  Caso essa entidade não exista ou o parâmetro `expression` nomeie um conjunto de funções sobrecarregadas, o compilador produz uma mensagem de erro.  
  
-   Se o parâmetro `expression` é uma chamada para uma função ou para uma função de operador sobrecarregado, `decltype(``expression``)` é o tipo de retorno da função.  Os parênteses em torno de um operador sobrecarregado são ignorados.  
  
-   Se o parâmetro `expression` é um [rvalue](../Topic/Lvalues%20and%20Rvalues%20\(Visual%20C++\).md), `decltype(``expression``)` é o tipo de `expression`.  Se o parâmetro `expression` é um [lvalue](../Topic/Lvalues%20and%20Rvalues%20\(Visual%20C++\).md), `decltype(``expression``)` é uma [referência de lvalue](../Topic/Lvalue%20Reference%20Declarator:%20&.md) ao tipo de `expression`.  
  
 O exemplo de código a seguir demonstra alguns usos do especificador de tipo `decltype`.  Primeiro, suponha que você tenha codificado as instruções a seguir.  
  
```  
int var;  
const int&& fx();   
struct A { double x; }  
const A* a = new A();  
```  
  
 Depois, examine os tipos que são retornados pelas quatro instruções `decltype` na tabela a seguir.  
  
|Instrução|Tipo|Observações|  
|---------------|----------|-----------------|  
|`decltype(fx());`|`const int&&`|Uma [referência de rvalue](../cpp/rvalue-reference-declarator-amp-amp.md) a um `const int`.|  
|`decltype(var);`|`int`|O tipo da variável `var`.|  
|`decltype(a->x);`|`double`|O tipo do acesso de membro.|  
|`decltype((a->x));`|`const double&`|Os parênteses internos fazem com que a instrução seja avaliada como uma expressão em vez de um acesso de membro.  Como `a` é declarado como um ponteiro `const`, o tipo é uma referência a `const double`.|  
  
## Decltype e auto  
 No C\+\+ 14, você pode usar `decltype(auto)` com nenhum tipo de retorno à direita para declarar uma função de modelo cujo tipo de retorno depende dos tipos dos argumentos de modelo.  
  
 No C\+\+ 11, você pode usar o `decltype` Digite especificador em um tipo de retorno à direita, junto com o `auto` palavra\-chave para declarar uma função de modelo cujo tipo de retorno depende dos tipos dos argumentos de modelo.  Por exemplo, considere o exemplo de código a seguir, no qual o tipo de retorno da função de modelo depende dos tipos dos argumentos de modelo.  No exemplo de código, o *desconhecido* espaço reservado indica que o tipo de retorno não pode ser especificado.  
  
```  
template<typename T, typename U>  
UNKNOWN func(T&& t, U&& u){ return t + u; };   
```  
  
 A introdução do especificador de tipo `decltype` permite que um desenvolvedor obtenha o tipo da expressão que a função de modelo retorna.  Use a *sintaxe de declaração de função alternativa* que é mostrada posteriormente, a palavra\-chave `auto` e o especificador de tipo `decltype` para declarar um tipo de retorno *com especificação tardia*.  O tipo de retorno com especificação tardia é determinado quando a declaração é compilada, não quando ela é codificada.  
  
 O protótipo a seguir ilustra a sintaxe de uma declaração de função alternativa.  Observe que o `const` e `volatile` qualificadores e o `throw` [especificação de exceção](../cpp/exception-specifications-throw-cpp.md) são opcionais.  O *function\_body* espaço reservado representa uma instrução composta que especifica que a função faz.  Como uma melhor prática de codificação, o *expressão* espaço reservado a `decltype` instrução deve corresponder à expressão especificada pelo `return` instrução, se houver, no *function\_body*.  
  
 `auto` *function\_name*`(`*parameters*opt`)` `const`opt `volatile`opt `−>` `decltype(`*expression*`)` `throw`opt `{`*function\_body*`};`  
  
 No exemplo de código a seguir, o tipo de retorno com especificação tardia da função de modelo `myFunc` é determinado pelos tipos dos argumentos de modelo `t` e `u`.  Como uma melhor prática de codificação, o exemplo de código também usa referências de rvalue e o modelo de função `forward`, que oferecem suporte ao *encaminhamento perfeito*.  Para obter mais informações, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
```  
//C++11  
 template<typename T, typename U>  
auto myFunc(T&& t, U&& u) -> decltype (forward<T>(t) + forward<U>(u))   
        { return forward<T>(t) + forward<U>(u); };  
  
//C++14  
template<typename T, typename U>  
decltype(auto) myFunc(T&& t, U&& u)   
        { return forward<T>(t) + forward<U>(u); };  
  
```  
  
## Decltype e funções de encaminhamento \(C \+ \+ 11\)  
 As funções de encaminhamento encapsulam chamadas para outras funções.  Considere um modelo de função que encaminha seus argumentos, ou os resultados de uma expressão que envolve esses argumentos, para outra função.  Além disso, a função de encaminhamento retorna o resultado da chamada para a outra função.  Nesse cenário, o tipo de retorno da função de encaminhamento deve ser igual ao tipo de retorno da função encapsulada.  
  
 Nesse cenário, você não pode escrever uma expressão de tipo apropriada sem o especificador de tipo `decltype`.  O especificador de tipo `decltype` habilita funções genéricas de encaminhamento porque não perde informações necessárias sobre se uma função retorna \(ou não\) um tipo de referência.  Para obter um exemplo de código de uma função de encaminhamento, consulte o exemplo anterior da função de modelo `myFunc`.  
  
## Exemplo  
 O exemplo de código a seguir declara o tipo de retorno com especificação tardia da função de modelo `Plus()`.  A função `Plus` processa seus dois operandos com a sobrecarga `operator+`.  Consequentemente, a interpretação do operador de adição \(\+\) e do tipo de retorno da função `Plus` depende dos tipos dos argumentos de função.  
  
```  
// decltype_1.cpp  
// compile with: /EHsc  
//  
#include "stdafx.h"  
#include <iostream>  
#include <string>  
#include <utility>  
#include <iomanip>  
  
using namespace std;  
  
template<typename T1, typename T2>  
auto Plus(T1&& t1, T2&& t2) ->   
   decltype(forward<T1>(t1) + forward<T2>(t2))  
{  
   return forward<T1>(t1) + forward<T2>(t2);  
}  
  
class X  
{  
   friend X operator+(const X& x1, const X& x2)  
   {  
      return X(x1.m_data + x2.m_data);  
   }  
  
public:  
   X(int data) : m_data(data) {}  
   int Dump() const { return m_data;}  
private:  
   int m_data;  
};  
  
int main()  
{  
   // Integer   
   int i = 4;  
   cout <<   
      "Plus(i, 9) = " <<   
      Plus(i, 9) << endl;  
  
   // Floating point  
   float dx = 4.0;  
   float dy = 9.5;  
   cout <<     
      setprecision(3) <<   
      "Plus(dx, dy) = " <<  
      Plus(dx, dy) << endl;  
  
   // String        
   string hello = "Hello, ";  
   string world = "world!";  
   cout << Plus(hello, world) << endl;  
  
   // Custom type  
   X x1(20);  
   X x2(22);  
   X x3 = Plus(x1, x2);  
   cout <<   
      "x3.Dump() = " <<   
      x3.Dump() << endl;  
}  
```  
  
 **Saída**  
  
 Esse exemplo de código produz os seguintes resultados:  
  
 13  
  
 13.5  
  
 Hello, world\!  
  
 42  
  
## Requisitos  
 Visual C\+\+ 2010 ou versões posteriores.  
  
 decltype\(Auto\) requer o Visual Studio 2015 ou posterior  
  
## Consulte também  
 [\(NOTINBUILD\)Simple Type Names](http://msdn.microsoft.com/pt-br/333f45cb-2c72-4d81-8e59-e346b05f55e3)