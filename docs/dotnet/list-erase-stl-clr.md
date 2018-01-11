---
title: 'List:: Erase (STL/CLR) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::list::erase
dev_langs: C++
helpviewer_keywords: erase member [STL/CLR]
ms.assetid: 78705058-1e83-441d-b267-d4fb56451c0b
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 54595b61ddd21ccd81cf4f2846224789861cb480
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="listerase-stlclr"></a>list::erase (STL/CLR)
Remove os elementos em posições especificadas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
iterator erase(iterator where);  
iterator erase(iterator first, iterator last);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 primeiro  
 Início do intervalo a ser apagado.  
  
 last  
 Fim do intervalo a ser apagado.  
  
 onde  
 Elemento apagar.  
  
## <a name="remarks"></a>Comentários  
 A primeira função de membro remove o elemento de sequência controlada apontada pelo `where`. Você pode usá-lo para remover um único elemento.  
  
 A segunda função de membro remove os elementos da sequência controlada no intervalo [`first`, `last`). Você pode usá-lo para remover a zero ou mais elementos contíguos.  
  
 Ambas as funções de membro retornam um iterador que designa o primeiro elemento restantes além de quaisquer elementos removidos, ou [List:: end (STL/CLR)](../dotnet/list-end-stl-clr.md) `()` se esse elemento não existe.  
  
 Ao apagar elementos, o número de cópias do elemento é linear no número de elementos entre o fim de apagamento e a extremidade mais próximo da sequência de. (Quando apagando um ou mais elementos em ambas as extremidades da sequência, nenhuma cópia do elemento ocorre).  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_list_erase.cpp   
// compile with: /clr   
#include <cliext/list>   
  
int main()   
    {   
    cliext::list<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// erase an element and reinspect   
    System::Console::WriteLine("erase(begin()) = {0}",   
        *c1.erase(c1.begin()));   
  
// add elements and display " b c d e"   
    c1.push_back(L'd');   
    c1.push_back(L'e');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// erase all but end   
    cliext::list<wchar_t>::iterator it = c1.end();   
    System::Console::WriteLine("erase(begin(), end()-1) = {0}",   
        *c1.erase(c1.begin(), --it));   
    System::Console::WriteLine("size() = {0}", c1.size());   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
erase(begin()) = b  
 b c d e  
erase(begin(), end()-1) = e  
size() = 1  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/lista >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [lista (STL/CLR)](../dotnet/list-stl-clr.md)   
 [list::clear (STL/CLR)](../dotnet/list-clear-stl-clr.md)