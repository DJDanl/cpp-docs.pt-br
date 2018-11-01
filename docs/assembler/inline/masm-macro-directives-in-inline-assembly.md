---
title: Diretivas de macro MASM no assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- directives, macros
- inline assembly, macro directives
- macros, directives
- MASM (Microsoft Macro Assembler), inline assembly macro directives
ms.assetid: 83643a09-1699-40a8-8ef2-13502bc4ac2c
ms.openlocfilehash: 7e1bed782d28a5bf7c934c3f57f50aae70038578
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50508921"
---
# <a name="masm-macro-directives-in-inline-assembly"></a>Diretivas de macro MASM no assembly embutido

**Seção específica da Microsoft**

O assembler embutido não é um assembler de macro. Não é possível usar diretivas de macro MASM (**MACRO**, `REPT`, **IRC**, `IRP`, e `ENDM`) ou operadores de macro (**<>**, **!** , **&**, `%`, e `.TYPE`). Um `__asm` bloco pode usar diretivas de pré-processador de C, no entanto. Ver [usando C ou C++ em blocos ASM](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md) para obter mais informações.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>