---
title: "Usando operadores em blocos __asm | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __asm [C++], operadores"
  - "colchetes [ ]"
  - "colchetes [ ], blocos __asm"
  - "operadores [C++], usando em blocos __asm"
  - "colchetes [ ]"
  - "colchetes [ ], blocos __asm"
ms.assetid: a26ccfd4-40ae-4a61-952f-c417982aa8dd
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Usando operadores em blocos __asm
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Um bloco de `__asm` não pode usar os operadores específicos de 2.0 C ou C\+\+, como o operador de **\<\<** .  No entanto, operadores compartilhados por C e 2.0 por MASM, como \* o operador, é interpretado como operadores de linguagem assembly.  Por exemplo, fora de um bloco de `__asm` , os colchetes \(**\[ \]**\) são interpretados como incluir os subscritos de matriz, que C dimensionar automaticamente ao tamanho de um elemento na matriz.  Dentro de um bloco de `__asm` , são consultados como o operador do índice de MASM, o que gerencie um unscaled deslocamento de bytes de qualquer objeto de dados ou rótulo \(não apenas uma matriz\).  O código a seguir ilustra a diferença:  
  
```  
int array[10];  
  
__asm mov array[6], bx ;  Store BX at array+6 (not scaled)  
  
array[6] = 0;         /* Store 0 at array+24 (scaled) */  
```  
  
 A primeira referência a `array` não é escalonada, mas a segunda é.  Observe que você pode usar o operador de **TIPO** para obter a escala com base em uma constante.  Por exemplo, as instruções seguintes são equivalentes:  
  
```  
__asm mov array[6 * TYPE int], 0 ; Store 0 at array + 24  
  
array[6] = 0;                   /* Store 0 at array + 24 */  
```  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Usando C ou C\+\+ em blocos \_\_asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)