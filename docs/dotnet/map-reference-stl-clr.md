---
title: 'Map:: Reference (STL/CLR) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::map::reference
dev_langs: C++
helpviewer_keywords: reference member [STL/CLR]
ms.assetid: 7bbfeb61-f12a-42d1-b5ae-7b6421c1d33c
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 53ea7b8723a0db47e35cbacd5d9bd778543c2ea3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mapreference-stlclr"></a>map::reference (STL/CLR)
O tipo de uma referência para um elemento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef value_type% reference;  
```  
  
## <a name="remarks"></a>Comentários  
 O tipo descreve uma referência a um elemento.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_map_reference.cpp   
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
    Mymap::iterator it = c1.begin();   
    for (; it != c1.end(); ++it)   
        {   // get a reference to an element   
        Mymap::reference ref = *it;   
        System::Console::Write(" [{0} {1}]", ref->first, ref->second);   
        }   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
[a 1] [b 2] [c 3]  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/mapa >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [Map (STL/CLR)](../dotnet/map-stl-clr.md)   
 [Map:: const_reference (STL/CLR)](../dotnet/map-const-reference-stl-clr.md)   
 [map::value_type (STL/CLR)](../dotnet/map-value-type-stl-clr.md)