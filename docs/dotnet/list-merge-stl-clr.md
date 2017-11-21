---
title: 'List:: Merge (STL/CLR) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::list::merge
dev_langs: C++
helpviewer_keywords: merge member [STL/CLR]
ms.assetid: f8e93cd3-bd08-4086-859b-08a2899cc9a6
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 6547cb0a60b0e65bbfd11acd03d1d5bf7d926c86
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="listmerge-stlclr"></a>list::merge (STL/CLR)
Mescla dois ordenados sequências controladas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void merge(list<Value>% right);  
template<typename Pred2>  
    void merge(list<Value>% right, Pred2 pred);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Pred  
 Comparador para pares do elemento.  
  
 direita  
 Contêiner de mesclagem.  
  
## <a name="remarks"></a>Comentários  
 A primeira função de membro remove todos os elementos da sequência controlada por `right` e inseri-los na sequência controlada. Ambas as sequências anteriormente devem ser ordenadas por `operator<` – elementos não devem ser diminuídos em valor conforme você percorre qualquer sequência. A sequência resultante também é ordenada por `operator<`. Você pode usar essa função de membro para mesclar duas sequências que aumentam o valor em uma sequência que aumenta também o valor.  
  
 A segunda função de membro se comporta como o primeiro, exceto que as sequências são ordenadas por `pred`  --  `pred(X, Y)` deve ser false para qualquer elemento `X` que segue o elemento `Y` na sequência. Você pode usá-lo para mesclar duas sequências ordenadas por uma função de predicado ou representante que você especificar.  
  
 As funções de executam uma mesclagem estável - nenhum par de elementos em qualquer uma das sequências controladas originais é revertida na sequência controlada resultante. Além disso, se um par de elementos `X` e `Y` na sequência controlada resultante tem ordenação equivalente – `!(X < Y) && !(X < Y)` – um elemento na sequência controlada original aparece antes de um elemento de uma sequência controlada por `right`.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_list_merge.cpp   
// compile with: /clr   
#include <cliext/list>   
  
typedef cliext::list<wchar_t> Mylist;   
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'c');   
    c1.push_back(L'e');   
  
// display initial contents " a c e"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    cliext::list<wchar_t> c2;   
    c2.push_back(L'b');   
    c2.push_back(L'd');   
    c2.push_back(L'f');   
  
// display initial contents " b d f"   
    for each (wchar_t elem in c2)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// merge and display   
    cliext::list<wchar_t> c3(c1);   
    c3.merge(c2);   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("c2.size() = {0}", c2.size());   
  
// sort descending, merge descending, and redisplay   
    c1.sort(cliext::greater<wchar_t>());   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    c3.sort(cliext::greater<wchar_t>());   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
    c3.merge(c1, cliext::greater<wchar_t>());   
    for each (wchar_t elem in c3)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    System::Console::WriteLine("c1.size() = {0}", c1.size());   
    return (0);   
    }  
  
```  
  
```Output  
 a c e  
 b d f  
 a b c d e f  
c2.size() = 0  
 e c a  
 f e d c b a  
 f e e d c c b a a  
c1.size() = 0  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/lista >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [lista (STL/CLR)](../dotnet/list-stl-clr.md)   
 [List:: Sort (STL/CLR)](../dotnet/list-sort-stl-clr.md)   
 [list::splice (STL/CLR)](../dotnet/list-splice-stl-clr.md)