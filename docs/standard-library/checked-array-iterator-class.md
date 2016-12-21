---
title: "Classe checked_array_iterator | Microsoft Docs"
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
  - "iterator/checked_array_iterator"
  - "checked_array_iterator"
  - "std::checked_array_iterator"
  - "std.checked_array_iterator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "checked_array_iterator"
  - "Classe checked_array_iterator"
  - "checked_array_iterator, sintaxe"
ms.assetid: 7f07185e-d588-4ae3-9c4f-84ec4aa25a28
caps.latest.revision: 28
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe checked_array_iterator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe `checked_array_iterator` permite que você transforme uma matriz ou um ponteiro em um iterador verificado.  Use essa classe como um wrapper \(usando a função [make\_checked\_array\_iterator](../Topic/make_checked_array_iterator.md)\) para matrizes ou ponteiros brutos como uma maneira direcionada de fornecer verificação e gerenciar avisos de ponteiros não verificados, em vez de silenciar esses avisos globalmente.  Se necessário, você pode usar a versão não verificada da classe, [unchecked\_array\_iterator](../standard-library/unchecked-array-iterator-class.md).  
  
> [!NOTE]
>  Essa classe é uma extensão da Biblioteca Padrão do C\+\+ da Microsoft.  O código implementado usando essa função não é portátil para ambientes de criação do C\+\+ Standard que não oferecem suporte a essa extensão da Microsoft.  Para ver um exemplo que demonstra como escrever código que não exige uso dessa classe, veja o segundo exemplo abaixo.  
  
## Sintaxe  
  
```  
template <class _Iterator>  
    class checked_array_iterator;  
```  
  
## Comentários  
 Essa classe é definida no namespace [stdext](../Topic/stdext%20Namespace.md).  
  
 Para obter mais informações e código de exemplo sobre o recurso iterador verificado, consulte[Iteradores Verificados](../standard-library/checked-iterators.md).  
  
## Exemplo  
 O exemplo a seguir mostra como definir e usar um iterador de matriz verificado.  
  
 Se o destino não for grande o suficiente para armazenar todos os elementos que estão sendo copiados, como seria se você tivesse alterado a linha:  
  
```cpp  
copy(a, a + 5, checked_array_iterator<int*>(b, 5));  
```  
  
 até  
  
```cpp  
copy(a, a + 5, checked_array_iterator<int*>(b, 4));  
```  
  
 Ocorrerá um erro de tempo de execução.  
  
```cpp  
// compile with: /EHsc /W4 /MTd  
#include <algorithm>  
#include <iostream>  
  
using namespace std;  
using namespace stdext;  
  
int main() {  
   int a[]={0, 1, 2, 3, 4};  
   int b[5];  
   copy(a, a + 5, checked_array_iterator<int*>(b, 5));  
  
   cout << "(";  
   for (int i = 0 ; i < 5 ; i++)  
      cout << " " << b[i];  
   cout << " )" << endl;  
  
   // constructor example  
   checked_array_iterator<int*> checked_out_iter(b, 5);  
   copy(a, a + 5, checked_out_iter);  
  
   cout << "(";  
   for (int i = 0 ; i < 5 ; i++)  
      cout << " " << b[i];  
   cout << " )" << endl;  
}  
```  
  
  **\( 0 1 2 3 4 \)**  
**\( 0 1 2 3 4 \)**   
## Exemplo  
 Para evitar a necessidade da classe `checked_array_iterator` ao usar algoritmos da Biblioteca Padrão do C\+\+, pense em usar um `vector` em vez de uma matriz dinamicamente alocada.  O exemplo a seguir demonstra como fazer isso.  
  
```cpp  
// compile with: /EHsc /W4 /MTd  
  
#include <algorithm>  
#include <iostream>  
#include <vector>  
  
using namespace std;  
  
int main()  
{  
    std::vector<int> v(10);  
    int *arr = new int[10];  
    for (int i = 0; i < 10; ++i)  
    {  
        v[i] = i;  
        arr[i] = i;  
    }  
  
    // std::copy(v.begin(), v.end(), arr); will result in  
    // warning C4996. To avoid this warning while using int *,  
    // use the Microsoft extension checked_array_iterator.  
    std::copy(v.begin(), v.end(),  
              stdext::checked_array_iterator<int *>(arr, 10));  
  
    // Instead of using stdext::checked_array_iterator and int *,  
    // consider using std::vector to encapsulate the array. This will  
    // result in no warnings, and the code will be portable.  
    std::vector<int> arr2(10);    // Similar to int *arr = new int[10];  
    std::copy(v.begin(), v.end(), arr2.begin());  
  
    for (int j = 0; j < arr2.size(); ++j)  
    {  
        cout << " " << arr2[j];  
    }  
    cout << endl;  
  
    return 0;  
}  
```  
  
  **0 1 2 3 4 5 6 7 8 9**   
