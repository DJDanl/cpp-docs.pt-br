---
title: Usando operadores em blocos __asm
ms.date: 08/30/2018
helpviewer_keywords:
- brackets [ ]
- brackets [ ], __asm blocks
- __asm keyword [C++], operators
- square brackets [ ], __asm blocks
- operators [C++], using in __asm blocks
- square brackets [ ]
ms.assetid: a26ccfd4-40ae-4a61-952f-c417982aa8dd
ms.openlocfilehash: cdcfee20cfdc5a6dc315d00ef024d1616900a2e8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87191099"
---
# <a name="using-operators-in-__asm-blocks"></a>Usando operadores em blocos __asm

**Específico da Microsoft**

Um **`__asm`** bloco não pode usar operadores específicos de C ou C++, como o **<<** operador. No entanto, os operadores compartilhados por C e MASM, como o \* operador, são interpretados como operadores de linguagem de assembly. Por exemplo, fora de um **`__asm`** bloco, colchetes (**[]**) são interpretados como subscritos de matriz delimitador, que C é dimensionado automaticamente para o tamanho de um elemento na matriz. Dentro de um **`__asm`** bloco, eles são vistos como o operador de índice MASM, que gera um deslocamento de byte não dimensionado de qualquer objeto de dados ou rótulo (não apenas uma matriz). O código a seguir ilustra a diferença:

```cpp
int array[10];

__asm mov array[6], bx ;  Store BX at array+6 (not scaled)

array[6] = 0;         /* Store 0 at array+24 (scaled) */
```

A primeira referência a `array` não é dimensionada, mas a segunda é. Observe que você pode usar o operador **Type** para obter dimensionamento com base em uma constante. Por exemplo, as instruções seguintes são equivalentes:

```cpp
__asm mov array[6 * TYPE int], 0 ; Store 0 at array + 24

array[6] = 0;                   /* Store 0 at array + 24 */
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Usando C ou C++ em blocos de __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)<br/>
