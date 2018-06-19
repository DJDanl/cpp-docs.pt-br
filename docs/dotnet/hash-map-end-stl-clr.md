---
title: 'hash_map:: end (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::hash_map::end
dev_langs:
- C++
helpviewer_keywords:
- end member [STL/CLR]
ms.assetid: bda12a48-cc2b-426f-a4e8-992c88f61736
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 230c5a68ef4f8564769801d71a0d9bf7b0d602b4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33108321"
---
# <a name="hashmapend-stlclr"></a>hash_map::end (STL/CLR)
Designa o fim da sequência controlada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
iterator end();  
```  
  
## <a name="remarks"></a>Comentários  
 A função de membro retorna um iterador bidirecional que aponta logo após o fim da sequência controlada. Você pode usá-lo para obter um iterador que designa o fim da sequência controlada; seu status alteração não se altera o comprimento da sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_hash_map_end.cpp   
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
    for each (Myhash_map::value_type elem in c1)   
        System::Console::Write(" [{0} {1}]", elem->first, elem->second);   
    System::Console::WriteLine();   
  
// inspect last two items   
    Myhash_map::iterator it = c1.end();   
    --it;   
    --it;   
    System::Console::WriteLine("*-- --end() = [{0} {1}]",   
        it->first, it->second);   
    ++it;   
    System::Console::WriteLine("*--end() = [{0} {1}]",   
        it->first, it->second);   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
*-- --end() = [b 2]  
*--end() = [c 3]  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/hash_map >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_map (STL/CLR)](../dotnet/hash-map-stl-clr.md)   
 [hash_map::begin (STL/CLR)](../dotnet/hash-map-begin-stl-clr.md)