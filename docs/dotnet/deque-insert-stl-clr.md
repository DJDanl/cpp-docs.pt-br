---
title: "deque::insert (STL/CLR) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "cliext::deque::insert"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "inserir membro [STL/CLR]"
ms.assetid: a3b86c46-e6a8-42d0-b642-5a8f05ddd68c
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# deque::insert (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Adiciona os elementos em uma posição especificada.  
  
## Sintaxe  
  
```  
iterator insert(iterator where, value_type val);  
void insert(iterator where, size_type count, value_type val);  
template<typename InIt>  
    void insert(iterator where, InIt first, InIt last);  
void insert(iterator where,  
    System::Collections::Generic::IEnumerable<Value>^ right);  
```  
  
#### Parâmetros  
 count  
 Número de elementos a ser inserido.  
  
 primeiro  
 Início do intervalo a ser inserido.  
  
 last  
 O fim do intervalo a ser inserido.  
  
 direita  
 Enumeração o a ser inserido.  
  
 val  
 Valor do elemento a ser inserido.  
  
 onde  
 Onde no contêiner inserir antes.  
  
## Comentários  
 Cada uma das funções de membro, insere antes do elemento apontado por `where` na sequência controlada, uma sequência especificada pelos operandos restantes.  
  
 A primeira função de membro insere um elemento com valor `val` e retorna um iterador que designa o elemento inserido recentemente.  Use\-a para inserir um único elemento antes de um local designado por um iterador.  
  
 A segunda função de membro insere uma reprodução dos elementos de `count` de valor `val`.  Use\-a para inserir elementos zero ou mais contíguas que são todas as cópias do mesmo valor.  
  
 Se `InIt` é do tipo inteiro, a terceira função de membro se comportará da mesma maneira que `insert(``where``, (size_type)``first``, (value_type)``last``)`.  Se não, insere a sequência `[``first``,` `last``)`.  Use\-a para inserir elementos zero ou mais contíguos copiado de outra sequência.  
  
 A quarta função de membro insere a sequência designada por `right`.  Use\-a para inserir uma sequência descrita por um enumerador.  
  
 Ao inserir um único elemento, o número de cópias do elemento é linear no número de elementos entre o ponto de inserção e término mais próximo da sequência. \(Ao inserir um ou mais elementos em um ou outro fim de sequência, nenhuma cópia do elemento ocorre.\) Se `InIt` é um iterador de entrada, a terceira função de membro é efetivamente uma única inserção para cada elemento na sequência.  Caso contrário, ao inserir elementos de `N` , o número de cópias do elemento é linear em `N` mais o número de elementos entre o ponto de inserção e término mais próximo da sequência.  
  
## Exemplo  
  
```  
// cliext_deque_insert.cpp   
// compile with: /clr   
#include <cliext/deque>   
  
int main()   
    {   
    cliext::deque<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert a single value using iterator   
    cliext::deque<wchar_t>::iterator it = c1.begin();   
    System::Console::WriteLine("insert(begin()+1, L'x') = {0}",   
        *c1.insert(++it, L'x'));   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert a repetition of values   
    cliext::deque<wchar_t> c2;   
    c2.insert(c2.begin(), 2, L'y');   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert an iterator range   
    it = c1.end();   
    c2.insert(c2.end(), c1.begin(), --it);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert an enumeration   
    c2.insert(c2.begin(),   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c1);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **um b c**  
**insert\(begin\(\)\+1, L'x\) \= x**  
 **um x b c**  
 **y y**  
 **y um x y b**  
 **um x y b c um x y b**   
## Requisitos  
 **Cabeçalho:** \<cliext\/deque\>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [deque](../dotnet/deque-stl-clr.md)   
 [deque::assign](../dotnet/deque-assign-stl-clr.md)