---
title: Erro não fatal de ML A2206 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A2206
dev_langs:
- C++
helpviewer_keywords:
- A2206
ms.assetid: 711846d0-5a09-4353-8857-60588c25526a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 10edbe68ca7f0093cdeb6a9ca5a02cde07f556e6
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43676342"
---
# <a name="ml-nonfatal-error-a2206"></a>Erro não fatal A2206 (ML)

**operador ausente na expressão**

Uma expressão não pode ser avaliada porque está faltando um operador. Essa mensagem de erro também pode ser um efeito colateral de um erro de programa anterior.

A seguinte linha gerará este erro:

```asm
value1 = ( 1 + 2 ) 3
```

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>