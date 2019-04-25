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
ms.openlocfilehash: a871c19942252bf6a1a4901f8854b7b759700cd9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62166497"
---
# <a name="using-operators-in-asm-blocks"></a>Usando operadores em blocos __asm

**Seção específica da Microsoft**

Uma `__asm` bloco não é possível usar operadores específicos de C ou C++, como o **<<** operador. No entanto, operadores compartilhados por C e MASM, tais como o \* operador, são interpretados como operadores de linguagem de assembly. Por exemplo, fora de um `__asm` bloquear, os colchetes (**[]**) são interpretados como subscritos de matriz, que C pode ser dimensionado automaticamente para o tamanho de um elemento na matriz de circunscrição. Dentro de um `__asm` bloco, eles são vistos como o operador de índice (MASM), que produz um deslocamento de byte fora de escala de qualquer objeto de dados ou o rótulo (não apenas uma matriz). O código a seguir ilustra a diferença:

```cpp
int array[10];

__asm mov array[6], bx ;  Store BX at array+6 (not scaled)

array[6] = 0;         /* Store 0 at array+24 (scaled) */
```

A primeira referência às `array` não é redimensionada, mas a segunda. Observe que você pode usar o **tipo** operador para atingir o dimensionamento com base em uma constante. Por exemplo, as instruções a seguir são equivalentes:

```cpp
__asm mov array[6 * TYPE int], 0 ; Store 0 at array + 24

array[6] = 0;                   /* Store 0 at array + 24 */
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Usando C ou C++ em blocos __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)<br/>