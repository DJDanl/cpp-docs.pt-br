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
ms.openlocfilehash: 1bdc6d54a6c9b60036d7434edec960715db304e2
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40017676"
---
# <a name="hstringoperatorlt-operator"></a>Operador hstring::&lt; operador
Indica se o primeiro parâmetro é menor do que o segundo parâmetro.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
inline bool operator<(  
    const HString& lhs,   
    const HString& rhs) throw()  
```  
  
### <a name="parameters"></a>Parâmetros  
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