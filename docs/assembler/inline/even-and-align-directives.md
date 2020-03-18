---
title: Diretivas EVEN e ALIGN
ms.date: 08/30/2018
helpviewer_keywords:
- EVEN directive
- directives, MASM
- MASM (Microsoft Macro Assembler), directives
- NOP (no operation instruction)
- ALIGN directive
ms.assetid: 7357ab2d-4a5c-43ca-accb-a5f21cdfcde5
ms.openlocfilehash: 63fa73988b9b9433a988035789a923ac73936214
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79441582"
---
# <a name="even-and-align-directives"></a>Diretivas EVEN e ALIGN

**Seção específica da Microsoft**

Embora o Assembler embutido não dê suporte à maioria das diretivas MASM, ele dá suporte a `EVEN` e **alinhar**. Essas diretivas colocam instruções **Nop** (sem operação) no código do assembly, conforme necessário, para alinhar os rótulos a limites específicos. Isso torna as operações de busca de instrução mais eficientes para alguns processadores.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>