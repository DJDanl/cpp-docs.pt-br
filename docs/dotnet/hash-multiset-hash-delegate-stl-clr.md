---
title: hash_multiset::hash_delegate (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::hash_multiset::hash_delegate
dev_langs:
- C++
helpviewer_keywords:
- hash_delegate member [STL/CLR]
ms.assetid: 61ccfdfb-6a3c-40aa-902f-49e004a31a75
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 838680260226d222207e1d385f2c0ff25d83e372
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="hashmultisethashdelegate-stlclr"></a>hash_multiset::hash_delegate (STL/CLR)
Localiza um elemento que corresponde a uma chave especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
hasher^ hash_delegate();  
```  
  
## <a name="remarks"></a>Comentários  
 A função de membro retorna o representante usado para converter um valor de chave para um número inteiro. Você pode usá-lo para uma chave de hash.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_hash_multiset_hash_delegate.cpp   
// compile with: /clr   
#include <cliext/hash_set>   
  
typedef cliext::hash_multiset<wchar_t> Myhash_multiset;   
int main()   
    {   
    Myhash_multiset c1;   
    Myhash_multiset::hasher^ myhash = c1.hash_delegate();   
  
    System::Console::WriteLine("hash(L'a') = {0}", myhash(L'a'));   
    System::Console::WriteLine("hash(L'b') = {0}", myhash(L'b'));   
    return (0);   
    }  
  
```  
  
```Output  
hash(L'a') = 1616896120  
hash(L'b') = 570892832  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/hash_set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_multiset (STL/CLR)](../dotnet/hash-multiset-stl-clr.md)   
 [hash_multiset::hasher (STL/CLR)](../dotnet/hash-multiset-hasher-stl-clr.md)