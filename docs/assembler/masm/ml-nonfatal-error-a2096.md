---
title: Erro não fatal A2096 (ML)
ms.date: 08/30/2018
ms.topic: error-reference
f1_keywords:
- A2096
helpviewer_keywords:
- A2096
ms.assetid: bab0b5ee-b39f-4e44-a41a-3f949fab4297
ms.openlocfilehash: e6b31afeff801e7128b5a76576e9eaa3398f68e5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50676272"
---
# <a name="ml-nonfatal-error-a2096"></a>Erro não fatal A2096 (ML)

**segmento, grupo ou registro de segmento esperado**

Um segmento ou o grupo era esperado, mas não foi encontrado.

Um dos seguintes ocorreu:

- O operando esquerdo especificado com o segmento de substituir o operador (**:**) não era um nome de grupo segmento register (CS, DS, SS, ES, FS ou GS), o nome do segmento ou a expressão de segmento.

- O [PRESSUPOR](../../assembler/masm/assume.md) diretiva foi fornecida um registrador de segmento sem um endereço válido de segmento, registre-se do segmento, grupo ou especiais **simples** grupo.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>