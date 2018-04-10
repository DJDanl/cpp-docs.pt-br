---
title: 'hash_multiset:: Erase (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- cliext::hash_multiset::erase
dev_langs:
- C++
helpviewer_keywords:
- erase member [STL/CLR]
ms.assetid: bddd329d-aece-4b93-8355-005351c3aa45
caps.latest.revision: 16
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 9e2e35eeecab632371922705cc95848e84a46d1d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hashmultiseterase-stlclr"></a>hash_multiset::erase (STL/CLR)
Remove os elementos em posições especificadas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
iterator erase(iterator where);  
iterator erase(iterator first, iterator last);  
bool erase(key_type key)  
```  
  
#### <a name="parameters"></a>Parâmetros  
 primeiro  
 Início do intervalo a ser apagado.  
  
 key  
 Valor de chave para apagar.  
  
 last  
 Fim do intervalo a ser apagado.  
  
 onde  
 Elemento apagar.  
  
## <a name="remarks"></a>Comentários  
 A primeira função de membro remove o elemento de sequência controlada apontada pelo `where`e retorna um iterador que designa o primeiro elemento restantes além do elemento removido, ou [hash_multiset:: end (STL/CLR)](../dotnet/hash-multiset-end-stl-clr.md) `()` se esse elemento não existe. Você pode usá-lo para remover um único elemento.  
  
 A segunda função de membro remove os elementos da sequência controlada no intervalo [`first`, `last`) e retorna um iterador que designa o primeiro elemento restantes além de quaisquer elementos removidos, ou `end()` se esse elemento não existe. Você pode usá-lo para remover a zero ou mais elementos contíguos.  
  
 A terceira função do membro remove um elemento de sequência controlada cuja chave tem ordenação equivalente para `key`e retorna uma contagem do número de elementos removidos. Você pode usá-lo para remover e contagem de todos os elementos que correspondem a uma chave especificada.  
  
 A eliminação de cada elemento demora proporcional de logaritmo do número de elementos na sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_hash_multiset_erase.cpp   
// compile with: /clr   
#include <cliext/hash_set>   
  
typedef cliext::hash_multiset<wchar_t> Myhash_multiset;   
int main()   
    {   
    Myhash_multiset c1;   
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// erase an element and reinspect   
    System::Console::WriteLine("erase(begin()) = {0}",   
        *c1.erase(c1.begin()));   
  
// add elements and display " b c d e"   
    c1.insert(L'd');   
    c1.insert(L'e');   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// erase all but end   
    Myhash_multiset::iterator it = c1.end();   
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
 **Cabeçalho:** \<cliext/hash_set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_multiset (STL/CLR)](../dotnet/hash-multiset-stl-clr.md)   
 [hash_multiset::clear (STL/CLR)](../dotnet/hash-multiset-clear-stl-clr.md)