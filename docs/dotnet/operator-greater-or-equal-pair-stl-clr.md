---
title: operador&gt;= (pair) (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::pair::operator>=
dev_langs:
- C++
helpviewer_keywords:
- operator>= member [STL/CLR]
ms.assetid: dcc2decf-3b2b-495d-9fd5-3daba27d5096
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 396a3e076adefac3a04a85de8451a0ff9a03ab5f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33133411"
---
# <a name="operatorgt-pair-stlclr"></a>operador&gt;= (pair) (STL/CLR)
Par de maior que ou igual comparação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename Value1,  
    typename Value2>  
    bool operator>=(pair<Value1, Value2>% left,  
        pair<Value1, Value2>% right);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 esquerda  
 Par esquerdo a ser comparado.  
  
 direita  
 Par correto a ser comparado.  
  
## <a name="remarks"></a>Comentários  
 Retorna a função de operador `!(left < right)`. Você pode usá-lo para testar se `left` não for ordenado antes `right` quando dois pares são comparado elemento pelo elemento.  
  
## <a name="example"></a>Exemplo  
  
```  
// cliext_pair_operator_ge.cpp   
// compile with: /clr   
#include <cliext/utility>   
  
int main()   
    {   
    cliext::pair<wchar_t, int> c1(L'x', 3);   
    System::Console::WriteLine("[{0}, {1}]", c1.first, c1.second);   
    cliext::pair<wchar_t, int> c2(L'x', 4);   
    System::Console::WriteLine("[{0}, {1}]", c2.first, c2.second);   
  
    System::Console::WriteLine("[x 3] >= [x 3] is {0}",   
        c1 >= c1);   
    System::Console::WriteLine("[x 3] >= [x 4] is {0}",   
        c1 >= c2);   
    return (0);   
    }  
  
```  
  
```Output  
[x, 3]  
[x, 4]  
[x 3] >= [x 3] is True  
[x 3] >= [x 4] is False  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/utilitário >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [par (STL/CLR)](../dotnet/pair-stl-clr.md)   
 [operador = = (pair) (STL/CLR)](../dotnet/operator-equality-pair-stl-clr.md)   
 [operador! = (pair) (STL/CLR)](../dotnet/operator-inequality-pair-stl-clr.md)   
 [operador\< (pair) (STL/CLR)](../dotnet/operator-less-than-pair-stl-clr.md)   
 [operador > (pair) (STL/CLR)](../dotnet/operator-greater-than-pair-stl-clr.md)   
 [operator<= (pair) (STL/CLR)](../dotnet/operator-less-or-equal-pair-stl-clr.md)