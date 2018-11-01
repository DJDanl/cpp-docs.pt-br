---
title: optimize
ms.date: 11/04/2016
f1_keywords:
- vc-pragma.optimize
- optimize_CPP
helpviewer_keywords:
- pragmas, optimize
- optimize pragma
ms.assetid: cb13c1cc-186a-45bc-bee7-95a8de7381cc
ms.openlocfilehash: 65948f2b466bdd40bd753dbba99e2e235c57b0f6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50615859"
---
# <a name="optimize"></a>optimize

Especifica as otimizações a serem executadas em uma base de função por função.

## <a name="syntax"></a>Sintaxe

```
#pragma optimize( "[optimization-list]", {on | off} )
```

## <a name="remarks"></a>Comentários

O **otimizar** pragma deve aparecer fora de uma função e entra em vigor na primeira função definida depois que o pragma é considerado. O *na* e *off* argumentos ativar as opções especificadas no *lista de otimização* ativada ou desativada.

O *lista de otimização* pode ser zero ou mais dos parâmetros mostrados na tabela a seguir.

### <a name="parameters-of-the-optimize-pragma"></a>Parâmetros do pragma de otimização

|Parâmetro(s)|Tipo de otimização|
|--------------------|--------------------------|
|*g*|Habilita as otimizações globais.|
|*s* ou *t*|Especifica sequências curtas ou rápidas de código de máquina.|
|*y*|Gera ponteiros de quadro na pilha de programa.|

Essas são as mesmas letras usadas com o [/O](../build/reference/o-options-optimize-code.md) opções do compilador. Por exemplo, o pragma a seguir é equivalente à opção de compilador `/Os`:

```
#pragma optimize( "ts", on )
```

Usando o **otimizar** pragma com a cadeia de caracteres vazia (**""**) é uma forma especial de política:

Quando você usa o *off* parâmetro, ele desativa as otimizações, *g*, *s*, *t*, e *y*, desativado.

Quando você usa o *na* parâmetro, ele redefine as otimizações que você especificou com o [/O](../build/reference/o-options-optimize-code.md) opção de compilador.

```
#pragma optimize( "", off )
.
.
.
#pragma optimize( "", on )
```

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)