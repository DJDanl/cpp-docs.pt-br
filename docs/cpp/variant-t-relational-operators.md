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
ms.openlocfilehash: e0d7ea1a0bcaf8329cff0cdfb0c01154f3c5a73b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80187564"
---
# <a name="_variant_t-relational-operators"></a>Operadores relacionais _variant_t

**Seção específica da Microsoft**

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

*varSrc*<br/>
Um `VARIANT` a ser comparado com o objeto `_variant_t`.

*pSrc*<br/>
Ponteiro para o `VARIANT` a ser comparado com o objeto `_variant_t`.

## <a name="return-value"></a>Valor retornado

Retorna **true** se a comparação for mantida; caso contrário, **false** .

## <a name="remarks"></a>Comentários

Compara um objeto `_variant_t` com um `VARIANT`, testando a igualdade ou desigualdade.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _variant_t](../cpp/variant-t-class.md)
