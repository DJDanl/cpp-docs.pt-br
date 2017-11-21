---
title: Diretivas de Macro MASM no Assembly embutido | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- directives, macros
- inline assembly, macro directives
- macros, directives
- MASM (Microsoft Macro Assembler), inline assembly macro directives
ms.assetid: 83643a09-1699-40a8-8ef2-13502bc4ac2c
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: f789df759729deb3c2b548efb008ae9a27357ab2
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="masm-macro-directives-in-inline-assembly"></a>Diretivas de macro MASM no assembly embutido
## <a name="microsoft-specific"></a>Específico da Microsoft  
 O assembler embutido não é um assembler de macro. Não é possível usar diretivas de macro MASM (**MACRO**, `REPT`, **IRC**, `IRP`, e `ENDM`) ou operadores de macro (**<>**, **!** ,  **&** , `%`, e `.TYPE`). Um `__asm` bloco pode usar diretivas de pré-processador C, no entanto. Consulte [usando C ou C++ em blocos ASM](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md) para obter mais informações.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)