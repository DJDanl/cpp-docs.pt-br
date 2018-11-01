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
ms.openlocfilehash: 4b19e3c1615912550cdf1eb6a2b0b3f906ee4af9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50522315"
---
# <a name="varianttdetach"></a>_variant_t::Detach

**Seção específica da Microsoft**

Desanexa encapsulado `VARIANT` objeto deste `_variant_t` objeto.

## <a name="syntax"></a>Sintaxe

```
VARIANT Detach( );
```

## <a name="return-value"></a>Valor de retorno

Encapsulado `VARIANT`.

## <a name="remarks"></a>Comentários

Extrai e retorna encapsulado `VARIANT`, em seguida, limpa esse `_variant_t` objeto sem destruí-lo. Essa função membro remove os `VARIANT` do encapsulamento e define o `VARTYPE` isso `_variant_t` objeto como VT_EMPTY. Cabe a você liberar retornado `VARIANT` chamando o [VariantClear](/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) função.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _variant_t](../cpp/variant-t-class.md)