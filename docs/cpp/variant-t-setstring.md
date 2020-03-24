---
title: _variant_t::SetString
ms.date: 11/04/2016
f1_keywords:
- _variant_t::SetString
helpviewer_keywords:
- SetString method [C++]
ms.assetid: 816b08e5-6830-46ca-b3d7-7689308b3be3
ms.openlocfilehash: 0cd300a09c29668c496d93109d1bc862947e948c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187551"
---
# <a name="_variant_tsetstring"></a>_variant_t::SetString

**Seção específica da Microsoft**

Atribui uma cadeia de caracteres a este objeto `_variant_t`.

## <a name="syntax"></a>Sintaxe

```
void SetString(const char* pSrc);
```

#### <a name="parameters"></a>parâmetros

*pSrc*<br/>
Ponteiro para a cadeia de caracteres.

## <a name="remarks"></a>Comentários

Converte uma cadeia de caracteres ANSI em uma cadeia de caracteres Unicode `BSTR` e a atribui a este objeto `_variant_t`.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
