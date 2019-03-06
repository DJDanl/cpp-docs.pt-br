---
title: Efeitos colaterais da dependência
ms.date: 11/04/2016
helpviewer_keywords:
- dependencies, side effects
- NMAKE program, dependents
ms.assetid: d4e8db25-fdc0-4d73-81ec-1538f2e1b3e8
ms.openlocfilehash: 1479fac4defa45545ffd06ab30fd53ae0c2506af
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57422631"
---
# <a name="dependency-side-effects"></a>Efeitos colaterais da dependência

Se um destino for especificado com dois-pontos (:) em duas linhas de dependência em locais diferentes, e se os comandos aparecem depois de apenas uma das linhas, NMAKE interpreta as dependências, como se adjacentes ou combinados. Ele não invoca uma regra de inferência de tipos para a dependência que não tem nenhum comando, mas em vez disso, presume que as dependências pertencem ao bloco de uma descrição e executa os comandos especificados com a dependência de outra. Por exemplo, esse conjunto de regras:

```Output
bounce.exe : jump.obj
   echo Building bounce.exe...

bounce.exe : up.obj
```

é avaliado como este:

```Output
bounce.exe : jump.obj up.obj
   echo Building bounce.exe...
```

Esse efeito não ocorrerá se um dois-pontos duplos (`::`) é usado. Por exemplo, esse conjunto de regras:

```Output
bounce.exe :: jump.obj
   echo Building bounce.exe...

bounce.exe :: up.obj
```

é avaliado como este:

```Output
bounce.exe : jump.obj
   echo Building bounce.exe...

bounce.exe : up.obj
# invokes an inference rule
```

## <a name="see-also"></a>Consulte também

[Destinos](../build/targets.md)
