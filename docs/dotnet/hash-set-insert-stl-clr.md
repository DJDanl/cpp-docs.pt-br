---
title: "hash_set::insert (STL/CLR) | Microsoft Docs"
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
  - "cliext::hash_set::insert"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "inserir membro [STL/CLR]"
ms.assetid: 0a9bc9aa-012e-4101-9e8c-f1f4b6b76af7
caps.latest.revision: 14
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# hash_set::insert (STL/CLR)
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
// cliext_hash_set_insert.cpp   
// compile with: /clr   
#include <cliext/hash_set>   
  
typedef cliext::hash_set<wchar_t> Myhash_set;   
typedef Myhash_set::pair_iter_bool Pairib;   
int main()   
    {   
    Myhash_set c1;   
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert a single value, unique and duplicate   
    Pairib pair1 = c1.insert(L'x');   
    System::Console::WriteLine("insert(L'x') = [{0} {1}]",   
        *pair1.first, pair1.second);   
  
    pair1 = c1.insert(L'b');   
    System::Console::WriteLine("insert(L'b') = [{0} {1}]",   
        *pair1.first, pair1.second);   
  
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert a single value with hint   
    System::Console::WriteLine("insert(begin(), L'y') = {0}",   
        *c1.insert(c1.begin(), L'y'));   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert an iterator range   
    Myhash_set c2;   
    Myhash_set::iterator it = c1.end();   
    c2.insert(c1.begin(), --it);   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// insert an enumeration   
    Myhash_set c3;   
    c3.insert(   // NOTE: cast is not needed   
        (System::Collections::Generic::IEnumerable<wchar_t>^)%c1);   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
  **um b c**  
**insert \(\) \= \[L'xx true\]**  
**insert \(\) \= \[L'bb false\]**  
 **um b c x**  
**insert\(begin\(\), L'y\) \= y**  
 **um b c x y**  
 **um b c x**  
 **um b c x y**   
## Requisitos  
 cliext \<\/hash\_set de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [hash\_set](../dotnet/hash-set-stl-clr.md)