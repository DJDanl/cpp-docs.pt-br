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
ms.openlocfilehash: 865fc5fac5f46cdc8c55966e9989227d1d671d6f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169247"
---
# <a name="segment-references-in-inline-assembly"></a>Referências de segmento em assembly embutido

**Seção específica da Microsoft**

Você deve se referir aos segmentos pelo registro, em vez de pelo nome (o nome do segmento `_TEXT` é inválido, por exemplo). As substituições de segmento devem usar o registro explicitamente, como em ES: [BX].

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>
