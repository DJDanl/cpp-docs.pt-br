---
title: sort_heap (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::sort_heap
dev_langs:
- C++
helpviewer_keywords:
- sort_heap function [STL/CLR]
ms.assetid: a8fa6b76-90cd-413b-9c5b-f65b93d4bbed
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: c9db31945e8e767c9b1f1a9a4d16513b704e5e52
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="sortheap-stlclr"></a>sort_heap (STL/CLR)
Converte um heap em um intervalo classificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class _RanIt> inline  
    void sort_heap(_RanIt _First, _RanIt _Last);  
template<class _RanIt, class _Pr> inline  
    void sort_heap(_RanIt _First, _RanIt _Last, _Pr _Pred);  
```  
  
## <a name="remarks"></a>Comentários  
 Essa função se comporta como a função de biblioteca padrão C++ `sort_heap`. Para obter mais informações, consulte [sort_heap](../standard-library/algorithm-functions.md#sort_heap).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/algoritmo >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [algorithm (STL/CLR)](../dotnet/algorithm-stl-clr.md)