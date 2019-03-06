---
title: Usando o build de depuração para verificar a substituição de memória
ms.date: 11/04/2016
helpviewer_keywords:
- memory, overwrites
ms.assetid: 1345eb4d-24ba-4595-b1cc-2da66986311e
ms.openlocfilehash: 75f4d5aeddc617173aa33d96f8ff934fb8c1b320
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57413830"
---
# <a name="using-the-debug-build-to-check-for-memory-overwrite"></a>Usando o build de depuração para verificar a substituição de memória

Para usar o build de depuração para verificar a substituição de memória, você primeiro deve recompilar o projeto para depuração. Em seguida, vá para o início do seu aplicativo `InitInstance` de função e adicione a seguinte linha:

```
afxMemDF |= checkAlwaysMemDF;
```

O alocador de memória de depuração coloca bytes guard em torno de todas as alocações de memória. No entanto, eles se proteger bytes não fizer nada, a menos que você verifique se eles foram alterados (que poderia indicar uma substituição de memória). Caso contrário, isso simplesmente fornece um buffer que pode, na verdade, permitem que você se contentar com uma substituição de memória.

Ativando o `checkAlwaysMemDF`, você forçará o MFC para fazer uma chamada para o `AfxCheckMemory` funcionar sempre que uma chamada para **novo** ou **excluir** é feita. Se uma substituição de memória foi detectada, ele irá gerar uma mensagem de rastreamento que é semelhante ao seguinte:

```
Damage Occurred! Block=0x5533
```

Se você vir uma dessas mensagens, você precisa percorrer seu código para determinar onde ocorreu o dano. Para isolar mais precisamente onde ocorreu a substituição de memória, você pode fazer chamadas explícitas para `AfxCheckMemory` por conta própria. Por exemplo:

```
ASSERT(AfxCheckMemory());
    DoABunchOfStuff();
    ASSERT(AfxCheckMemory());
```

Se a primeira declaração for bem-sucedida e um segundo falha, isso significa que a substituição de memória deve ter ocorreu na função entre as duas chamadas.

Dependendo da natureza do seu aplicativo, você pode descobrir que `afxMemDF` faz com que seu programa seja executado muito lentamente para até mesmo testar. O `afxMemDF` faz com que o variável `AfxCheckMemory` para ser chamado para cada chamada para novos e excluir. Nesse caso, você deve dispersão suas próprias chamadas para `AfxCheckMemory`(), conforme mostrado acima e tentar isolar a memória substituir dessa forma.

## <a name="see-also"></a>Consulte também

[Corrigindo problemas do build de versão](../../build/reference/fixing-release-build-problems.md)
