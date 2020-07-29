---
title: Operadores relacionais _variant_t
ms.date: 11/04/2016
f1_keywords:
- _variant_t::operator==
- _variant_t::operator!=
helpviewer_keywords:
- '!= operator'
- relational operators [C++], _variant_t class
- operator!= [C++], variant
- operator!= [C++], relational operators
- operator != [C++], variant
- operator == [C++], variant
- operator== [C++], variant
- operator != [C++], relational operators
- == operator [C++], with specific Visual C++ objects
ms.assetid: 141bacb8-41a2-44dd-b3c0-4ad1f884f4ea
ms.openlocfilehash: 6e0296a2bf4ce97e41fdf6208c3dd1c6b91215dc
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226927"
---
# <a name="_variant_t-relational-operators"></a>Operadores relacionais _variant_t

**Específico da Microsoft**

Compare dois objetos `_variant_t` em termos de igualdade ou desigualdade.

## <a name="syntax"></a>Sintaxe

```
bool operator==(
   const VARIANT& varSrc) const;
bool operator==(
   const VARIANT* pSrc) const;
bool operator!=(
   const VARIANT& varSrc) const;
bool operator!=(
   const VARIANT* pSrc) const;
```

#### <a name="parameters"></a>parâmetros

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
Um `VARIANT` a ser comparado com o `_variant_t` objeto.

*pSrc*<br/>
Ponteiro para o `VARIANT` a ser comparado com o `_variant_t` objeto.

## <a name="return-value"></a>Valor retornado

Retorna **`true`** se a comparação se aplica, **`false`** caso contrário.

## <a name="remarks"></a>Comentários

Compara um `_variant_t` objeto com um `VARIANT` , testando a igualdade ou desigualdade.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
