---
title: Dependências cumulativas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- dependencies, cumulative
- cumulative dependencies in NMAKE
- dependencies
ms.assetid: fa6dd777-80b8-437d-87a7-aec0ed818a49
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5a66b153a52da06cca14845b9a58fcef0f42676d
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45725706"
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