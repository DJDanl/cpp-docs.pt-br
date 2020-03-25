---
title: Pseudoinstrução _emit
ms.date: 08/30/2018
f1_keywords:
- _emit
helpviewer_keywords:
- byte defining (inline assembly)
- _emit pseudoinstruction
ms.assetid: 004c48f3-364c-4e82-9a51-e326f9cc7b2b
ms.openlocfilehash: 8be250aadf20dc4a7dee6a0b565ece21840339d7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169468"
---
# <a name="_emit-pseudoinstruction"></a>Pseudoinstrução _emit

**Seção específica da Microsoft**

O **_emit** pseudoinstruction define um byte no local atual no segmento de texto atual. O **_emit** pseudoinstruction se assemelha à diretiva [DB](../../assembler/masm/db.md) de MASM.

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
> Se `_emit` gerar instruções que modificam os registros e você compilar o aplicativo com otimizações, o compilador não poderá determinar quais registros serão afetados. Por exemplo, se `_emit` gera uma instrução que modifica o registro **Rax** , o compilador não sabe que **Rax** foi alterado. O compilador pode então fazer uma suposição incorreta sobre o valor no registro depois que o código embutido do assembler é executado. Consequentemente, seu aplicativo pode apresentar comportamento imprevisível quando é executado.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>
