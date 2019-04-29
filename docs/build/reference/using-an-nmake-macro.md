---
title: Usando uma macro NMAKE
ms.date: 11/04/2016
helpviewer_keywords:
- macros, NMAKE
- NMAKE macros, using
ms.assetid: 95c87fbc-76e6-48c0-8536-9bfe179f328e
ms.openlocfilehash: fb3b154ba8b30bbfc9a6c7c6b37720e5c60d6327
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62317244"
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

[Substituição de macro](macro-substitution.md)

## <a name="see-also"></a>Consulte também

[Macros e NMAKE](macros-and-nmake.md)
