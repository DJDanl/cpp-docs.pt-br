---
title: _variant_t::Attach
ms.date: 11/04/2016
f1_keywords:
- _variant_t::Attach
- _variant_t.Attach
helpviewer_keywords:
- Attach method [C++]
- VARIANT object [C++], attach
- VARIANT object
ms.assetid: 2f02bd08-2306-4477-aa88-d2a5dee2b859
ms.openlocfilehash: d0822dfc730cbbb64f8364e6fa8fe8bc7207f9f9
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81750733"
---
# <a name="_variant_tattach"></a>_variant_t::Attach

**Específico da Microsoft**

Anexa um `VARIANT` objeto ao objeto **_variant_t.**

## <a name="syntax"></a>Sintaxe

```cpp
void Attach(VARIANT& varSrc);
```

#### <a name="parameters"></a>Parâmetros

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
Um `VARIANT` objeto a ser anexado a este **objeto _variant_t.**

## <a name="remarks"></a>Comentários

Toma posse `VARIANT` do encapsulando-o. Esta função membro libera qualquer `VARIANT`encapsulamento existente, `VARIANT`depois copia `VARTYPE` o fornecido e define seu VT_EMPTY para garantir que seus recursos só possam ser liberados pelo **destruidor de _variant_t.**

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
