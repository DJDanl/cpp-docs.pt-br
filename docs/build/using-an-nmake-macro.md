---
title: Usando uma macro NMAKE
ms.date: 11/04/2016
helpviewer_keywords:
- macros, NMAKE
- NMAKE macros, using
ms.assetid: 95c87fbc-76e6-48c0-8536-9bfe179f328e
ms.openlocfilehash: 9d8ff76e1e730b65db363749797ef9ae2062adab
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50645075"
---
# <a name="using-an-nmake-macro"></a>Usando uma macro NMAKE

Para usar uma macro, colocar seu nome entre parênteses, precedido por um sinal de cifrão ($), da seguinte maneira.

## <a name="syntax"></a>Sintaxe

```
$(macroname)
```

## <a name="remarks"></a>Comentários

Não são permitidos espaços. Os parênteses são opcionais se *macroname* é um caractere único. A cadeia de caracteres de definição substitui $(*macroname*); uma macro é substituída por uma cadeia de caracteres nula.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

[Substituição de macro](../build/macro-substitution.md)

## <a name="see-also"></a>Consulte também

[Macros e NMAKE](../build/macros-and-nmake.md)