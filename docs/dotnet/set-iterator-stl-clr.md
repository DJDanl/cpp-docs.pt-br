---
title: 'set:: Iterator (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::set::iterator
dev_langs:
- C++
helpviewer_keywords:
- iterator member [STL/CLR]
ms.assetid: 7e54276b-4cb3-4bff-a3a6-23ae328aa369
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 28340c07ce60f509cd52b776d8d8eac3367d7a87
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="setiterator-stlclr"></a>set::iterator (STL/CLR)
O tipo de um iterador para a sequência controlada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef T1 iterator;  
```  
  
## <a name="remarks"></a>Comentários  
 O tipo descreve um objeto do tipo especificado `T1` que pode servir como um iterador bidirecional para a sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_set_iterator.cpp   
// compile with: /clr   
#include <cliext/set>   
  
typedef cliext::set<wchar_t> Myset;   
int main()   
    {   
    Myset c1;   
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
  
// display contents " a b c"   
    Myset::iterator it = c1.begin();   
    for (; it != c1.end(); ++it)   
        System::Console::Write(" {0}", *it);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
a b c  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [conjunto (STL/CLR)](../dotnet/set-stl-clr.md)   
 [set::const_iterator (STL/CLR)](../dotnet/set-const-iterator-stl-clr.md)