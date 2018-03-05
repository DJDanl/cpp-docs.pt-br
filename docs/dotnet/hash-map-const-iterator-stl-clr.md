---
title: 'hash_map:: const_iterator (STL/CLR) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- cliext::hash_map::const_iterator
dev_langs:
- C++
helpviewer_keywords:
- const_iterator member [STL/CLR]
ms.assetid: a1750775-a657-4c9f-8194-c2af938e39ff
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 0b7559c47238fecb20b93425fb17d2f618c3937b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hashmapconstiterator-stlclr"></a>hash_map::const_iterator (STL/CLR)
O tipo de um iterador de constante para a sequência controlada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef T2 const_iterator;  
```  
  
## <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo especificado `T2` que pode servir como um iterador de constante bidirecional para a sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_hash_map_const_iterator.cpp   
// compile with: /clr   
#include <cliext/hash_map>   
  
typedef cliext::hash_map<wchar_t, int> Myhash_map;   
int main()   
    {   
    Myhash_map c1;   
    c1.insert(Myhash_map::make_value(L'a', 1));   
    c1.insert(Myhash_map::make_value(L'b', 2));   
    c1.insert(Myhash_map::make_value(L'c', 3));   
  
// display contents " [a 1] [b 2] [c 3]"   
    Myhash_map::const_iterator cit = c1.begin();   
    for (; cit != c1.end(); ++cit)   
        System::Console::Write(" [{0} {1}]", cit->first, cit->second);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3]  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/hash_map >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_map (STL/CLR)](../dotnet/hash-map-stl-clr.md)   
 [hash_map::iterator (STL/CLR)](../dotnet/hash-map-iterator-stl-clr.md)