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
ms.openlocfilehash: b5446fb6fa0722018e4ab7734019e677b6acec7c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46435201"
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

### <a name="parameters"></a>Parâmetros

*LHS*<br/>
O primeiro parâmetro a ser comparado. *LHS* pode ser uma **HString** ou `HStringReference` objeto ou um identificador de HSTRING.

*rhs*<br/>
O segundo parâmetro a ser comparado. *rhs* pode ser um **HString** ou `HStringReference` objeto ou um identificador de HSTRING.

## <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o *lhs* e *rhs* parâmetros não forem iguais; caso contrário, **false**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe HString](../windows/hstring-class.md)