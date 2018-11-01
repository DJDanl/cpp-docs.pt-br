---
title: Diretivas EVEN e ALIGN
ms.date: 08/30/2018
f1_keywords:
- align
- EVEN
helpviewer_keywords:
- EVEN directive
- directives, MASM
- MASM (Microsoft Macro Assembler), directives
- NOP (no operation instruction)
- ALIGN directive
ms.assetid: 7357ab2d-4a5c-43ca-accb-a5f21cdfcde5
ms.openlocfilehash: 522d5689d680d0fc334743d2802abe21570dd6f3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50604342"
---
# <a name="even-and-align-directives"></a>Diretivas EVEN e ALIGN

**Seção específica da Microsoft**

Embora o assembler embutido não oferece suporte a maioria das diretivas MASM, ele suporta `EVEN` e **ALINHAR**. Coloque essas diretivas **NOP** (nenhuma operação) instruções no código de assembly, conforme necessário para alinhar os rótulos para os limites específicos. Isso torna as operações de busca de instrução mais eficiente para alguns processadores.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>