---
title: pseudoinstrução Emit | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: conceptual
f1_keywords:
- _emit
dev_langs:
- C++
helpviewer_keywords:
- byte defining (inline assembly)
- _emit pseudoinstruction
ms.assetid: 004c48f3-364c-4e82-9a51-e326f9cc7b2b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 569e3a078109e66df7dcf5cbf314817ce0786899
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50061918"
---
# <a name="emit-pseudoinstruction"></a>Pseudoinstrução _emit

**Seção específica da Microsoft**

O **pseudoinstrução** Emit define um byte na posição atual no segmento de texto atual. O **pseudoinstrução** Emit é semelhante a [DB](../../assembler/masm/db.md) diretiva do MASM.

O fragmento a seguir coloca os bytes 0x4A, 0x43 e 0x4B no código:

```cpp
#define randasm __asm _emit 0x4A __asm _emit 0x43 __asm _emit 0x4B
.
.
.
__asm {
    randasm
    }
```

> [!CAUTION]
> Se `_emit` gera instruções que modificam os registros e você compila o aplicativo com otimizações, o compilador não pode determinar quais registros são afetados. Por exemplo, se `_emit` gera uma instrução que modifica o **rax** register, o compilador não sabe disso **rax** foi alterado. O compilador pode, em seguida, fazer uma suposição incorreta sobre o valor em que registrar depois que o código de assembler embutido é executado. Consequentemente, seu aplicativo pode apresentar um comportamento imprevisível, quando ele é executado.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>