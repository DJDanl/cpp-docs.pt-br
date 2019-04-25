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
ms.openlocfilehash: 510267c7ab00fe22a93dc01342def5fc262ddb04
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62166212"
---
# <a name="varianttattach"></a>_variant_t::Attach

**Seção específica da Microsoft**

Anexa uma `VARIANT` do objeto para o **variant_t** objeto.

## <a name="syntax"></a>Sintaxe

```
void Attach(VARIANT& varSrc);
```

#### <a name="parameters"></a>Parâmetros

*varSrc*<br/>
Um `VARIANT` o objeto a ser anexado a este **variant_t** objeto.

## <a name="remarks"></a>Comentários

Se apropria do `VARIANT` , encapsulando-lo. Essa função de membro libera qualquer encapsulado existente `VARIANT`, em seguida, copia fornecido `VARIANT`e define seu `VARTYPE` como VT_EMPTY para garantir que seus recursos só podem ser liberados pelo **variant_t** destruidor.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _variant_t](../cpp/variant-t-class.md)