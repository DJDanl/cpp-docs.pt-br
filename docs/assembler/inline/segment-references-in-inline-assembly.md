---
title: Referências de segmento em assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- references, inline assembly
- segment references in inline assembly
- inline assembly, segment references
- registers
- inline assembly, registers
- registers, inline assembly
ms.assetid: c63e6bb4-49d9-4fa1-bb22-eea21b5cbc0f
ms.openlocfilehash: 5c07fa897da23a55f376a20e7588c8c8c269d1a6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50577327"
---
# <a name="segment-references-in-inline-assembly"></a>Referências de segmento em assembly embutido

**Seção específica da Microsoft**

Você deve se referir a segmentos pelo registro em vez de por nome (o nome do segmento `_TEXT` é inválido, por exemplo). Substituições de segmento devem usar o registro explicitamente, como em ES: [BX].

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>