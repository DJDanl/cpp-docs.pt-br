---
title: 'deque:: end (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::deque::end
dev_langs:
- C++
helpviewer_keywords:
- end member [STL/CLR]
ms.assetid: 3de3e816-3334-4b39-97ad-6f8771e9b4e9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 46d74add9abe1d106654e99624e75a40f40ab32b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33107565"
---
# <a name="dequeend-stlclr"></a>deque::end (STL/CLR)
Designa o fim da sequência controlada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
iterator end();  
```  
  
## <a name="remarks"></a>Comentários  
 A função de membro retorna um iterador de acesso aleatório que aponta logo após o fim da sequência controlada. Você pode usá-lo para obter um iterador que designa o `current` final da sequência controlada, mas seu status pode alterar se altera o comprimento da sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_deque_end.cpp   
// compile with: /clr   
#include <cliext/deque>   
  
int main()   
    {   
    cliext::deque<wchar_t> c1;   
    c1.push_back(L'a');   
    c1.push_back(L'b');   
    c1.push_back(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect last two items   
    cliext::deque<wchar_t>::iterator it = c1.end();   
    --it;   
    System::Console::WriteLine("*-- --end() = {0}", *--it);   
    System::Console::WriteLine("*--end() = {0}", *++it);   
  
// alter first two items and reinspect   
    *--it = L'x';   
    *++it = L'y';   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
*-- --end() = b  
*--end() = c  
 a x y  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/deque >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [deque (STL/CLR)](../dotnet/deque-stl-clr.md)   
 [deque:: back (STL/CLR)](../dotnet/deque-back-stl-clr.md)   
 [deque::back_item (STL/CLR)](../dotnet/deque-back-item-stl-clr.md)   
 [deque::begin (STL/CLR)](../dotnet/deque-begin-stl-clr.md)