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
ms.openlocfilehash: b0692c9befaa6b7e787ada624dcbb56b074c9f9d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80160457"
---
# <a name="_variant_tchangetype"></a>_variant_t::ChangeType

**Seção específica da Microsoft**

Altera o tipo do objeto `_variant_t` para o `VARTYPE`indicado.

## <a name="syntax"></a>Sintaxe

```
void ChangeType(
   VARTYPE vartype,
   const _variant_t* pSrc = NULL
);
```

#### <a name="parameters"></a>parâmetros

*VarType*<br/>
O `VARTYPE` para este objeto de `_variant_t`.

*pSrc*<br/>
Um ponteiro para o objeto `_variant_t` a ser convertido. Se esse valor for NULL, a conversão será feita no local.

## <a name="remarks"></a>Comentários

Essa função de membro converte um objeto `_variant_t` no `VARTYPE`indicado. Se *pSrc* for NULL, a conversão será feita em vigor, caso contrário, esse objeto de `_variant_t` será copiado de *pSrc* e convertido.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
