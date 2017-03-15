---
title: "Depura&#231;&#227;o e listagens para assembly embutido | Microsoft Docs"
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
  - "Palavra-chave __asm [C++], depuração"
  - "bugs, blocos __asm"
  - "depurando [C++], código de assembly embutido"
  - "assembly embutido, depuração"
  - "assembly embutido, listas"
  - "depurador de nível de origem"
ms.assetid: 69266930-6f9a-433d-b704-f4f44e7b2583
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Depura&#231;&#227;o e listagens para assembly embutido
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Programas que contêm código embutida de assembly poderão ser depurado com um depurador da fonte nível se você compila com a opção de [\/Zi](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) .  
  
 No depurador, você pode definir pontos de interrupção em 2.0 C ou C\+\+ e linhas de assembly idioma.  Se você habilitar o modo misto do assembly e de origem, você pode exibir a origem e o formulário desmontado de código do assembly.  
  
 Observe que coloca várias instruções de assembly ou instruções de idioma de origem em uma linha podem impedir de depuração.  No modo de origem, você poderá usar o depurador para definir pontos de interrupção em uma única linha mas não em instruções individuais na mesma linha.  O mesmo princípio se aplica a `__asm` um bloco definido como a macro c, que se expande a uma única linha lógica.  
  
 Se você criar uma listagem mista de origem e do assembly com a opção do compilador de [\/FAs](../../build/reference/fa-fa-listing-file.md) , a lista contém os formatos de origem e do assembly de cada linha do assembly idioma.  Macros não são expandidos nas listagens, mas são expandidos durante a compilação.  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Usando linguagem de assembly em blocos de \_\_asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)