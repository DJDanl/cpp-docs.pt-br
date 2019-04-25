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
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62167368"
---
# <a name="segment-references-in-inline-assembly"></a>Referências de segmento em assembly embutido

**Seção específica da Microsoft**

Você deve se referir a segmentos pelo registro em vez de por nome (o nome do segmento `_TEXT` é inválido, por exemplo). Substituições de segmento devem usar o registro explicitamente, como em ES: [BX].

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>