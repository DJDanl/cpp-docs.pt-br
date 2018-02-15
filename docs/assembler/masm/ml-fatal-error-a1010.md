---
title: ML Erro Fatal A1010 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- A1010
dev_langs:
- C++
helpviewer_keywords:
- A1010
ms.assetid: 9e0b5241-67f4-4740-8701-3b2d2d1ad9e4
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 553071ff10688f0b49909b16c8c60d95899247d1
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="ml-fatal-error-a1010"></a>Erro fatal A1010 (ML)
**aninhamento de bloco não correspondentes:**  
  
 A partir de um bloco não tinha um fim correspondente ou final de um bloco não tem um início correspondente. Um dos procedimentos a seguir pode estar envolvido:  
  
-   Uma diretiva de alto nível, como [. Se](../../assembler/masm/dot-if.md), [. REPITA](../../assembler/masm/dot-repeat.md), ou [. ENQUANTO](../../assembler/masm/dot-while.md).  
  
-   Uma diretiva de assembly condicional como [se](../../assembler/masm/if-masm.md), [REPITA](../../assembler/masm/repeat.md), ou **ENQUANTO**.  
  
-   Uma definição de estrutura ou união.  
  
-   Uma definição de procedimento.  
  
-   Uma definição de segmento.  
  
-   Um [POPCONTEXT](../../assembler/masm/popcontext.md) diretiva.  
  
-   Um assembly condicional diretiva, como um [ELSE](../../assembler/masm/else-masm.md), [ELSEIF](../../assembler/masm/elseif-masm.md), ou **ENDIF** sem uma [se](../../assembler/masm/if-masm.md).  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)