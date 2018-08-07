---
title: 'Operador hstringreference:: Operator = = | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::operator==
dev_langs:
- C++
ms.assetid: cad3d52d-cd67-4194-a270-5239b1121a09
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7620cee350ab69f55737e6336b275218a70b6891
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39607707"
---
# <a name="hstringreferenceoperator-operator"></a>Operador HStringReference::Operator==
Indica se os dois parâmetros são iguais.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
inline bool operator==(  
               const HStringReference& lhs,   
               const HStringReference& rhs) throw()  
  
inline bool operator==(  
               const HSTRING& lhs,   
               const HStringReference& rhs) throw()  
  
inline bool operator==(  
               const HStringReference& lhs,   
               const HSTRING& rhs) throw()  
```  
  
### <a name="parameters"></a>Parâmetros  
 *LHS*  
 O primeiro parâmetro a ser comparado. *LHS* pode ser uma **HStringReference** objeto ou um identificador de HSTRING.  
  
 *rhs*  
 O segundo parâmetro a ser comparado.  *rhs* pode ser uma **HStringReference** objeto ou um identificador de HSTRING.  
  
## <a name="return-value"></a>Valor de retorno  
 **Verdadeiro** se o *lhs* e *rhs* parâmetros forem iguais; caso contrário, **false**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HStringReference](../windows/hstringreference-class.md)