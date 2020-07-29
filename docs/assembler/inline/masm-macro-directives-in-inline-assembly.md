---
title: Diretivas de macro MASM no assembly embutido
ms.date: 08/30/2018
helpviewer_keywords:
- directives, macros
- inline assembly, macro directives
- macros, directives
- MASM (Microsoft Macro Assembler), inline assembly macro directives
ms.assetid: 83643a09-1699-40a8-8ef2-13502bc4ac2c
ms.openlocfilehash: 964f70aeef6e0e62ac4b941b2cc26d3e7c7ef466
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87191788"
---
# <a name="masm-macro-directives-in-inline-assembly"></a>Diretivas de macro MASM no assembly embutido

**Específico da Microsoft**

O Assembler embutido não é um assembler de macro. Não é possível usar as diretivas de macro MASM (**macro**, `REPT` **IRC**, `IRP` e `ENDM` ) ou operadores de macro ( **<>** , **!**, **&** , `%` e `.TYPE` ). **`__asm`** No entanto, um bloco pode usar as diretivas de pré-processador do C. Consulte [usando C ou C++ em blocos de __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md) para obter mais informações.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Usando o idioma do assembly em blocos de __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>
