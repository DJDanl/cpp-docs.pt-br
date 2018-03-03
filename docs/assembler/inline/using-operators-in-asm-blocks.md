---
title: Usando operadores em blocos ASM | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ca8ac739793c81ef18f8657cbf53c9cb018b3e38
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-operators-in-asm-blocks"></a>Usando operadores em blocos __asm
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Um `__asm` bloco não é possível usar operadores de C ou C++ específicos, como o  **<<**  operador. No entanto, operadores compartilhados por C e MASM, como o \* operador, são interpretados como operadores de linguagem de assembly. Por exemplo, fora de um `__asm` bloquear colchetes (**[]**) são interpretados como subscritos de matriz, que C dimensiona automaticamente para o tamanho de um elemento na matriz de circunscrição. Dentro de um `__asm` bloco, que são vistos como o operador de índice (MASM), que gera um deslocamento de byte fora de escala de qualquer objeto de dados ou um rótulo (não apenas uma matriz). O código a seguir ilustra a diferença:  
  
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