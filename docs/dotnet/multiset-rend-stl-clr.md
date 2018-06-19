---
title: 'multiset:: rend (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::multiset::rend
dev_langs:
- C++
helpviewer_keywords:
- rend member [STL/CLR]
ms.assetid: db84e142-efa7-4171-bad6-8132f3f5f741
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 50d87790e3165d27c7d6ca87fafb112fc51a7fde
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33135918"
---
# <a name="multisetrend-stlclr"></a>multiset::rend (STL/CLR)
Designa o fim da sequência controlada invertida.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
reverse_iterator rend();  
```  
  
## <a name="remarks"></a>Comentários  
 A função de membro retorna um iterador inverso que aponta logo após o início da sequência controlada. Portanto, ele designa o `end` da sequência inversa. Você pode usá-lo para obter um iterador que designa o `current` final da sequência controlada visto na ordem inversa, mas seu status pode alterar se altera o comprimento da sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_multiset_rend.cpp   
// compile with: /clr   
#include <cliext/set>   
  
typedef cliext::multiset<wchar_t> Mymultiset;   
int main()   
    {   
    Mymultiset c1;   
    c1.insert(L'a');   
    c1.insert(L'b');   
    c1.insert(L'c');   
  
// display initial contents " a b c"   
    for each (wchar_t elem in c1)   
        System::Console::Write(" {0}", elem);   
    System::Console::WriteLine();   
  
// inspect first two items   
    Mymultiset::reverse_iterator rit = c1.rend();   
    --rit;   
    System::Console::WriteLine("*-- --rend() = {0}", *--rit);   
    System::Console::WriteLine("*--rend() = {0}", *++rit);   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
*-- --rend() = b  
*--rend() = a  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [multiconjunto (STL/CLR)](../dotnet/multiset-stl-clr.md)   
 [multiset:: Begin (STL/CLR)](../dotnet/multiset-begin-stl-clr.md)   
 [multiset:: end (STL/CLR)](../dotnet/multiset-end-stl-clr.md)   
 [multiset::rbegin (STL/CLR)](../dotnet/multiset-rbegin-stl-clr.md)