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
ms.openlocfilehash: 719852c4556291747b612d54c44d4bf82caa9188
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62165925"
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

Extrai e retorna encapsulado `VARIANT`, em seguida, limpa esse `_variant_t` objeto sem destruí-lo. Essa função membro remove os `VARIANT` do encapsulamento e define o `VARTYPE` isso `_variant_t` objeto como VT_EMPTY. Cabe a você liberar retornado `VARIANT` chamando o [VariantClear](/windows/desktop/api/oleauto/nf-oleauto-variantclear) função.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _variant_t](../cpp/variant-t-class.md)