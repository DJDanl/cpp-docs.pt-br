---
title: "Assembler embutido | Microsoft Docs"
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
  - "assembler [C++]"
  - "assembler [C++], embutidas"
  - "linguagem de assembly [C++], embutidas"
  - "assembler embutido [C++]"
  - "assembly embutido [C++]"
ms.assetid: 7e13f18f-3628-4306-8b81-4a6d09c043fe
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Assembler embutido
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 A linguagem de assembly serve para muitas finalidades, como melhorar a velocidade do programa, reduzir as necessidades de memória e controlar o hardware.  É possível usar o assembler embutido para inserir instruções da linguagem de assembly incorporada diretamente em seus programas de código\-fonte C e C\+\+, sem etapas adicionais de assembly e vinculação.  O assembler embutido é integrado ao compilador e, portanto, não é necessário um assembler separado, como o MASM \(Microsoft Macro Assembler\).  
  
> [!NOTE]
>  Os programas com código assembler embutido não são totalmente portáteis para outras plataformas de hardware.  Se seu projeto visa portabilidade, evite usar o assembler embutido.  
  
 O assembly embutido não tem suporte nos processadores ARM e [!INCLUDE[vcprx64](../Token/vcprx64_md.md)].  Os tópicos a seguir explicam como usar o assembler embutido do Visual C\/C\+\+ com processadores x86:  
  
-   [Visão geral do assembler embutido](../../assembler/inline/inline-assembler-overview.md)  
  
-   [Vantagens do assembly embutido](../../assembler/inline/advantages-of-inline-assembly.md)  
  
-   [\_\_asm](../../assembler/inline/asm.md)  
  
-   [Usando a linguagem de assembly em blocos \_\_asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)  
  
-   [Usando C ou C\+\+ em blocos \_\_asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)  
  
-   [Usando e preservando registros no assembly embutido](../../assembler/inline/using-and-preserving-registers-in-inline-assembly.md)  
  
-   [Passando para rótulos no assembly embutido](../../assembler/inline/jumping-to-labels-in-inline-assembly.md)  
  
-   [Chamando funções C no assembly embutido](../../assembler/inline/calling-c-functions-in-inline-assembly.md)  
  
-   [Chamando funções C\+\+ no assembly embutido](../../assembler/inline/calling-cpp-functions-in-inline-assembly.md)  
  
-   [Definindo blocos \_\_asm como macros do C](../../assembler/inline/defining-asm-blocks-as-c-macros.md)  
  
-   [Otimizando o assembly embutido](../../assembler/inline/optimizing-inline-assembly.md)  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Intrínsecos do compilador e linguagem do assembly](../../intrinsics/compiler-intrinsics-and-assembly-language.md)   
 [Referência de linguagem C\+\+](../../cpp/cpp-language-reference.md)