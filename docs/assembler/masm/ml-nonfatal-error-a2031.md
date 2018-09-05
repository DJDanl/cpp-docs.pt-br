---
title: Erro não fatal de ML A2031 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A2031
dev_langs:
- C++
helpviewer_keywords:
- A2031
ms.assetid: d5b11f58-4a00-42be-9062-8fa8728e6306
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bf6744224847e114e76df6e7ad6470696d3e8387
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43682652"
---
# <a name="ml-nonfatal-error-a2031"></a>Erro não fatal A2031 (ML)

**deve ser o índice ou a base de dados de registro**

Foi feita uma tentativa para usar um registro que não era um registro de base ou índice em uma expressão de memória.

Por exemplo, as expressões a seguir causam esse erro:

```asm
[ax]
[bl]
```

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>