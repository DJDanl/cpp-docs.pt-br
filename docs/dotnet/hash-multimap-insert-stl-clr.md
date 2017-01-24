---
title: "hash_multimap::insert (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_multimap::insert"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "inserir membro [STL/CLR]"
ms.assetid: 51cd98b0-c959-4a44-b914-582c00681bd7
caps.latest.revision: 15
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_multimap::insert (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Adiciona os elementos.  
  
## Sintaxe  
  
```  
iterator insert(value_type val);  
iterator insert(iterator where, value_type val);  
template<typename InIter>  
    void insert(InIter first, InIter last);  
void insert(System::Collections::Generic::IEnumerable<value_type>^ right);  
```  
  
#### Parâmetros  
 primeiro  
 Início do intervalo a ser inserido.  
  
 last  
 O fim do intervalo a ser inserido.  
  
 direita  
 Enumeração o a ser inserido.  
  
 val  
 Valor de chave a ser inserido.  
  
 onde  
 Onde no contêiner inserir \(dica somente\).  
  
## Comentários  
 Cada uma das funções de membro insere uma sequência especificada pelos operandos restantes.  
  
 A primeira função de membro insere um elemento com valor `val`, e retorna um iterador que designa o elemento inserido recentemente.  Você usará para inserir um único elemento.  
  
 A segunda função de membro insere um elemento com valor `val`, usando `where` como uma dica \(para melhorar o desempenho\), e retorna um iterador que designa o elemento inserido recentemente.  Use\-a para inserir um único elemento que pode ser em conjunto em um elemento que você saiba.  
  
 A terceira função de membro insere a sequência `[``first``,` `last``)`.  Use\-a para inserir zero ou mais elementos copiados de outra sequência.  
  
 A quarta função de membro insere a sequência designada por `right`.  Use\-a para inserir uma sequência descrita por um enumerador.  
  
 Cada inserção de elemento usa o tempo proporcionais ao logaritmo o número de elementos na sequência controlada.  A inserção pode ocorrer em tempo amortizados constantes, porém, uma dica dados que designa um elemento adjacente ao ponto de inserção.  
  
## Exemplo  
  
```  
// cliext_hash_multimap_insert.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_multimap<wchar_t, int> Myhash_multimap;   
int main()   
    {   
    Myhash_multimap c1;   
    c1.insert(Myhash_multimap::make_value(L'a', 1));   
    c1.insert(Myhash_multimap::make_value(L'b', 2));   
    c1.insert(Myhash_multimap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// insert a single value, unique and duplicate   
    Myhash_multimap::iterator it =   
        c1.insert(Myhash_multimap::make_value(L'x', 24));   
    System::Console::WriteLine("insert([L'x' 24]) = [{0} {1}]",   
        it->first, it->second);   
  
    it = c1.insert(Myhash_multimap::make_value(L'b', 2));   
    System::Console::WriteLine("insert([L'b' 2]) = [{0} {1}]",   
        it->first, it->second);   
  
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// insert a single value with hint   
    it = c1.insert(c1.begin(), Myhash_multimap::make_value(L'y', 25));   
    System::Console::WriteLine("insert(begin(), [L'y' 25]) = [{0} {1}]",   
        it->first, it->second);   
    for each (Myhash_multimap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// insert an iterator range   
    Myhash_multimap c2;   
    it = c1.end();   
    c2.insert(c1.begin(), --it);   
    for each (Myhash_multimap::value_type elem in c2)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// insert an enumeration   
    Myhash_multimap c3;   
    c3.insert(   // NOTE: cast is not needed   
        (System::Collections::Generic::   
            IEnumerable<Myhash_multimap::value_type>^)%c1);   
    for each (Myhash_multimap::value_type elem in c3)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **um \[1\] \[2\] \[b3 c\]**  
**insert \(\[L'x 24 \= \[\]\)x 24\]**  
**insert \(\[L'b 2 \= \[\]\)b 2\]**  
 **um \[1\] \[2\] b b \[2\] \[3\] \[cx 24\]**  
**insert\(begin\(\), \[L'y 25 \= \[\]\)y 25\]**  
 **um \[1\] \[2\] \[b e c\] 2 \[3\] \[\] \[24 xy 25\]**  
 **um \[1\] \[2\] b b \[2\] \[3\] \[cx 24\]**  
 **um \[1\] \[2\] \[b e c\] 2 \[3\] \[\] \[24 xy 25\]**   
## Requisitos  
 cliext \<\/hash\_map de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_multimap](../dotnet/hash-multimap-stl-clr.md)