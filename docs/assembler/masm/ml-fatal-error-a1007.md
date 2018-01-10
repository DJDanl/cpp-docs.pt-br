---
title: ML Erro Fatal A1007 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: A1007
dev_langs: C++
helpviewer_keywords: A1007
ms.assetid: bcf9c826-beb3-4e93-91fe-1ffd34995fbf
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 619f1eae458b52eb7851118d6702dccec769a1ca
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ml-fatal-error-a1007"></a>Erro fatal A1007 (ML)
**nível de aninhamento muito profundo**  
  
 O assembler atingiu seu limite de aninhamento. O limite é de 20 níveis, exceto quando indicado em contrário.  
  
 Um dos procedimentos a seguir foi muito aninhado:  
  
-   Uma diretiva de alto nível, como [. Se](../../assembler/masm/dot-if.md), [. REPITA](../../assembler/masm/dot-repeat.md), ou [. ENQUANTO](../../assembler/masm/dot-while.md).  
  
-   Uma definição de estrutura.  
  
-   Uma diretiva de assembly condicional.  
  
-   Uma definição de procedimento.  
  
-   Um [PUSHCONTEXT](../../assembler/masm/pushcontext.md) diretiva (o limite é 10).  
  
-   Uma definição de segmento.  
  
-   Um arquivo de inclusão.  
  
-   Uma macro.  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)