---
title: nth_element (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::nth_element
dev_langs:
- C++
helpviewer_keywords:
- nth_element function [STL/CLR]
ms.assetid: 19fc1695-62a9-4f85-9920-d153c1c6481f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 4517ca62c7f7e376a13f2b3e02488d6c0256031a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="nthelement-stlclr"></a>nth_element (STL/CLR)
Partições de um intervalo de elementos, localizando corretamente o `n`elemento th da sequência do intervalo para que todos os elementos na frente dele sejam menor ou igual a ele e todos os elementos que se seguem na sequência são maior ou igual a ele.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class _RanIt> inline  
    void nth_element(_RanIt _First, _RanIt _Nth, _RanIt _Last);  
template<class _RanIt, class _Pr> inline  
    void nth_element(_RanIt _First, _RanIt _Nth, _RanIt _Last,  
        _Pr _Pred);  
```  
  
## <a name="remarks"></a>Comentários  
 Essa função se comporta como a função de biblioteca padrão C++ `nth_element`. Para obter mais informações, consulte [nth_element](../standard-library/algorithm-functions.md#nth_element).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/algoritmo >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [algorithm (STL/CLR)](../dotnet/algorithm-stl-clr.md)