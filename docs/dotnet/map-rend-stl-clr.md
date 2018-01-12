---
title: 'Map:: rend (STL/CLR) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::map::rend
dev_langs: C++
helpviewer_keywords: rend member [STL/CLR]
ms.assetid: 132d9a82-f76a-4f3e-8d21-26de17e1245f
caps.latest.revision: "15"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: eeafd4d7c6cf0fc6d79d17c462115297ad7cbc71
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="maprend-stlclr"></a>map::rend (STL/CLR)
Designa o fim da sequência controlada invertida.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
reverse_iterator rend();  
```  
  
## <a name="remarks"></a>Comentários  
 A função de membro retorna um iterador inverso que aponta logo após o início da sequência controlada. Portanto, ele designa o `end` da sequência inversa. Você pode usá-lo para obter um iterador que designa o `current` final da sequência controlada visto na ordem inversa, mas seu status pode alterar se altera o comprimento da sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_map_rend.cpp   
// compile with: /clr   
#include <cliext/map>   
  
typedef cliext::map<wchar_t, int> Mymap;   
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
  
// inspect first two items in reversed sequence   
    Mymap::reverse_iterator rit = c1.rend();   
    --rit;   
    --rit;   
    System::Console::WriteLine("*-- --rend() = [{0} {1}]",   
        rit->first, rit->second);   
    ++rit;   
    System::Console::WriteLine("*--rend() = [{0} {1}]",   
        rit->first, rit->second);   
    return (0);   
    }  
  
```  
  
```Output  
 [a 1] [b 2] [c 3]  
*-- --rend() = [b 2]  
*--rend() = [a 1]  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/mapa >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [Map (STL/CLR)](../dotnet/map-stl-clr.md)   
 [Map:: Begin (STL/CLR)](../dotnet/map-begin-stl-clr.md)   
 [Map:: end (STL/CLR)](../dotnet/map-end-stl-clr.md)   
 [map::rbegin (STL/CLR)](../dotnet/map-rbegin-stl-clr.md)