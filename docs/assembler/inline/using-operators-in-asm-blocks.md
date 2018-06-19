---
title: Usando operadores em blocos ASM | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- brackets [ ]
- brackets [ ], __asm blocks
- __asm keyword [C++], operators
- square brackets [ ], __asm blocks
- operators [C++], using in __asm blocks
- square brackets [ ]
ms.assetid: a26ccfd4-40ae-4a61-952f-c417982aa8dd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2e1c7c4b8415655aff36327db9c6a9f866d82683
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32051124"
---
# <a name="using-operators-in-asm-blocks"></a>Usando operadores em blocos __asm
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Um `__asm` bloco não é possível usar operadores de C ou C++ específicos, como o **<<** operador. No entanto, operadores compartilhados por C e MASM, como o \* operador, são interpretados como operadores de linguagem de assembly. Por exemplo, fora de um `__asm` bloquear colchetes (**[]**) são interpretados como subscritos de matriz, que C dimensiona automaticamente para o tamanho de um elemento na matriz de circunscrição. Dentro de um `__asm` bloco, que são vistos como o operador de índice (MASM), que gera um deslocamento de byte fora de escala de qualquer objeto de dados ou um rótulo (não apenas uma matriz). O código a seguir ilustra a diferença:  
  
```  
int array[10];  
  
__asm mov array[6], bx ;  Store BX at array+6 (not scaled)  
  
array[6] = 0;         /* Store 0 at array+24 (scaled) */  
```  
  
 A primeira referência às `array` não é redimensionado, mas o segundo. Observe que você pode usar o **tipo** operador para obter o dimensionamento com base em uma constante. Por exemplo, as instruções a seguir são equivalentes:  
  
```  
__asm mov array[6 * TYPE int], 0 ; Store 0 at array + 24  
  
array[6] = 0;                   /* Store 0 at array + 24 */  
```  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Usando C ou C++ em blocos __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)