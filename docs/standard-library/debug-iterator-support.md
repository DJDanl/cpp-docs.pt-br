---
title: "Suporte a Iterador de Depura&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_HAS_ITERATOR_DEBUGGING symbol"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "suporte a depuração de iteradores"
  - "iteradores incompatíveis"
  - "iteradores, suporte a depuração de iteradores"
  - "iteradores, incompatíveis"
  - "Bibliotecas Seguras"
  - "Bibliotecas Seguras, Biblioteca Padrão C++"
  - "Biblioteca Padrão C++ Segura"
  - "Biblioteca Padrão C++, suporte a depuração de iteradores"
ms.assetid: f3f5bd15-4be8-4d64-a4d0-8bc0761c68b6
caps.latest.revision: 22
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Suporte a Iterador de Depura&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca de tempo de execução do Visual C\+\+ detecta o uso incorreto de iterador, e afirma e exibe uma caixa de diálogo em tempo de execução.  Para habilitar o suporte do iterador de depuração, você deve usar uma versão de depuração da biblioteca de tempo de execução c para criar seu programa.  Para obter mais informações, consulte [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).  Para obter informações sobre como usar iteradores, consulte [Iteradores Verificados](../standard-library/checked-iterators.md).  
  
 O padrão do C\+\+ descreve como as funções de membro podem fazer com que os iteradores em um contêiner sejam inválidas.  Dois exemplos são:  
  
-   Apagar um elemento de um contêiner faz com que os iteradores ao elemento se tornem inválido.  
  
-   Aumentar o tamanho de [vetor](../standard-library/vector.md) \(push ou inserção\) faz com que os iteradores em `vector` se tornem inválido.  
  
## Exemplo  
 Se você criar o seguinte programa no modo de depuração, em tempo de execução e terminará o.  
  
```cpp  
/* compile with /EHsc /MDd */  
#include <vector>  
#include <iostream>  
  
int main() {  
   std::vector<int> v ;  
  
   v.push_back(10);  
   v.push_back(15);  
   v.push_back(20);  
  
   std::vector<int>::iterator i = v.begin();  
   ++i;  
  
   std::vector<int>::iterator j = v.end();  
   --j;  
  
   std::cout<<*j<<'\n';  
  
   v.insert(i,25);   
  
   std::cout<<*j<<'\n'; // Using an old iterator after an insert  
}  
  
```  
  
## Exemplo  
 Você pode usar o símbolo [\_HAS\_ITERATOR\_DEBUGGING](../Topic/_HAS_ITERATOR_DEBUGGING.md) para desativar o recurso de depuração de iterador em uma compilação de depuração.  O seguinte programa não afirma, mas ainda dispara comportamento indefinido.  
  
> [!IMPORTANT]
>  Use `_ITERATOR_DEBUG_LEVEL` para controlar `_HAS_ITERATOR_DEBUGGING`.  Para obter mais informações, consulte [\_ITERATOR\_DEBUG\_LEVEL](../standard-library/iterator-debug-level.md).  
  
```cpp  
// iterator_debugging.cpp  
// compile with: /EHsc /MDd  
#define _HAS_ITERATOR_DEBUGGING 0  
#include <vector>  
#include <iostream>  
  
int main() {  
   std::vector<int> v ;  
  
   v.push_back(10);  
   v.push_back(15);  
   v.push_back(20);  
  
   std::vector<int>::iterator i = v.begin();  
   ++i;  
  
   std::vector<int>::iterator j = v.end();  
   --j;  
  
   std::cout<<*j<<'\n';  
  
   v.insert(i,25);   
  
   std::cout<<*j<<'\n'; // Using an old iterator after an insert  
}  
```  
  
  **20**  
**\-572662307**   
## Exemplo  
 Declarar também ocorrerá se você tentar usar como mostrado um iterador antes de ser inicializado, aqui:  
  
```cpp  
/* compile with /EHsc /MDd */  
#include <string>  
using namespace std;  
int main() {  
   string::iterator i1, i2;  
   if (i1 == i2)  
      ;  
}  
```  
  
## Exemplo  
 O exemplo de código provocará uma asserção porque os dois iteradores ao algoritmo de [for\_each](../Topic/for_each.md) são incompatíveis.  Os algoritmos verificação para determinar se os iteradores que eles são fornecidos fazem referência ao mesmo contêiner.  
  
```cpp  
/* compile with /EHsc /MDd */  
#include <algorithm>  
#include <vector>  
using namespace std;  
  
int main()  
{  
    vector<int> v1;  
    vector<int> v2;  
  
    v1.push_back(10);  
    v1.push_back(20);  
  
    v2.push_back(10);  
    v2.push_back(20);  
  
    // The next line will assert because v1 and v2 are  
    // incompatible.  
    for_each(v1.begin(), v2.end(), [] (int& elem) { elem *= 2; } );  
}  
```  
  
 Observe que este exemplo usa a expressão `[] (int& elem) { elem *= 2; }` de lambda em vez de um funtor.  Embora essa opção tem nenhum rolagem em funtor semelhante de falha \- um declarar causaria a mesma falha \- lambdas é uma maneira muito útil de realizar tarefas compactas do objeto da função.  Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../cpp/lambda-expressions-in-cpp.md).  
  
## Exemplo  
 O iterador de depuração que verifica também causa uma variável de iterador que está declarada em um loop de `for` para estar fora do escopo quando o escopo do loop de `for` termina.  
  
```cpp  
// debug_iterator.cpp  
// compile with: /EHsc /MDd  
#include <vector>  
#include <iostream>  
int main() {  
   std::vector<int> v ;  
  
   v.push_back(10);  
   v.push_back(15);  
   v.push_back(20);  
  
   for (std::vector<int>::iterator i = v.begin() ; i != v.end(); ++i)  
   ;  
   --i;   // C2065  
}  
```  
  
## Exemplo  
 Os iteradores de depuração não têm destruidores triviais.  Se um destruidor não executa, por qualquer motivo, as violações de acesso e a corrupção de dados podem ocorrer.  Considere este exemplo:  
  
```cpp  
/* compile with: /EHsc /MDd */  
#include <vector>  
struct base {  
   // FIX: uncomment the next line  
   // virtual ~base() {}  
};  
  
struct derived : base {  
   std::vector<int>::iterator m_iter;  
   derived( std::vector<int>::iterator iter ) : m_iter( iter ) {}  
   ~derived() {}  
};  
  
int main() {  
   std::vector<int> vect( 10 );  
   base * pb = new derived( vect.begin() );  
   delete pb;  // doesn't call ~derived()  
   // access violation  
}  
```  
  
## Consulte também  
 [Visão geral da STL](../standard-library/cpp-standard-library-overview.md)