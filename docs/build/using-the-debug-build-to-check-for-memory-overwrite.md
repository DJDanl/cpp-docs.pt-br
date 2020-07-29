---
title: Usando o build de depuração para verificar a substituição de memória
ms.date: 11/04/2016
helpviewer_keywords:
- memory, overwrites
ms.assetid: 1345eb4d-24ba-4595-b1cc-2da66986311e
ms.openlocfilehash: 152f72749d2ebdacd46dd3e4db671bc5705d4b6a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213743"
---
# <a name="using-the-debug-build-to-check-for-memory-overwrite"></a>Usando o build de depuração para verificar a substituição de memória

Para usar a compilação de depuração para verificar a substituição de memória, você deve primeiro recompilar o projeto para depuração. Em seguida, vá até o início da função do seu aplicativo `InitInstance` e adicione a seguinte linha:

```
afxMemDF |= checkAlwaysMemDF;
```

O alocador de memória de depuração coloca os bytes de proteção em todas as alocações de memória. No entanto, esses bytes de proteção não fazem nada a menos que você verifique se eles foram alterados (o que indicaria uma substituição de memória). Caso contrário, isso apenas fornece um buffer que pode, de fato, permitir que você saia com uma substituição de memória.

Ao ativar o `checkAlwaysMemDF` , você forçará o MFC a fazer uma chamada para a `AfxCheckMemory` função sempre que uma chamada para **`new`** ou **`delete`** for feita. Se uma substituição de memória foi detectada, ela irá gerar uma mensagem de rastreamento semelhante à seguinte:

```
Damage Occurred! Block=0x5533
```

Se você vir uma dessas mensagens, precisará percorrer seu código para determinar onde o dano ocorreu. Para isolar mais precisamente o local em que a substituição de memória ocorreu, você pode fazer chamadas explícitas a `AfxCheckMemory` si mesmo. Por exemplo:

```
ASSERT(AfxCheckMemory());
    DoABunchOfStuff();
    ASSERT(AfxCheckMemory());
```

Se a primeira declaração for bem-sucedida e a segunda falhar, isso significa que a substituição da memória deve ter ocorrido na função entre as duas chamadas.

Dependendo da natureza do seu aplicativo, você pode achar que `afxMemDF` o programa será executado muito lentamente até mesmo para teste. A `afxMemDF` variável faz com que `AfxCheckMemory` seja chamada para cada chamada para New e Delete. Nesse caso, você deve dispersão de suas próprias chamadas para `AfxCheckMemory` () conforme mostrado acima e tentar isolar a substituição de memória dessa forma.

## <a name="see-also"></a>Confira também

[Corrigindo problemas de compilação da versão](fixing-release-build-problems.md)
