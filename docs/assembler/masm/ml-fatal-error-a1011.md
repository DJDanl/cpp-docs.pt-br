---
title: ML Erro Fatal A1011 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A1011
dev_langs:
- C++
helpviewer_keywords:
- A1011
ms.assetid: 7fbf092d-4189-4330-a884-dfa2268fc3dd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 843d676cba61e0da5f917a48408e56e79abb9efd
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32057191"
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