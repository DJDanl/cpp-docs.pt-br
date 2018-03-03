---
title: Diretivas de dados e operadores no Assembly embutido | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f2352b1809f2c0377f17fde8127fcbda6464617a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="data-directives-and-operators-in-inline-assembly"></a>Diretivas de dados e operadores no assembly embutido
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Embora um `__asm` bloco pode fazer referência a objetos e tipos de dados C ou C++, ele não é possível definir objetos de dados com diretivas MASM ou operadores. Especificamente, você não pode usar as diretivas de definição **DB**, `DW`, **DD**, `DQ`, `DT`, e `DF`, ou os operadores `DUP` ou  **Isso**. Registros e estruturas MASM também estão disponíveis. O assembler embutido não aceita as diretivas `STRUC`, `RECORD`, **largura**, ou **MÁSCARA**.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)