---
title: 'Vector:: Erase (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::vector::erase
dev_langs:
- C++
helpviewer_keywords:
- erase member [STL/CLR]
ms.assetid: 624905eb-83c0-499b-a07a-c10aebd7acc3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 87e6d3dae3423763ec110e8999c6fd5ede1a6bc9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33170002"
---
# <a name="vectorerase-stlclr"></a>vector::erase (STL/CLR)
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
  
 Ambas as funções de membro retornam um iterador que designa o primeiro elemento restantes além de quaisquer elementos removidos, ou [Vector:: end (STL/CLR)](../dotnet/vector-end-stl-clr.md) `()` se esse elemento não existe.  
  
 Ao apagar elementos, o número de cópias do elemento é linear no número de elementos entre o fim de apagamento e a extremidade mais próximo da sequência de. (Quando apagando um ou mais elementos em ambas as extremidades da sequência, nenhuma cópia do elemento ocorre).  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_vector_erase.cpp   
// compile with: /clr   
#include <cliext/vector>   
  
int main()   
    {   
    cliext::vector<wchar_t> c1;   
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
    cliext::vector<wchar_t>::iterator it = c1.end();   
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
 **Cabeçalho:** \<cliext/vetor >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [vetor (STL/CLR)](../dotnet/vector-stl-clr.md)   
 [vector::clear (STL/CLR)](../dotnet/vector-clear-stl-clr.md)