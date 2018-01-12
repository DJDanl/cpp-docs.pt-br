---
title: multiset::make_value (STL/CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::multiset::make_value
dev_langs: C++
helpviewer_keywords: make_value member [STL/CLR]
ms.assetid: 385ded5b-65bf-4806-8c3d-a4129a05f612
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: a0da7494efb2bfe2f5fbd4e5e4b9dad18468dd28
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="multisetmakevalue-stlclr"></a>multiset::make_value (STL/CLR)
Constrói um objeto de valor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
static value_type make_value(key_type key);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 key  
 Valor da chave a ser usado.  
  
## <a name="remarks"></a>Comentários  
 A função de membro retorna um `value_type` objeto cuja chave `key`. Você pode usá-lo para compor um objeto adequado para uso com várias outras funções de membro.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_multiset_make_value.cpp   
// compile with: /clr   
#include <cliext/set>   
  
typedef cliext::multiset<wchar_t> Mymultiset;   
int main()   
    {   
    Mymultiset c1;   
    c1.insert(Mymultiset::make_value(L'a'));   
    c1.insert(Mymultiset::make_value(L'b'));   
    c1.insert(Mymultiset::make_value(L'c'));   
  
// display contents " a b c"   
    for each (Mymultiset::value_type elem in c1)   
        System::Console::Write(" {0}", elem);   
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
 [multiconjunto (STL/CLR)](../dotnet/multiset-stl-clr.md)   
 [multiset:: key_type (STL/CLR)](../dotnet/multiset-key-type-stl-clr.md)   
 [multiset::value_type (STL/CLR)](../dotnet/multiset-value-type-stl-clr.md)