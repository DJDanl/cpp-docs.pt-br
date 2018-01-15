---
title: ML Erro Fatal A1011 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: A1011
dev_langs: C++
helpviewer_keywords: A1011
ms.assetid: 7fbf092d-4189-4330-a884-dfa2268fc3dd
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 470340e76897394e5b8ecb042ff97562b0c94c2d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
  
-   [. ELSE](../../assembler/masm/dot-else.md) seguir`.ELSE`  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)