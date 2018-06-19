---
title: 'Hstringreference:: Operator&lt; operador | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::operator<
dev_langs:
- C++
ms.assetid: 55aa48e8-7c96-4123-9ebe-42b4cd8b9377
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5b486157fb42883af724f2356e7f85701e405035
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33877287"
---
# <a name="hstringreferenceoperatorlt-operator"></a>Hstringreference:: Operator&lt; operador
Indica se o primeiro parâmetro é menor do que o segundo parâmetro.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
inline bool operator<(  
    const HStringReference& lhs,   
    const HStringReference& rhs) throw()  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `lhs`  
 O primeiro parâmetro para comparar. `lhs` pode ser uma referência a um HStringReference.  
  
 `rhs`  
 O segundo parâmetro para comparar.  `rhs` pode ser uma referência a um HStringReference.  
  
## <a name="return-value"></a>Valor de retorno  
 `true` Se o `lhs` parâmetro é menor do que o `rhs` parâmetro; caso contrário, `false`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HStringReference](../windows/hstringreference-class.md)