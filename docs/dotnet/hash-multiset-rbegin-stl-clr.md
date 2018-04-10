---
title: 'hash_multiset:: rbegin (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-windows
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- cliext::hash_multiset::rbegin
dev_langs:
- C++
helpviewer_keywords:
- rbegin member [STL/CLR]
ms.assetid: 69a06d99-3262-495b-9956-5f155162da33
caps.latest.revision: 15
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: ba6880567d5380f95fc3400f02d01c5da21ec938
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hashmultisetrbegin-stlclr"></a>hash_multiset::rbegin (STL/CLR)
Designa o início da sequência controlada invertida.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
reverse_iterator rbegin();  
```  
  
## <a name="remarks"></a>Comentários  
 A função de membro retorna um iterador inverso que designa o último elemento da sequência controlada ou logo após o início de uma sequência vazia. Portanto, ele designa o `beginning` da sequência inversa. Você pode usá-lo para obter um iterador que designa o `current` pode alterá-início da sequência controlada visto na ordem inversa, mas seu status se altera o comprimento da sequência controlada.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_hash_multiset_rbegin.cpp   
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
  
// inspect first two items in reversed sequence   
    Myhash_multiset::reverse_iterator rit = c1.rbegin();   
    System::Console::WriteLine("*rbegin() = {0}", *rit);   
    System::Console::WriteLine("*++rbegin() = {0}", *++rit);   
    return (0);   
    }  
  
```  
  
```Output  
 a b c  
*rbegin() = c  
*++rbegin() = b  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/hash_set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_multiset (STL/CLR)](../dotnet/hash-multiset-stl-clr.md)   
 [hash_multiset:: Begin (STL/CLR)](../dotnet/hash-multiset-begin-stl-clr.md)   
 [hash_multiset:: end (STL/CLR)](../dotnet/hash-multiset-end-stl-clr.md)   
 [hash_multiset::rend (STL/CLR)](../dotnet/hash-multiset-rend-stl-clr.md)