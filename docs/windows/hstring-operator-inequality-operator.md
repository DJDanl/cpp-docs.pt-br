---
title: 'Hstring:: Operator! = operador | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString::operator!=
dev_langs:
- C++
ms.assetid: dcdd2aca-e7d6-4bf1-b2de-03efbb430a93
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 74fc15d10818d14467b866ec37c9e353348ce882
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33877025"
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
 O primeiro parâmetro para comparar. `lhs` pode ser um objeto HString ou HStringReference ou um identificador HSTRING.  
  
 `rhs`  
 O segundo parâmetro para comparar.`rhs` pode ser um objeto HString ou HStringReference ou um identificador HSTRING.  
  
## <a name="return-value"></a>Valor de retorno  
 `true` se os parâmetros `lhs` e `rhs` não forem iguais; caso contrário, `false`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HString](../windows/hstring-class.md)