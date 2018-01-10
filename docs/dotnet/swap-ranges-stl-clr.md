---
title: swap_ranges (STL/CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: cliext::swap_ranges
dev_langs: C++
helpviewer_keywords: swap_ranges function [STL/CLR]
ms.assetid: 3fb39a84-b088-48f1-8bb7-2bbe68b048a9
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: c3b486446ff1f2061fa28a31bceaf5e560beec15
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="swapranges-stlclr"></a>swap_ranges (STL/CLR)
Troca os elementos de um intervalo com os elementos de outro, de tamanho igual.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class _FwdIt1, class _FwdIt2> inline  
    _FwdIt2 swap_ranges(_FwdIt1 _First1, _FwdIt1 _Last1,  
        _FwdIt2 _First2);  
```  
  
## <a name="remarks"></a>Comentários  
 Essa função se comporta como a função de biblioteca padrão C++ `swap_ranges`. Para obter mais informações, consulte [swap_ranges](../standard-library/algorithm-functions.md#swap_ranges).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/algoritmo >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [algorithm (STL/CLR)](../dotnet/algorithm-stl-clr.md)