---
title: Diretivas EVEN e ALIGN | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: conceptual
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a43425a4038ffb140eeaa0a9d111a39fc5c11ff0
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32057949"
---
# <a name="even-and-align-directives"></a>Diretivas EVEN e ALIGN
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Embora o assembler embutido não oferece suporte a maioria das diretivas MASM, ele oferece suporte a `EVEN` e **ALINHAR**. Colocar essas diretivas **NOP** (nenhuma operação) instruções no código de assembly, conforme necessário para alinhar rótulos limites específicos. Isso torna as operações de busca de instrução mais eficiente para alguns processadores.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)