---
title: Erro não fatal A2031 (ML)
ms.date: 12/17/2019
ms.custom: error-reference
f1_keywords:
- A2031
helpviewer_keywords:
- A2031
ms.assetid: d5b11f58-4a00-42be-9062-8fa8728e6306
ms.openlocfilehash: 4764f7296e28e2128fc4fc80e64f39ceb2a8ed8c
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75317065"
---
# <a name="ml-nonfatal-error-a2031"></a>Erro não fatal A2031 (ML)

**deve ser um índice ou um registro base**

Foi feita uma tentativa de usar um registro que não era um registro de base ou de índice em uma expressão de memória.

Por exemplo, as expressões a seguir causam esse erro:

```asm
[ax]
[bl]
```

## <a name="see-also"></a>Veja também

[Mensagens de erro de ML](ml-error-messages.md)
