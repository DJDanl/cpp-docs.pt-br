---
title: Diretivas de macro MASM no assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- directives, macros
- inline assembly, macro directives
- macros, directives
- MASM (Microsoft Macro Assembler), inline assembly macro directives
ms.assetid: 83643a09-1699-40a8-8ef2-13502bc4ac2c
ms.openlocfilehash: 38b73346fc52f6b5efe478f8eb960ad049fae924
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169273"
---
# <a name="masm-macro-directives-in-inline-assembly"></a>Diretivas de macro MASM no assembly embutido

**Seção específica da Microsoft**

O Assembler embutido não é um assembler de macro. Não é possível usar as diretivas de macro MASM (**macro**, `REPT`, **IRC**, `IRP`e `ENDM`) ou operadores de macro ( **<>** , **!** , **&** , `%`e `.TYPE`). No entanto, um bloco de `__asm` pode usar as diretivas de pré-processador do C. Consulte [usando C ou C++ em blocos de __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md) para obter mais informações.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>
