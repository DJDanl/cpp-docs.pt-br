---
title: copy_backward (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::copy_backward
dev_langs:
- C++
helpviewer_keywords:
- copy_backward function [STL/CLR]
ms.assetid: 649db3fd-5a79-44b6-bea9-ecbcbeba1f32
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 5ff5b52b356d4601ac671f148a4b0464f69f3a16
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="copybackward-stlclr"></a>copy_backward (STL/CLR)
Atribui os valores dos elementos de um intervalo de origem a um intervalo de destino, iterando pela sequência de elementos de origem e atribuindo-lhes novas posições em uma direção retroativa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class _BidIt1, class _BidIt2> inline  
    _BidIt2 copy_backward(_BidIt1 _First, _BidIt1 _Last,  
        _BidIt2 _Dest);  
```  
  
## <a name="remarks"></a>Comentários  
 Essa função se comporta como a função de biblioteca padrão C++ `copy_backward`. Para obter mais informações, consulte [copy_backward](../standard-library/algorithm-functions.md#copy_backward).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/algoritmo >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [algorithm (STL/CLR)](../dotnet/algorithm-stl-clr.md)