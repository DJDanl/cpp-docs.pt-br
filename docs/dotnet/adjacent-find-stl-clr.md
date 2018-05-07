---
title: adjacent_find (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::adjacent_find
dev_langs:
- C++
helpviewer_keywords:
- adjacent_find function
ms.assetid: 48bf57ea-b128-4d16-97c5-01d8a378369f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: ce62fd96954adb122176e02eb19c00b63d4ebbb3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="adjacentfind-stlclr"></a>adjacent_find (STL/CLR)
Procura dois elementos adjacentes que sejam iguais ou atendam a uma condição especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class _FwdIt> inline  
    _FwdIt adjacent_find(_FwdIt _First, _FwdIt _Last);  
template<class _FwdIt, class _Pr> inline  
    _FwdIt adjacent_find(_FwdIt _First, _FwdIt _Last, _Pr _Pred);  
```  
  
## <a name="remarks"></a>Comentários  
 Essa função se comporta como a função de biblioteca padrão C++ `adjacent_find`. Para obter mais informações, consulte [adjacent_find](../standard-library/algorithm-functions.md#adjacent_find).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/algoritmo >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [algorithm (STL/CLR)](../dotnet/algorithm-stl-clr.md)