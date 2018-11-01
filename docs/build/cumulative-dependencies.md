---
title: Dependências cumulativas
ms.date: 11/04/2016
helpviewer_keywords:
- dependencies, cumulative
- cumulative dependencies in NMAKE
- dependencies
ms.assetid: fa6dd777-80b8-437d-87a7-aec0ed818a49
ms.openlocfilehash: c31740b830993c91568aea6d167fd3113b04fc57
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50460275"
---
# <a name="cumulative-dependencies"></a>Dependências cumulativas

As dependências são cumulativas em um bloco de descrição, se um destino é repetido.

Por exemplo, o conjunto de regras,

```Output
bounce.exe : jump.obj
bounce.exe : up.obj
   echo Building bounce.exe...
```

é avaliado como este:

```Output
bounce.exe : jump.obj up.obj
   echo Building bounce.exe...
```

Vários destinos em várias linhas de dependência em um bloco único descrição são avaliados como se cada foram especificadas em um bloco de descrição separado, mas os destinos que não estão na última linha de dependência não usam o bloco de comandos. NMAKE tenta usar uma regra de inferência de tipos para esses destinos.

Por exemplo, o conjunto de regras,

```Output
leap.exe bounce.exe : jump.obj
bounce.exe climb.exe : up.obj
   echo Building bounce.exe...
```

é avaliado como este:

```Output

leap.exe : jump.obj
# invokes an inference rule
bounce.exe : jump.obj up.obj
   echo Building bounce.exe...
climb.exe : up.obj
   echo Building bounce.exe...
```

## <a name="see-also"></a>Consulte também

[Destinos](../build/targets.md)