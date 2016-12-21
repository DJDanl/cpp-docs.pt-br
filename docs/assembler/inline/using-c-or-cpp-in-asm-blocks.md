---
title: "Usando C ou C++ em blocos __asm | Microsoft Docs"
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
  - "Palavra-chave __asm [C++], elementos C/C++ em"
  - "comentários, em blocos __asm"
  - "constantes, em blocos __asm"
  - "assembly embutido, mesclando instruções com instruções C/C++"
  - "Macros , blocos __asm"
  - "diretivas de pré-processador"
  - "diretivas de pré-processador, usado em blocos __asm"
  - "pré-processador, Diretivas ()"
  - "símbolos, em blocos __asm"
  - "nomes de tipos, usado em blocos __asm"
  - "nomes typedef, usado em blocos __asm"
ms.assetid: ae8b2b52-6b75-42e3-ac0c-ad02d922ed97
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Usando C ou C++ em blocos __asm
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Como as instruções de assembly embutidos podem ser combinadas com as instruções de 2.0 C ou C\+\+, podem fazer referência a variáveis de 2.0 C ou C\+\+ por nome e usar muitos outros elementos desses idiomas.  
  
 Um bloco de `__asm` pode usar os seguintes elementos de linguagem:  
  
-   Símbolos, inclusive rótulos e nomes de variável e de função  
  
-   Constantes, inclusive constantes e membros simbólicos de `enum`  
  
-   Macros e políticas de pré\-processador  
  
-   Comentários \( **\/\* \*\/** e **\/\/** \)  
  
-   Nomes de tipo \(onde um tipo de MASM seria legais\)  
  
-   nomes de`typedef` , geralmente usados com os operadores como **PTR** e **TIPO** ou para especificar a estrutura ou o sindicalistas  
  
 Dentro de um bloco de `__asm` , você pode especificar constantes de número inteiro com notação de 2.0 C ou a notação de raiz de assembler \(0x100 e 100h são equivalentes, por exemplo\).  Isso permite que você defina \(usando\) `#define`uma constante em C e use a em 2.0 C ou C\+\+ e partes do assembly do programa.  Você também pode especificar constantes em octal precedendo\-as com um 0.  Por exemplo, 0777 especifica uma constante octal.  
  
## Que você deseja saber mais?  
  
-   [Usando operadores em blocos de \_\_asm](../../assembler/inline/using-operators-in-asm-blocks.md)  
  
-   [Usando blocos de \_\_asm de 2.0 C ou C\+\+ Symbols\_in](../Topic/Using%20C%20or%20C++%20Symbols%20in%20__asm%20Blocks.md)  
  
-   [Acessando C ou C\+\+ 2.0 dados em blocos de \_\_asm](../Topic/Accessing%20C%20or%20C++%20Data%20in%20__asm%20Blocks.md)  
  
-   [Funções de gravação com assembly embutido](../../assembler/inline/writing-functions-with-inline-assembly.md)  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)