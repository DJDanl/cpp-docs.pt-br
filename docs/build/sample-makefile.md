---
title: Makefile de exemplo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 8343ce71-5556-4ae0-8d1e-7efd82673070
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b66d7d341f734608a7e2298b00a1078549c5de1c
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45705218"
---
# <a name="sample-makefile"></a>Makefile de exemplo

Este tópico contém um makefile de exemplo.

## <a name="sample"></a>Amostra

### <a name="code"></a>Código

```
# Sample makefile

!include <win32.mak>

all: simple.exe challeng.exe

.c.obj:
  $(cc) $(cdebug) $(cflags) $(cvars) $*.c

simple.exe: simple.obj
  $(link) $(ldebug) $(conflags) -out:simple.exe simple.obj $(conlibs) lsapi32.lib

challeng.exe: challeng.obj md4c.obj
  $(link) $(ldebug) $(conflags) -out:challeng.exe $** $(conlibs) lsapi32.lib
```

## <a name="see-also"></a>Consulte também

[Conteúdo de um makefile](../build/contents-of-a-makefile.md)