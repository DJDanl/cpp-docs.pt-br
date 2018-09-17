---
title: Usando uma Macro NMAKE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- macros, NMAKE
- NMAKE macros, using
ms.assetid: 95c87fbc-76e6-48c0-8536-9bfe179f328e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e0b68a5f3128b5d3780895f8080411819ed9b538
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45712570"
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