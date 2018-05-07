---
title: make_pair (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::make_pair
dev_langs:
- C++
helpviewer_keywords:
- make_pair function [STL/CLR]
ms.assetid: 74733f2c-97b0-4d69-b431-5ab8f0de9e3e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 99e2cc7bc7255940b28f2f85dae1a7cbebd6df46
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="makepair-stlclr"></a>make_pair (STL/CLR)
Fazer um `pair` de um par de valores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value1,  
    typename Value2>  
    pair<Value1, Value2> make_pair(Value1 first, Value2 second);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Value1`  
 O tipo do primeiro valor encapsulado.  
  
 `Value2`  
 O tipo do segundo valor encapsulado.  
  
 `first`  
 Primeiro valor a ser quebrado.  
  
 `second`  
 Segundo valor a ser quebrado.  
  
## <a name="remarks"></a>Comentários  
 A função do modelo retorna `pair<Value1, Value2>(first, second)`. Você pode usá-lo para construir um `pair<Value1, Value2>` objeto a partir de um par de valores.  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// cliext_make_pair.cpp   
// compile with: /clr   
#include <cliext/utility>   
  
int main()   
    {   
    cliext::pair<wchar_t, int> c1(L'x', 3);   
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);   
  
    c1 = cliext::make_pair(L'y', 4);   
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);   
    return (0);   
    }  
  
```  
  
```Output  
[x, 3]  
[y, 4]  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/utilitário >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [range_adapter (STL/CLR)](../dotnet/range-adapter-stl-clr.md)