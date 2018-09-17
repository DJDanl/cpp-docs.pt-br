---
title: Verificar para substituições de memória | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- memory, overwrites
ms.assetid: da7c5d77-a267-415f-a8ab-ee5ce5bfc286
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 246f625e899016080662f27a5901962c1c62f1a8
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45718634"
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