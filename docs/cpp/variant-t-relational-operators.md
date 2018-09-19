---
title: Operadores relacionais variant_t | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _variant_t::operator==
- _variant_t::operator!=
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 95cb1ac663607f26c4f168c2e98910f5b41963c0
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46040135"
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