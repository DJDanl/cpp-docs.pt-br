---
title: 'Hstringreference:: Operator! = operador | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HStringReference::operator!=
dev_langs:
- C++
ms.assetid: 01ab6691-1fc7-4feb-85f0-fe795593a160
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 996ead81a72fb3cc58544576059a8347972e2a6b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46429034"
---
# <a name="hstringreferenceoperator-operator"></a>Operador HStringReference::Operator!=

Indica se os dois parâmetros não são iguais.

## <a name="syntax"></a>Sintaxe

```cpp
inline bool operator==(
               const HStringReference& lhs,
               const HSTRING& rhs) throw()

inline bool operator!=(
               const HStringReference& lhs,
               const HStringReference& rhs) throw()

inline bool operator!=(
               const HSTRING& lhs,
               const HStringReference& rhs) throw()

inline bool operator!=(
               const HStringReference& lhs,
               const HSTRING& rhs) throw()  
```

### <a name="parameters"></a>Parâmetros

*LHS*<br/>
O primeiro parâmetro a ser comparado. *LHS* pode ser uma **HStringReference** objeto ou um identificador de HSTRING.

*rhs*<br/>
O segundo parâmetro a ser comparado.  *rhs* pode ser uma **HStringReference** objeto ou um identificador de HSTRING.

## <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o *lhs* e *rhs* parâmetros não forem iguais; caso contrário, **false**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe HStringReference](../windows/hstringreference-class.md)