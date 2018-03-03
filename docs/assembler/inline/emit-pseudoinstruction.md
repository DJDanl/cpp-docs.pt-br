---
title: "pseudoinstrução Emit | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _emit
dev_langs:
- C++
helpviewer_keywords:
- byte defining (inline assembly)
- _emit pseudoinstruction
ms.assetid: 004c48f3-364c-4e82-9a51-e326f9cc7b2b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c506c689b94a7f6f7fa51c4c456e20454b28df02
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="emit-pseudoinstruction"></a>Pseudoinstrução _emit
## <a name="microsoft-specific"></a>Específico da Microsoft  
 O **pseudoinstrução** Emit define um byte no local atual no segmento de texto atual. O **pseudoinstrução** Emit é semelhante a [DB](../../assembler/masm/db.md) diretiva de MASM.  
  
 O fragmento a seguir coloca os bytes 0x4A, 0x43 e 0x4B no código:  
  
```  
#define randasm __asm _emit 0x4A __asm _emit 0x43 __asm _emit 0x4B  
 .  
 .  
 .  
__asm {  
     randasm  
     }  
```  
  
> [!CAUTION]
>  Se `_emit` gera instruções que modificam registros e compilar o aplicativo com otimizações, o compilador não pode determinar quais registros são afetados. Por exemplo, se `_emit` gera uma instrução que modifica o **rax** o registro, o compilador não sabe que **rax** foi alterado. O compilador pode, em seguida, fazer uma suposição incorreta sobre o valor em que registrar depois que o código do assembler embutido é executado. Consequentemente, seu aplicativo pode apresentar um comportamento imprevisível quando ele é executado.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)