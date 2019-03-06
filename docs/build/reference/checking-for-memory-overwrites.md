---
title: Verificando substituições de memória
ms.date: 11/04/2016
helpviewer_keywords:
- memory, overwrites
ms.assetid: da7c5d77-a267-415f-a8ab-ee5ce5bfc286
ms.openlocfilehash: b37bd68519aea1194b601e89fefd0f14d428630a
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57422189"
---
# <a name="checking-for-memory-overwrites"></a>Verificando substituições de memória

Se você receber uma violação de acesso em uma chamada para uma função de manipulação de heap, é possível que seu programa corrompeu o heap. Um sintoma comum dessa situação seria:

```
Access Violation in _searchseg
```

O [heapchk](../../c-runtime-library/reference/heapchk.md) função está disponível em ambos os depuração e libere compilações (somente no Windows NT) para verificar a integridade do heap de biblioteca de tempo de execução. Você pode usar `_heapchk` da mesma maneira como o `AfxCheckMemory` função, isolar uma substituição de heap, por exemplo:

```
if(_heapchk()!=_HEAPOK)
   DebugBreak();
```

Se essa função nunca falhar, você precisa isolar no ponto em que o heap foi corrompido.

## <a name="see-also"></a>Consulte também

[Corrigindo problemas do build de versão](../../build/reference/fixing-release-build-problems.md)
