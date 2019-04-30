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
ms.openlocfilehash: e0d26247868440f47c73422510ac0e998f8e8dee
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62403289"
---
# <a name="variantt-relational-operators"></a>Operadores relacionais _variant_t

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

#### <a name="parameters"></a>Parâmetros

*varSrc*<br/>
Um `VARIANT` a ser comparado com o `_variant_t` objeto.

*pSrc*<br/>
Ponteiro para o `VARIANT` a ser comparado com o `_variant_t` objeto.

## <a name="return-value"></a>Valor de retorno

Retorna **verdadeira** se mantém em comparação, **falso** se não for.

## <a name="remarks"></a>Comentários

Compara uma `_variant_t` do objeto com um `VARIANT`, testes de igualdade ou desigualdade.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _variant_t](../cpp/variant-t-class.md)