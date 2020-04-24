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
ms.openlocfilehash: c2283158856a6781ab2e12c51f4e2ad0e4f1d531
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81750721"
---
# <a name="_variant_tchangetype"></a>_variant_t::ChangeType

**Específico da Microsoft**

Altera o tipo `_variant_t` do objeto `VARTYPE`para o indicado .

## <a name="syntax"></a>Sintaxe

```cpp
void ChangeType(
   VARTYPE vartype,
   const _variant_t* pSrc = NULL
);
```

#### <a name="parameters"></a>Parâmetros

*Vartype*<br/>
O `VARTYPE` para `_variant_t` este objeto.

*Psrc*<br/>
Um ponteiro para o objeto `_variant_t` a ser convertido. Se esse valor for NULO, a conversão será feita no lugar.

## <a name="remarks"></a>Comentários

Esta função de `_variant_t` membro converte `VARTYPE`um objeto no indicado . Se *o pSrc* for NULL, a conversão `_variant_t` será feita no lugar, caso contrário este objeto será copiado do *pSrc* e convertido.

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
