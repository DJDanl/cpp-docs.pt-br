---
title: Diretivas EVEN e ALIGN | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: conceptual
f1_keywords:
- align
- EVEN
dev_langs:
- C++
helpviewer_keywords:
- EVEN directive
- directives, MASM
- MASM (Microsoft Macro Assembler), directives
- NOP (no operation instruction)
- ALIGN directive
ms.assetid: 7357ab2d-4a5c-43ca-accb-a5f21cdfcde5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 06a1007c50e3490e5b14e4da886494557be0d37e
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43688295"
---
# <a name="even-and-align-directives"></a>Diretivas EVEN e ALIGN

**Seção específica da Microsoft**

Embora o assembler embutido não oferece suporte a maioria das diretivas MASM, ele suporta `EVEN` e **ALINHAR**. Coloque essas diretivas **NOP** (nenhuma operação) instruções no código de assembly, conforme necessário para alinhar os rótulos para os limites específicos. Isso torna as operações de busca de instrução mais eficiente para alguns processadores.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>