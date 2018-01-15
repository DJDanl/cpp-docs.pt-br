---
title: 'Hstring:: Operator! = operador | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::HString::operator!=
dev_langs: C++
ms.assetid: dcdd2aca-e7d6-4bf1-b2de-03efbb430a93
caps.latest.revision: "2"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5aab0784b2a099a104fee696148fb9d7ec0c5ac9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hstringoperator-operator"></a>Operador HString::Operator!=
Indica se os dois parâmetros não são iguais.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
inline bool operator!=( const HString& lhs,   
                        const HString& rhs) throw()  
  
inline bool operator!=( const HStringReference& lhs,   
                        const HString& rhs) throw()  
  
inline bool operator!=( const HString& lhs,   
                        const HStringReference& rhs) throw()  
  
inline bool operator!=( const HSTRING& lhs,   
                        const HString& rhs) throw()  
  
inline bool operator!=( const HString& lhs,   
                        const HSTRING& rhs) throw()  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `lhs`  
 O primeiro parâmetro para comparar. `lhs`pode ser um objeto HString ou HStringReference ou um identificador HSTRING.  
  
 `rhs`  
 O segundo parâmetro para comparar.`rhs` pode ser um objeto HString ou HStringReference ou um identificador HSTRING.  
  
## <a name="return-value"></a>Valor de retorno  
 `true` se os parâmetros `lhs` e `rhs` não forem iguais; caso contrário, `false`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HString](../windows/hstring-class.md)