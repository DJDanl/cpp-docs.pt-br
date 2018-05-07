---
title: 'hash_set:: value_comp (STL/CLR) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::hash_set::value_comp
dev_langs:
- C++
helpviewer_keywords:
- value_comp member [STL/CLR]
ms.assetid: 7ef381ea-438b-48ce-b0cb-96d844ea5df7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 04b841e458809cea7ccda1fd6bc632129764ae78
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="hashsetvaluecomp-stlclr"></a>hash_set::value_comp (STL/CLR)
Copia o delegado de ordenação de dois valores de elemento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
value_compare^ value_comp();  
```  
  
## <a name="remarks"></a>Comentários  
 A função de membro retorna o delegado de classificação usado para ordenar a sequência controlada. Você pode usá-lo para comparar dois valores de elemento.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_hash_set_value_comp.cpp   
// compile with: /clr   
#include <cliext/hash_set>   
  
typedef cliext::hash_set<wchar_t> Myhash_set;   
int main()   
    {   
    Myhash_set c1;   
    Myhash_set::value_compare^ kcomp = c1.value_comp();   
  
    System::Console::WriteLine("compare(L'a', L'a') = {0}",   
        kcomp(L'a', L'a'));   
    System::Console::WriteLine("compare(L'a', L'b') = {0}",   
        kcomp(L'a', L'b'));   
    System::Console::WriteLine("compare(L'b', L'a') = {0}",   
        kcomp(L'b', L'a'));   
    System::Console::WriteLine();   
    return (0);   
    }  
  
```  
  
```Output  
compare(L'a', L'a') = True  
compare(L'a', L'b') = True  
compare(L'b', L'a') = False  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/hash_set >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [hash_set (STL/CLR)](../dotnet/hash-set-stl-clr.md)   
 [hash_set:: value_compare (STL/CLR)](../dotnet/hash-set-value-compare-stl-clr.md)   
 [hash_set::value_type (STL/CLR)](../dotnet/hash-set-value-type-stl-clr.md)