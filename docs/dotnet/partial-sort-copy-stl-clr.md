---
title: partial_sort_copy (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::partial_sort_copy
dev_langs:
- C++
helpviewer_keywords:
- partial_sort_copy function [STL/CLR]
ms.assetid: ed4af83e-7554-4f6d-bf54-c56fa6210fe8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 99b60d3b3384cacd7c501ea1d8beb4e76131616b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33159828"
---
# <a name="partialsortcopy-stlclr"></a>partial_sort_copy (STL/CLR)
Copia elementos de um intervalo de origem em um intervalo de destino, em que os elementos de origem são ordenados por menor que ou outro predicado binário especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class _InIt, class _RanIt> inline  
    _RanIt partial_sort_copy(_InIt _First1, _InIt _Last1,  
        _RanIt _First2, _RanIt _Last2);  
template<class _InIt, class _RanIt, class _Pr> inline  
    _RanIt partial_sort_copy(_InIt _First1, _InIt _Last1,  
        _RanIt _First2, _RanIt _Last2, _Pr _Pred);  
```  
  
## <a name="remarks"></a>Comentários  
 Essa função se comporta como a função de biblioteca padrão C++ `partial_sort_copy`. Para obter mais informações, consulte [partial_sort_copy](../standard-library/algorithm-functions.md#partial_sort_copy).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/algoritmo >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [algorithm (STL/CLR)](../dotnet/algorithm-stl-clr.md)