---
title: "map::insert (STL/CLR) | Microsoft Docs"
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
  - "cliext::map::insert"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "inserir membro [STL/CLR]"
ms.assetid: 599c702e-7db0-45b8-8247-4ff041a3639c
caps.latest.revision: 16
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# map::insert (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Adiciona os elementos.  
  
## Sintaxe  
  
```  
cliext::pair<iterator, bool> insert(value_type val);  
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
  
 A primeira função de membro se esforça inserir um elemento com valor `val`, e retorna um par de valores `X`.  Se `X.second` for true, `X.first` designa o elemento inserido recentemente; se não `X.first` designa um elemento com equivalente de ordenação que já existir e nenhum novo elemento foi inserido.  Você usará para inserir um único elemento.  
  
 A segunda função de membro insere um elemento com valor `val`, usando `where` como uma dica \(para melhorar o desempenho\), e retorna um iterador que designa o elemento inserido recentemente.  Use\-a para inserir um único elemento que pode ser em conjunto em um elemento que você saiba.  
  
 A terceira função de membro insere a sequência `[``first``,` `last``)`.  Use\-a para inserir zero ou mais elementos copiados de outra sequência.  
  
 A quarta função de membro insere a sequência designada por `right`.  Use\-a para inserir uma sequência descrita por um enumerador.  
  
 Cada inserção de elemento usa o tempo proporcionais ao logaritmo o número de elementos na sequência controlada.  A inserção pode ocorrer em tempo amortizados constantes, porém, uma dica dados que designa um elemento adjacente ao ponto de inserção.  
  
## Exemplo  
  
```  
// cliext_map_insert.cpp   
// compile with: /clr   
#include <cliext/map>   
  
typedef cliext::map<wchar_t, int> Mymap;   
typedef Mymap::pair_iter_bool Pairib;   
int main()   
    {   
    Mymap c1;   
    c1.insert(Mymap::make_value(L'a', 1));   
    c1.insert(Mymap::make_value(L'b', 2));   
    c1.insert(Mymap::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (Mymap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// insert a single value, unique and duplicate   
// insert a single value, success and failure   
    Pairib pair1 = c1.insert(Mymap::make_value(L'x', 24));   
    System::Console::WriteLine("insert([L'x' 24]) = [[{0} {1}] {2}]",   
        pair1.first->first, pair1.first->second, pair1.second);   
  
    pair1 = c1.insert(Mymap::make_value(L'b', 2));   
    System::Console::WriteLine("insert([L'b' 2]) = [[{0} {1}] {2}]",   
        pair1.first->first, pair1.first->second, pair1.second);   
  
    for each (Mymap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// insert a single value with hint   
    Mymap::iterator it =   
        c1.insert(c1.begin(), Mymap::make_value(L'y', 25));   
    System::Console::WriteLine("insert(begin(), [L'y' 25]) = [{0} {1}]",   
        it->first, it->second);   
    for each (Mymap::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// insert an iterator range   
    Mymap c2;   
    it = c1.end();   
    c2.insert(c1.begin(), --it);   
    for each (Mymap::value_type elem in c2)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// insert an enumeration   
    Mymap c3;   
    c3.insert(   // NOTE: cast is not needed   
        (System::Collections::Generic::   
            IEnumerable<Mymap::value_type>^)%c1);   
    for each (Mymap::value_type elem in c3)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **um \[1\] \[2\] \[b3 c\]**  
**insert \(\[L'x 24 \= \[\[\]\)X 24\] true\]**  
**insert \(\[L'b 2 \= \[\[\]\)B 2\] false\]**  
 **um \[1\] b \[2\] \[3\] \[cx 24\]**  
**insert\(begin\(\), \[L'y 25 \= \[\]\)y 25\]**  
 **um \[1\] \[2\] b c \[3\] \[\] \[24 xy 25\]**  
 **um \[1\] b \[2\] \[3\] \[cx 24\]**  
 **um \[1\] \[2\] b c \[3\] \[\] \[24 xy 25\]**   
## Requisitos  
 cliext \<\/mapa de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [map](../dotnet/map-stl-clr.md)