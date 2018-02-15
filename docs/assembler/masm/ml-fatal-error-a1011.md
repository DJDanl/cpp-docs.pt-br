---
title: ML Erro Fatal A1011 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- A1011
dev_langs:
- C++
helpviewer_keywords:
- A1011
ms.assetid: 7fbf092d-4189-4330-a884-dfa2268fc3dd
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e3a614bc56c76b220eeeb73ce2cc7e90a9ca9b8e
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="ml-fatal-error-a1011"></a>Erro fatal A1011 (ML)
**diretiva deve ser no bloco de controle**  
  
 O assembler encontrar uma diretiva de alto nível em que um não era esperado. Uma das seguintes diretivas foi encontrada:  
  
-   [. ELSE](../../assembler/masm/dot-else.md) sem [. SE](../../assembler/masm/dot-if.md)  
  
-   [. ENDIF](../../assembler/masm/dot-endif.md) sem [. SE](../../assembler/masm/dot-if.md)  
  
-   [. ENDW](../../assembler/masm/dot-endw.md) sem [. WHILE](../../assembler/masm/dot-while.md)  
  
-   [. UNTILCXZ](../../assembler/masm/dot-untilcxz.md) sem [. REPITA](../../assembler/masm/dot-repeat.md)  
  
-   [. CONTINUAR](../../assembler/masm/dot-continue.md) sem [. ENQUANTO](../../assembler/masm/dot-while.md) ou [. REPITA](../../assembler/masm/dot-repeat.md)  
  
-   [. INTERROMPER](../../assembler/masm/dot-break.md) sem [. ENQUANTO](../../assembler/masm/dot-while.md) ou [. REPITA](../../assembler/masm/dot-repeat.md)  
  
-   [. ELSE](../../assembler/masm/dot-else.md) seguir `.ELSE`  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)