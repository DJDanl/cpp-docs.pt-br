---
title: _variant_t::Detach
ms.date: 11/04/2016
f1_keywords:
- _variant_t::Detach
- _variant_t.Detach
helpviewer_keywords:
- VARIANT object [C++], detatch
- Detach method [C++]
- VARIANT object
ms.assetid: c348ac08-62cf-4657-a16f-974a79c12158
ms.openlocfilehash: 9737db6b77483fa55e1dad90b9464752cd8537a5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187733"
---
# <a name="_variant_tdetach"></a>_variant_t::Detach

**Seção específica da Microsoft**

Desanexa o objeto de `VARIANT` encapsulado deste objeto `_variant_t`.

## <a name="syntax"></a>Sintaxe

```
VARIANT Detach( );
```

## <a name="return-value"></a>Valor retornado

O `VARIANT`encapsulado.

## <a name="remarks"></a>Comentários

Extrai e retorna o `VARIANT`encapsulado e, em seguida, limpa esse objeto `_variant_t` sem destruí-lo. Essa função de membro remove a `VARIANT` do encapsulamento e define a `VARTYPE` desse objeto `_variant_t` como VT_EMPTY. Cabe a você liberar o `VARIANT` retornado chamando a função [VariantClear](/windows/win32/api/oleauto/nf-oleauto-variantclear) .

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
