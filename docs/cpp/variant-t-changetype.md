---
title: _variant_t::ChangeType
ms.date: 11/04/2016
f1_keywords:
- _variant_t::ChangeType
- _variant_t.ChangeType
helpviewer_keywords:
- ChangeType method [C++]
- VARIANT object [C++], ChangeType
- VARIANT object
ms.assetid: 829d2eeb-3338-4a88-9dce-0ca145f47aac
ms.openlocfilehash: 319c4fde808932e86021ee59b051261c43ca2edd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50471234"
---
# <a name="varianttchangetype"></a>_variant_t::ChangeType

**Seção específica da Microsoft**

Altera o tipo dos `_variant_t` objeto a ser indicado `VARTYPE`.

## <a name="syntax"></a>Sintaxe

```
void ChangeType(
   VARTYPE vartype,
   const _variant_t* pSrc = NULL
);
```

#### <a name="parameters"></a>Parâmetros

*VarType*<br/>
O `VARTYPE` para este `_variant_t` objeto.

*pSrc*<br/>
Um ponteiro para o objeto `_variant_t` a ser convertido. Se esse valor for NULL, a conversão é feita no lugar.

## <a name="remarks"></a>Comentários

Essa função membro converte um `_variant_t` objeto indicado `VARTYPE`. Se *pSrc* for NULL, a conversão é feita in-loco, caso contrário `_variant_t` objeto é copiado do *pSrc* e, em seguida, convertidos.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _variant_t](../cpp/variant-t-class.md)