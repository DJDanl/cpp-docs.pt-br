---
title: 'hash_map:: Erase (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::hash_map::erase
dev_langs:
- C++
helpviewer_keywords:
- erase member [STL/CLR]
ms.assetid: 1d2a79aa-62f7-461c-8f7c-7b660eb189be
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 827791bc90ddea7026582c18ea14eadeb96e7512
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33110371"
---
# <a name="hashmaperase-stlclr"></a>hash_map::erase (STL/CLR)
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
 A primeira função de membro remove o elemento de sequência controlada apontada pelo `where`e retorna um iterador que designa o primeiro elemento restantes além do elemento removido, ou [hash_map:: end (STL/CLR)](../dotnet/hash-map-end-stl-clr.md) `()` se esse elemento não existe. Você pode usá-lo para remover um único elemento.  
  
 A segunda função de membro remove os elementos da sequência controlada no intervalo [`first`, `last`) e retorna um iterador que designa o primeiro elemento restantes além de quaisquer elementos removidos, ou `end()` se esse elemento não existe. Você pode usá-lo para remover a zero ou mais elementos contíguos.  
  
 A terceira função do membro remove um elemento de sequência controlada cuja chave tem ordenação equivalente para `key`e retorna uma contagem do número de elementos removidos. Você pode usá-lo para remover e contagem de todos os elementos que correspondem a uma chave especificada.  
  
 A eliminação de cada elemento demora proporcional de logaritmo do número de elementos na sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_hash_map_erase.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_map<wchar_t, int> Myhash_map;   
int main()   
    {   
    cliext::hash_map<wchar_t, int> c1;   
    c1.insert(cliext::hash_map<wchar_t, int>::make_value(L'a', 1));   
    c1.insert(cliext::hash_map<wchar_t, int>::make_value(L'b', 2));   
    c1.insert(cliext::hash_map<wchar_t, int>::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    for each (cliext::hash_map<wchar_t, int>::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// erase an element and reinspect   
    cliext::hash_map<wchar_t, int>::iterator it =   
        c1.erase(c1.begin());   
    System::Console::WriteLine("erase(begin()) = [{0} {1}]",   
        it->first, it->second);   
  
// add elements and display " b c d e"   
    c1.insert(cliext::hash_map<wchar_t, int>::make_value(L'd', 4));   
    c1.insert(cliext::hash_map<wchar_t, int>::make_value(L'e', 5));   
    for each (cliext::hash_map<wchar_t, int>::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// erase all but end   
    it = c1.end();   
    it = c1.erase(c1.begin(), --it);   
    System::Console::WriteLine("erase(begin(), end()-1) = [{0} {1}]",   
        it->first, it->second);   
    System::Console::WriteLine("size() = {0}", c1.size());   
  
// erase end   
    System::Console::WriteLine("erase(L'x') = {0}", c1.erase(L'x'));   
    System::Console::WriteLine("erase(L'e') = {0}", c1.erase(L'e'));   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
erase(begin()) = [b 2]  
 [b 2] [c 3] [d 4] [e 5]  
erase(begin(), end()-1) = [e 5]  
size() = 1  
erase(L'x') = 0  
erase(L'e') = 1  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/hash_map >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_map (STL/CLR)](../dotnet/hash-map-stl-clr.md)   
 [hash_map::clear (STL/CLR)](../dotnet/hash-map-clear-stl-clr.md)