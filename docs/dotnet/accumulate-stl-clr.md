---
title: Acumular (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::accumulate
dev_langs:
- C++
helpviewer_keywords:
- accumulate function [STL/CLR]
ms.assetid: b80e1ef1-1858-4c1d-817b-c42ad1f17a2f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 128fe8e46c24b8e0595fe19c0075933d3e5069a6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33103158"
---
# <a name="accumulate-stlclr"></a>accumulate (STL/CLR)
Calcula a soma de todos os elementos em um intervalo especificado, incluindo qualquer valor inicial ao calcular somas parciais sucessivas ou calcula o resultado de resultados parciais sucessivos obtidos usando uma operação binária especificada diferente da soma.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class _InIt, class _Ty> inline  
    _Ty accumulate(_InIt _First, _InIt _Last, _Ty _Val);  
template<class _InIt, class _Ty, class _Fn2> inline  
    _Ty accumulate(_InIt _First, _InIt _Last, _Ty _Val, _Fn2 _Func);  
```  
  
## <a name="remarks"></a>Comentários  
 Essa função se comporta como a função numérica da biblioteca padrão C++ `accumulate`. Para obter mais informações, consulte [acumular](../standard-library/numeric-functions.md#accumulate).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/numeric >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [numeric (STL/CLR)](../dotnet/numeric-stl-clr.md)