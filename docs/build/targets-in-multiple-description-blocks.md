---
title: Destinos em vários blocos de descrição
ms.date: 11/04/2016
helpviewer_keywords:
- description blocks
- blocks, multiple description
- multiple description blocks
ms.assetid: 8618dcd9-c11d-4562-91a7-0c904ed438a8
ms.openlocfilehash: df5ebba67b3fd041cbf28c90ec25f5a415c0669d
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57414038"
---
# <a name="targets-in-multiple-description-blocks"></a>Destinos em vários blocos de descrição

Para atualizar um destino em mais de um bloco de descrição usando comandos diferentes, especifique dois pontos consecutivos (:) entre os destinos e seus dependentes.

```
target.lib :: one.asm two.asm three.asm
    ml one.asm two.asm three.asm
    lib target one.obj two.obj three.obj
target.lib :: four.c five.c
    cl /c four.c five.c
    lib target four.obj five.obj
```

## <a name="see-also"></a>Consulte também

[Destinos](../build/targets.md)
