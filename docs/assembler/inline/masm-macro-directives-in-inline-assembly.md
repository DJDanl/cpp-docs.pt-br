---
title: Diretivas de Macro MASM no Assembly embutido | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
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
ms.openlocfilehash: 35ad22a9a4b79a31665ab6b156f8174d395bb0ee
ms.sourcegitcommit: fb9448eb96c6351a77df04af16ec5c0fb9457d9e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/13/2018
ms.locfileid: "43687967"
---
# <a name="masm-macro-directives-in-inline-assembly"></a>Diretivas de macro MASM no assembly embutido

**Seção específica da Microsoft**

O assembler embutido não é um assembler de macro. Não é possível usar diretivas de macro MASM (**MACRO**, `REPT`, **IRC**, `IRP`, e `ENDM`) ou operadores de macro (**<>**, **!** , **&**, `%`, e `.TYPE`). Um `__asm` bloco pode usar diretivas de pré-processador de C, no entanto. Ver [usando C ou C++ em blocos ASM](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md) para obter mais informações.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>