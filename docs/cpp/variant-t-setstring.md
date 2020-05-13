---
title: _variant_t::SetString
ms.date: 11/04/2016
f1_keywords:
- _variant_t::SetString
helpviewer_keywords:
- SetString method [C++]
ms.assetid: 816b08e5-6830-46ca-b3d7-7689308b3be3
ms.openlocfilehash: 60ad1c1bd95eb35f2a4f2800f79d0326c68a1176
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81745853"
---
# <a name="_variant_tsetstring"></a>_variant_t::SetString

**Específico da Microsoft**

Atribui uma cadeia de caracteres a este objeto `_variant_t`.

## <a name="syntax"></a>Sintaxe

```cpp
void SetString(const char* pSrc);
```

#### <a name="parameters"></a>Parâmetros

*Psrc*<br/>
Ponteiro para a cadeia de caracteres.

## <a name="remarks"></a>Comentários

Converte uma cadeia de caracteres ANSI em uma cadeia de caracteres Unicode `BSTR` e a atribui a este objeto `_variant_t`.

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
