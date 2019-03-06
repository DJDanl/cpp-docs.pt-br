---
title: Vários destinos
ms.date: 11/04/2016
helpviewer_keywords:
- makefiles, targets
- multiple targets in NMAKE
- targets, multiple in NMAKE
- NMAKE program, targets
ms.assetid: b609a179-0b9f-4b08-9930-998047588ae0
ms.openlocfilehash: 28ac69a6e724b4e7c6fe838e0de3703cbdf0cfaa
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57421422"
---
# <a name="multiple-targets"></a>Vários destinos

NMAKE avalia vários destinos em uma única dependência, como se cada foram especificada em um bloco de descrição separado.

Por exemplo, isso...

```Output
bounce.exe leap.exe : jump.obj
   echo Building...
```

... são avaliadas como este:

```Output
bounce.exe : jump.obj
   echo Building...
leap.exe : jump.obj
   echo Building...
```

## <a name="see-also"></a>Consulte também

[Destinos](../build/targets.md)
