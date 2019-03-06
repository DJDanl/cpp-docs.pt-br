---
title: Usando uma macro NMAKE
ms.date: 11/04/2016
helpviewer_keywords:
- macros, NMAKE
- NMAKE macros, using
ms.assetid: 95c87fbc-76e6-48c0-8536-9bfe179f328e
ms.openlocfilehash: a5f0fb9b13c5d5647b8f4ee382951df6282e8d68
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57415637"
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
