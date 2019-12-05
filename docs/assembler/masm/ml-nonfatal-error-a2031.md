---
title: Erro não fatal A2031 (ML)
ms.date: 08/30/2018
ms.custom: error-reference
f1_keywords:
- A2031
helpviewer_keywords:
- A2031
ms.assetid: d5b11f58-4a00-42be-9062-8fa8728e6306
ms.openlocfilehash: f964c67ba7bf399e9a3761e4e201662a6a712a1b
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74856695"
---
# <a name="ml-nonfatal-error-a2031"></a>Erro não fatal A2031 (ML)

**deve ser um índice ou um registro base**

Foi feita uma tentativa de usar um registro que não era um registro de base ou de índice em uma expressão de memória.

Por exemplo, as expressões a seguir causam esse erro:

```asm
[ax]
[bl]
```

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>