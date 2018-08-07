---
title: Operador hstring::&lt; operador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString::operator<
dev_langs:
- C++
ms.assetid: 48a051cb-4609-42be-b48c-d35fc99d1eab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: de7ffb304a8b2f1567ed5510c276c454903ec930
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39608398"
---
# <a name="hstringoperatorlt-operator"></a>Operador hstring::&lt; operador
Indica se o primeiro parâmetro é menor do que o segundo parâmetro.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
inline bool operator<(  
    const HString& lhs,   
    const HString& rhs) throw()  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *LHS*  
 O primeiro parâmetro a ser comparado. *LHS* pode ser uma referência a um **HString**.  
  
 *rhs*  
 O segundo parâmetro a ser comparado. *rhs* pode ser uma referência a um **HString**.  
  
## <a name="return-value"></a>Valor de retorno  
 **Verdadeiro** se o *lhs* parâmetro é menor do que o *rhs* parâmetro; caso contrário, **false**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HString](../windows/hstring-class.md)