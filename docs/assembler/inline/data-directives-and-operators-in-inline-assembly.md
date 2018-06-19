---
title: Diretivas de dados e operadores no Assembly embutido | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- data directives [C++]
- __asm keyword [C++], referencing limitations
- MASM (Microsoft Macro Assembler), directives
- directives [C++], MASM
- MASM (Microsoft Macro Assembler), structures
- operators [MASM]
- inline assembly, operators
- inline assembly, data directives
- MASM (Microsoft Macro Assembler), operators
- structures [C++], MASM
ms.assetid: fb7410c7-156a-4131-bcfc-211aa70533e3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0bd3bc686cc8cee1a02e9df936f80f542bec26bd
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32051379"
---
# <a name="data-directives-and-operators-in-inline-assembly"></a>Diretivas de dados e operadores no assembly embutido
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Embora um `__asm` bloco pode fazer referência a objetos e tipos de dados C ou C++, ele não é possível definir objetos de dados com diretivas MASM ou operadores. Especificamente, você não pode usar as diretivas de definição **DB**, `DW`, **DD**, `DQ`, `DT`, e `DF`, ou os operadores `DUP` ou  **Isso**. Registros e estruturas MASM também estão disponíveis. O assembler embutido não aceita as diretivas `STRUC`, `RECORD`, **largura**, ou **MÁSCARA**.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)