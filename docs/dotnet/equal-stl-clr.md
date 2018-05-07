---
title: igual a (STL/CLR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: reference
f1_keywords:
- cliext::equal
dev_langs:
- C++
helpviewer_keywords:
- equal function [STL/CLR]
ms.assetid: 7f271666-2198-4e33-8e03-8b73b376c724
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 28eab2b2622efbc017f6568a5bef0076fd9dc98e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="equal-stlclr"></a>equal (STL/CLR)
Compara a igualdade ou equivalência de dois intervalos, elemento por elemento, de certo modo especificado por um predicado binário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<class _InIt1, class _InIt2> inline  
    bool equal(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2);  
template<class _InIt1, class _InIt2, class _Pr> inline  
    bool equal(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2,  
        _Pr _Pred);  
```  
  
## <a name="remarks"></a>Comentários  
 Essa função se comporta como a função de biblioteca padrão C++ `equal`. Para obter mais informações, consulte [igual](../standard-library/algorithm-functions.md#equal).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<cliext/algoritmo >  
  
 **Namespace:** cliext  
  
## <a name="see-also"></a>Consulte também  
 [algorithm (STL/CLR)](../dotnet/algorithm-stl-clr.md)