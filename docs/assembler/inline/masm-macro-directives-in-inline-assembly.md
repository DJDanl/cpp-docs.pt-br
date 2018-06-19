---
title: Diretivas de Macro MASM no Assembly embutido | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- directives, macros
- inline assembly, macro directives
- macros, directives
- MASM (Microsoft Macro Assembler), inline assembly macro directives
ms.assetid: 83643a09-1699-40a8-8ef2-13502bc4ac2c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cfd8e3ca5fb6bf65a288c17b1754d567b2b081a8
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32049845"
---
# <a name="masm-macro-directives-in-inline-assembly"></a>Diretivas de macro MASM no assembly embutido
## <a name="microsoft-specific"></a>Específico da Microsoft  
 O assembler embutido não é um assembler de macro. Não é possível usar diretivas de macro MASM (**MACRO**, `REPT`, **IRC**, `IRP`, e `ENDM`) ou operadores de macro (**<>**, **!** , **&**, `%`, e `.TYPE`). Um `__asm` bloco pode usar diretivas de pré-processador C, no entanto. Consulte [usando C ou C++ em blocos ASM](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md) para obter mais informações.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)