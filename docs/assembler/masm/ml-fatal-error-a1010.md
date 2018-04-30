---
title: ML Erro Fatal A1010 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A1010
dev_langs:
- C++
helpviewer_keywords:
- A1010
ms.assetid: 9e0b5241-67f4-4740-8701-3b2d2d1ad9e4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b622595b6994c4c4eaa74ed8f824f28dffe89b1a
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
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