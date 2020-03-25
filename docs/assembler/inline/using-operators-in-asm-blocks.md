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
ms.openlocfilehash: b6ac9f7174baf1e0ebe41181c6a6f43e7bb3f5d1
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169091"
---
# <a name="using-operators-in-__asm-blocks"></a>Usando operadores em blocos __asm

**Seção específica da Microsoft**

Um bloco de `__asm` não pode usar C++ operadores C ou específicos, como o operador de **<<** . No entanto, os operadores compartilhados por C e MASM, como o operador de \*, são interpretados como operadores de linguagem de assembly. Por exemplo, fora de um bloco de `__asm`, colchetes ( **[]** ) são interpretados como subfechando scripts de matriz, que C é dimensionado automaticamente para o tamanho de um elemento na matriz. Dentro de um bloco de `__asm`, eles são vistos como o operador de índice MASM, que gera um deslocamento de byte não dimensionado de qualquer objeto de dados ou rótulo (não apenas uma matriz). O código a seguir ilustra a diferença:

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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Usando C ou C++ em blocos __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)<br/>
