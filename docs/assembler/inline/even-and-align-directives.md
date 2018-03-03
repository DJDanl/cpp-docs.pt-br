---
title: Diretivas EVEN e ALIGN | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 278794e0105ee054fdd4948967a78982a9d46d8c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="even-and-align-directives"></a>Diretivas EVEN e ALIGN
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Embora o assembler embutido não oferece suporte a maioria das diretivas MASM, ele oferece suporte a `EVEN` e **ALINHAR**. Colocar essas diretivas **NOP** (nenhuma operação) instruções no código de assembly, conforme necessário para alinhar rótulos limites específicos. Isso torna as operações de busca de instrução mais eficiente para alguns processadores.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)