---
title: partial_sum (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::partial_sum
dev_langs:
- C++
helpviewer_keywords:
- partial_sum function [STL/CLR]
ms.assetid: 845badae-8519-4ac8-9ea7-2b921bac7c51
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 0c8141e93d7c8101c9bbfaea08c317748cd44f87
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="partialsum-stlclr"></a>partial_sum (STL/CLR)
Calcula uma série de somas em um intervalo de entrada do primeiro elemento por meio de `i`elemento th e armazena o resultado de cada essa soma em `i`elemento th de um intervalo de destino ou calcula o resultado de um procedimento generalizado onde a operação de soma é substituída por outra operação binário especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class _InIt, class _OutIt> inline  
    _OutIt partial_sum(_InIt _First, _InIt _Last, _OutIt _Dest);  
template<class _InIt, class _OutIt, class _Fn2> inline  
    _OutIt partial_sum(_InIt _First, _InIt _Last,  
        _OutIt _Dest, _Fn2 _Func);  
```  
  
## <a name="remarks"></a>Comentários  
 Essa função se comporta como a função numérica da biblioteca padrão C++ `partial_sum`. Para obter mais informações, consulte [partial_sum](../standard-library/numeric-functions.md#partial_sum).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/numeric >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [numeric (STL/CLR)](../dotnet/numeric-stl-clr.md)