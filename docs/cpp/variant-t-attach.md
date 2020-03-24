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
ms.openlocfilehash: 3792ed4d0fcd86c4a4e846771c450413fda130b5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187759"
---
# <a name="_variant_tattach"></a>_variant_t::Attach

**Seção específica da Microsoft**

Anexa um objeto `VARIANT` ao objeto **_variant_t** .

## <a name="syntax"></a>Sintaxe

```
void Attach(VARIANT& varSrc);
```

#### <a name="parameters"></a>parâmetros

*varSrc*<br/>
Um objeto `VARIANT` a ser anexado a este objeto **_variant_t** .

## <a name="remarks"></a>Comentários

Apropria-se da `VARIANT` encapsulando-a. Essa função de membro libera qualquer `VARIANT`encapsulada existente e, em seguida, copia o `VARIANT`fornecido e define seu `VARTYPE` como VT_EMPTY para garantir que seus recursos só possam ser liberados pelo destruidor **_variant_t** .

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
