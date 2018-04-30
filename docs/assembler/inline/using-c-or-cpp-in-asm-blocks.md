---
title: Usando C ou C++ em blocos ASM | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- inline assembly, mixing instructions with C/C++ statements
- symbols, in __asm blocks
- macros, __asm blocks
- preprocessor directives, used in __asm blocks
- type names, used in __asm blocks
- preprocessor directives
- preprocessor, directives
- constants, in __asm blocks
- comments, in __asm blocks
- typedef names, used in __asm blocks
- __asm keyword [C++], C/C++ elements in
ms.assetid: ae8b2b52-6b75-42e3-ac0c-ad02d922ed97
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5e9451a0b665e5377c2acaf871154ec78a38c8b5
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="using-c-or-c-in-asm-blocks"></a>Usando C ou C++ em blocos __asm
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Como as instruções de assembly embutido podem ser combinadas com instruções C ou C++, podem se referir a variáveis de C ou C++ por nome e usar muitos outros elementos desses idiomas.  
  
 Um `__asm` bloco pode usar os seguintes elementos de linguagem:  
  
-   Símbolos, incluindo rótulos e nomes de variáveis e funções  
  
-   Constantes, incluindo as constantes simbólicas e `enum` membros  
  
-   Macros e diretivas de pré-processador  
  
-   Comentários (ambos **/ \* \* /** e **//** )  
  
-   Digite nomes (onde um tipo MASM seria legal)  
  
-   `typedef` nomes, geralmente usados com operadores, como **PTR** e **tipo** ou para especificar membros de estrutura ou união  
  
 Dentro de um `__asm` bloco, você pode especificar constantes inteiras com notação C ou notação de base do assembler (0x100 e 100 h são equivalentes, por exemplo). Isso permite que você defina (usando `#define`) uma constante em C e, em seguida, usá-lo em C ou C++ e assembly partes do programa. Você também pode especificar constantes em octal, precedendo-as com um 0. Por exemplo, 0777 Especifica uma constante octal.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Usando operadores em blocos __asm](../../assembler/inline/using-operators-in-asm-blocks.md)  
  
-   [Usando C ou C++ Symbols_in blocos de ASM](../../assembler/inline/using-c-or-cpp-symbols-in-asm-blocks.md)  
  
-   [Acessando dados C ou C++ em blocos __asm](../../assembler/inline/accessing-c-or-cpp-data-in-asm-blocks.md)  
  
-   [Escrevendo funções com assembly embutido](../../assembler/inline/writing-functions-with-inline-assembly.md)  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)