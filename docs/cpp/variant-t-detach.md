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
ms.openlocfilehash: 8426c80af04b2c0906af150ea3e91304335e9f69
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69500556"
---
# <a name="_variant_tdetach"></a>_variant_t::Detach

**Seção específica da Microsoft**

Desanexa o `VARIANT` objeto `_variant_t` encapsulado deste objeto.

## <a name="syntax"></a>Sintaxe

```
VARIANT Detach( );
```

## <a name="return-value"></a>Valor de retorno

O encapsulado `VARIANT`.

## <a name="remarks"></a>Comentários

Extrai e retorna o encapsulado `VARIANT`e limpa esse `_variant_t` objeto sem destruí-lo. Essa função de membro remove `VARIANT` o de encapsulamento e define `VARTYPE` o desse `_variant_t` objeto como VT_EMPTY. Cabe a você liberar o retornado `VARIANT` chamando a função [VariantClear](/windows/win32/api/oleauto/nf-oleauto-variantclear) .

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _variant_t](../cpp/variant-t-class.md)