### Construtores  
  
|||  
|-|-|  
|[checked\_array\_iterator](../Topic/checked_array_iterator::checked_array_iterator.md)|Constrói um `checked_array_iterator` padrão ou um `checked_array_iterator` de um iterador subjacente.|  
  
### DefsTipo  
  
|||  
|-|-|  
|[difference\_type](../Topic/checked_array_iterator::difference_type.md)|Um tipo que fornece a diferença entre dois `checked_array_iterator`s que se referem a elementos no mesmo contêiner.|  
|[pointer](../Topic/checked_array_iterator::pointer.md)|Um tipo que fornece um ponteiro para um elemento tratado por um `checked_array_iterator`.|  
|[referência](../Topic/checked_array_iterator::reference.md)|Um tipo que fornece uma referência a um elemento tratado por um `checked_array_iterator`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[base](../Topic/checked_array_iterator::base.md)|Recupera o iterador subjacente de seu `checked_array_iterator`.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\=\=](../Topic/checked_array_iterator::operator==.md)|Testa a igualdade de dois `checked_array_iterator`s.|  
|[operator\!\=](../Topic/checked_array_iterator::operator!=.md)|Testa a desigualdade de dois `checked_array_iterator`s.|  
|[operador \<](../Topic/checked_array_iterator::operator%3C.md)|Testa se o `checked_array_iterator` à esquerda do operador é menor que o `checked_array_iterator` à direita.|  
|[Operador \>](../Topic/checked_array_iterator::operator%3E.md)|Testa se o `checked_array_iterator` à esquerda do operador é maior que o `checked_array_iterator` à direita.|  
|[Operador \<\=](../Topic/checked_array_iterator::operator%3C=.md)|Testa se o `checked_array_iterator` à esquerda do operador é menor ou igual ao `checked_array_iterator` à direita.|  
|[Operador \>\=](../Topic/checked_array_iterator::operator%3E=.md)|Testa se o `checked_array_iterator` à esquerda do operador é maior ou igual ao `checked_array_iterator` à direita.|  
|[operator\*](../Topic/checked_array_iterator::operator*.md)|Retorna o elemento tratado por um `checked_array_iterator`.|  
|[operator\-\>](../Topic/checked_array_iterator::operator-%3E.md)|Retorna um ponteiro para o elemento tratado pelo `checked_array_iterator`.|  
|[operator\+\+](../Topic/checked_array_iterator::operator++.md)|Incrementa o `checked_array_iterator` até o próximo elemento.|  
|[operator\-\-](../Topic/checked_array_iterator::operator--.md)|Decrementa o `checked_array_iterator` para o elemento anterior.|  
|[operator\+\=](../Topic/checked_array_iterator::operator+=.md)|Adiciona um deslocamento especificado para um `checked_array_iterator`.|  
|[operator\+](../Topic/checked_array_iterator::operator+.md)|Adiciona um deslocamento a um iterador e retorna o novo `checked_array_iterator` que trata o elemento inserido na nova posição de deslocamento.|  
|[operator\-\=](../Topic/checked_array_iterator::operator-=.md)|Decrementa um deslocamento especificado de um `checked_array_iterator`.|  
|[operator\-](../Topic/checked_array_iterator::operator-.md)|Decrementa um deslocamento de um iterador e retorna o novo `checked_array_iterator` que trata o elemento inserido na nova posição de deslocamento.|  
|[operator&#91;&#93;](../Topic/checked_array_iterator::operator.md)|Retorna uma referência a um deslocamento do elemento tratado por um `checked_array_iterator` por um número especificado de posições.|  
  
## Requisitos  
 **Cabeçalho:** \<iterator\>  
  
 **Namespace:** stdext  
  
## Consulte também  
 [\<iterator\>](../standard-library/iterator.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)