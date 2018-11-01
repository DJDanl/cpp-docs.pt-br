---
title: Erro não fatal A2050 (ML)
ms.date: 08/30/2018
ms.topic: error-reference
f1_keywords:
- A2050
helpviewer_keywords:
- A2050
ms.assetid: 16f3a58f-4bde-48f1-b0e3-2ed9612780a5
ms.openlocfilehash: 59d08b9c2743a3b45633527bcc54b3e1c4d6a58c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50439709"
---
# <a name="ml-nonfatal-error-a2050"></a>Erro não fatal A2050 (ML)

**real ou o número de BCD não permitido**

Um número (real) de ponto flutuante ou uma constante binary coded decimal (BCD) foi usado diferente de como um inicializador de dados.

Um dos seguintes ocorreu:

- Um número real ou um BCD foi usado em uma expressão.

- Um número real foi usado para inicializar uma diretiva diferente de [DWORD](../../assembler/masm/dword.md), [QWORD](../../assembler/masm/qword.md), ou [TBYTE](../../assembler/masm/tbyte.md).

- Um BCD foi usado para inicializar uma diretiva diferente de `TBYTE`.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>