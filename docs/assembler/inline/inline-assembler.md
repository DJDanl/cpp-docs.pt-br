---
title: Assembler embutido | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- assembler [C++]
- assembler [C++], inline
- assembly language [C++], inline
- inline assembler [C++]
- inline assembly [C++]
ms.assetid: 7e13f18f-3628-4306-8b81-4a6d09c043fe
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5236bebdeef2db519556d3dace4c20d9529d0e23
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="inline-assembler"></a>Assembler embutido
**Seção específica da Microsoft**  
  
 A linguagem de assembly serve para muitas finalidades, como melhorar a velocidade do programa, reduzir as necessidades de memória e controlar o hardware. É possível usar o assembler embutido para inserir instruções da linguagem de assembly incorporada diretamente em seus programas de código-fonte C e C++, sem etapas adicionais de assembly e vinculação. O assembler embutido é integrado ao compilador e, portanto, não é necessário um assembler separado, como o MASM (Microsoft Macro Assembler).  
  
> [!NOTE]
>  Os programas com código assembler embutido não são totalmente portáteis para outras plataformas de hardware. Se seu projeto visa portabilidade, evite usar o assembler embutido.  
  
 O assembly embutido não tem suporte nos processadores ARM e [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)].  Os tópicos a seguir explicam como usar o assembler embutido do Visual C/C++ com processadores x86:  
  
-   [Visão geral do assembler embutido](../../assembler/inline/inline-assembler-overview.md)  
  
-   [Vantagens do assembly embutido](../../assembler/inline/advantages-of-inline-assembly.md)  
  
-   [__asm](../../assembler/inline/asm.md)  
  
-   [Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)  
  
-   [Usando C ou C++ em blocos __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)  
  
-   [Usando e preservando registros no assembly embutido](../../assembler/inline/using-and-preserving-registers-in-inline-assembly.md)  
  
-   [Passando para rótulos no assembly embutido](../../assembler/inline/jumping-to-labels-in-inline-assembly.md)  
  
-   [Chamando funções C no assembly embutido](../../assembler/inline/calling-c-functions-in-inline-assembly.md)  
  
-   [Chamando funções C++ no assembly embutido](../../assembler/inline/calling-cpp-functions-in-inline-assembly.md)  
  
-   [Definindo blocos __asm como macros de C](../../assembler/inline/defining-asm-blocks-as-c-macros.md)  
  
-   [Otimizando o assembly embutido](../../assembler/inline/optimizing-inline-assembly.md)  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Intrínsecos do compilador e linguagem de Assembly](../../intrinsics/compiler-intrinsics-and-assembly-language.md)   
 [Referência da linguagem C++](../../cpp/cpp-language-reference.md)