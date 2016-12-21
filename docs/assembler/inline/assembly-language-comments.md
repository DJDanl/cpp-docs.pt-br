---
title: "Coment&#225;rios da linguagem de assembly | Microsoft Docs"
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
  - "Palavra-chave __asm [C++], instruções"
  - "linguagem de assembly [C++], comentários"
  - "comentários [C++], linguagem de assembly"
  - "macros [C++], linguagem de assembly"
ms.assetid: 0dc10850-77f5-426e-9dab-185ea28e06e4
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Coment&#225;rios da linguagem de assembly
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 As instruções em um bloco de `__asm` podem usar comentários de assembly CLR:  
  
```  
__asm mov ax, offset buff ; Load address of buff  
```  
  
 Como macros C se expandem em uma única linha lógica, evite usar comentários de assembly idioma em macros. \(Consulte.\) [Definindo blocos de \_\_asm como macros C](../../assembler/inline/defining-asm-blocks-as-c-macros.md) Um bloco de `__asm` também pode conter comentários do c \- estilo 2.0; para obter mais informações, consulte [Usando C ou C\+\+ 2.0 em blocos de \_\_asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md).  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Usando linguagem de assembly em blocos de \_\_asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)