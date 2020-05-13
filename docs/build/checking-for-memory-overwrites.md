---
title: Verificando substituições de memória
ms.date: 11/04/2016
helpviewer_keywords:
- memory, overwrites
ms.assetid: da7c5d77-a267-415f-a8ab-ee5ce5bfc286
ms.openlocfilehash: 2c59cb96d640df6dcd96b9e0eafbcd325ed475f5
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64342251"
---
# <a name="checking-for-memory-overwrites"></a>Verificando substituições de memória

Se você obtiver uma violação de acesso em uma chamada para uma função de manipulação de heap, é possível que seu programa tenha corrompido o heap. Um sintoma comum dessa situação seria:

```
Access Violation in _searchseg
```

A função [_heapchk](../c-runtime-library/reference/heapchk.md) está disponível em compilações de depuração e versão (somente Windows NT) para verificar a integridade do heap de biblioteca de tempo de execução. Você pode usar `_heapchk` praticamente da mesma forma que a `AfxCheckMemory` função para isolar uma substituição de heap, por exemplo:

```
if(_heapchk()!=_HEAPOK)
   DebugBreak();
```

Se essa função falhar, você precisará isolar em qual ponto o heap foi corrompido.

## <a name="see-also"></a>Confira também

[Corrigindo problemas de compilação da versão](fixing-release-build-problems.md)
