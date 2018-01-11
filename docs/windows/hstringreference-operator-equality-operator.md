---
title: 'Hstringreference:: Operator = = operador | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::HStringReference::operator==
dev_langs: C++
ms.assetid: cad3d52d-cd67-4194-a270-5239b1121a09
caps.latest.revision: "2"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 4e9c9c9edcd5c53ee3e26f89ed467140d1509e13
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
  
#### <a name="parameters"></a>Parâmetros  
 `lhs`  
 O primeiro parâmetro para comparar. `lhs`pode ser um objeto HStringReference ou um identificador HSTRING.  
  
 `rhs`  
 O segundo parâmetro para comparar.  `rhs`pode ser um objeto HStringReference ou um identificador HSTRING.  
  
## <a name="return-value"></a>Valor de retorno  
 `true` se os parâmetros `lhs` e `rhs` forem iguais; caso contrário, `false`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HStringReference](../windows/hstringreference-class.md)