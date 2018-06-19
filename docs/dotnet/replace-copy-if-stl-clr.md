---
title: replace_copy_if (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::replace_copy_if
dev_langs:
- C++
helpviewer_keywords:
- replace_copy_if function [STL/CLR]
ms.assetid: 60edf9b8-34e6-4d94-a611-363ef7b7fb80
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 7f7c266e99b5ef86b8c85c23c77a0ed3cbd2dfcf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33161740"
---
# <a name="replacecopyif-stlclr"></a>replace_copy_if (STL/CLR)
Examina cada elemento em um intervalo de origem e o substitui se ele atender a um predicado especificado ao copiar o resultado em um novo intervalo de destino.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class _InIt, class _OutIt, class _Pr, class _Ty> inline  
    _OutIt replace_copy_if(_InIt _First, _InIt _Last, _OutIt _Dest,  
        _Pr _Pred, const _Ty% _Val);  
```  
  
## <a name="remarks"></a>Comentários  
 Essa função se comporta como a função de biblioteca padrão C++ `replace_copy_if`. Para obter mais informações, consulte [replace_copy_if](../standard-library/algorithm-functions.md#replace_copy_if).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/algoritmo >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [algorithm (STL/CLR)](../dotnet/algorithm-stl-clr.md)