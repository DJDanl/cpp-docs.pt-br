---
title: 'Operador hstring:: Operator = = | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString::operator==
dev_langs:
- C++
ms.assetid: 77ff4c1a-e62a-4256-bf9d-0f017137c630
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c21e9f79673cc888f8661803a8cc4bb9053870c4
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39604558"
---
# <a name="hstringoperator-operator"></a>Operador HString::Operator==
Indica se os dois parâmetros são iguais.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
inline bool operator==(  
               const HString& lhs,   
               const HString& rhs) throw()  
  
inline bool operator==(  
                const HString& lhs,   
                const HStringReference& rhs) throw()  
  
inline bool operator==(  
                const HStringReference& lhs,   
                const HString& rhs) throw()  
  
inline bool operator==(  
                 const HSTRING& lhs,   
                 const HString& rhs) throw()  
  
inline bool operator==(  
                 const HString& lhs,   
                 const HSTRING& rhs) throw()  
```  
  
### <a name="parameters"></a>Parâmetros  
 *LHS*  
 O primeiro parâmetro a ser comparado. *LHS* pode ser uma **HString** ou `HStringReference` objeto ou um identificador de HSTRING.  
  
 *rhs*  
 O segundo parâmetro a ser comparado. *rhs* pode ser um **HString** ou `HStringReference` objeto ou um identificador de HSTRING.  
  
## <a name="return-value"></a>Valor de retorno  
 **Verdadeiro** se o *lhs* e *rhs* parâmetros forem iguais; caso contrário, **false**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HString](../windows/hstring-class.md)