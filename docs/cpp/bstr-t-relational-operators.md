---
title: Operadores relacionais _bstr_t
ms.date: 05/07/2019
f1_keywords:
- _bstr_t::operator>
- _bstr_t::operator==
- _bstr_t::operator>=
- _bstr_t::operator!=
- _bstr_t::operator<
- _bstr_t::operator<=
- _bstr_t::operator!
helpviewer_keywords:
- _bstr_t [C++]
ms.assetid: e153da72-37c3-4d8a-b8eb-730d65da64dd
ms.openlocfilehash: 8fc163255a5ab342938f56f8a22af3984a48e56a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216616"
---
# <a name="_bstr_t-relational-operators"></a>Operadores relacionais _bstr_t

**Específico da Microsoft**

Compara dois objetos `_bstr_t`.

## <a name="syntax"></a>Sintaxe

```
bool operator!( ) const throw( );
bool operator==(const _bstr_t& str) const throw( );
bool operator!=(const _bstr_t& str) const throw( );
bool operator<(const _bstr_t& str) const throw( );
bool operator>(const _bstr_t& str) const throw( );
bool operator<=(const _bstr_t& str) const throw( );
bool operator>=(const _bstr_t& str) const throw( );
```

## <a name="remarks"></a>Comentários

Esses operadores comparam dois objetos `_bstr_t` lexicograficamente. Os operadores retornam **`true`** se as comparações retêm; caso contrário, retornam **`false`** .

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _bstr_t](../cpp/bstr-t-class.md)
