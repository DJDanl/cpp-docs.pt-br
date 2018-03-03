---
title: 'Hstring:: Operator&lt; operador | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString::operator<
dev_langs:
- C++
ms.assetid: 48a051cb-4609-42be-b48c-d35fc99d1eab
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4cbb21e34255d5350702d949792656bdf0a849a8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hstringoperatorlt-operator"></a>Hstring:: Operator&lt; operador
Indica se o primeiro parâmetro é menor do que o segundo parâmetro.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
inline bool operator<(  
    const HString& lhs,   
    const HString& rhs) throw()  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `lhs`  
 O primeiro parâmetro para comparar. `lhs`pode ser uma referência a um HString.  
  
 `rhs`  
 O segundo parâmetro para comparar. `rhs`pode ser uma referência a um HString.  
  
## <a name="return-value"></a>Valor de retorno  
 `true`Se o `lhs` parâmetro é menor do que o `rhs` parâmetro; caso contrário, `false`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HString](../windows/hstring-class.md)