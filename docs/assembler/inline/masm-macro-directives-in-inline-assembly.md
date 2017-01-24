---
title: "Diretivas de macro MASM no assembly embutido | Microsoft Docs"
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
  - "Diretivas (), Macros "
  - "assembly embutido, diretivas macro"
  - "Macros , Diretivas ()"
  - "MASM (Microsoft Macro Assembler), diretivas macro de assembly embutido"
ms.assetid: 83643a09-1699-40a8-8ef2-13502bc4ac2c
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Diretivas de macro MASM no assembly embutido
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 O assembler embutido não é uma macro assembler.  Você não pode usar políticas macro de MASM \(**MACRO**, `REPT`, **IRC**, `IRP`, e `ENDM`\) ou operadores macro \(**\<\>\!**, **&**, `%`, e `.TYPE`\).  Um bloco de `__asm` pode usar políticas de pré\-processador C, porém.  Consulte [Usando C ou C\+\+ 2.0 em blocos de \_\_asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md) para obter mais informações.  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Usando linguagem de assembly em blocos de \_\_asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)