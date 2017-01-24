---
title: "Macros nulas e indefinidas | Microsoft Docs"
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
  - "Macros , nulo e indefinido"
  - "programa NMAKE, macros nulas"
  - "programa NMAKE, macros indefinidas"
  - "Macros nulas em NMAKE"
  - "macros indefinidas e NMAKE"
ms.assetid: 1db4611a-1755-4328-b00f-d35365af8b6c
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Macros nulas e indefinidas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Nulo e macros indefinidos expandem em cadeias de caracteres nulas, mas uma macro definido como uma cadeia de caracteres nula será considerado definido em expressões de pré\-processamento.  Para definir uma macro como uma cadeia de caracteres nula, não especifique nenhum caractere exceto os espaços ou guias depois do sinal de igual \(\=\) em um arquivo de linha de comando ou de comando, e incluir a cadeia de caracteres nula ou a definição aspas duplas \(” "\).  Para undefine uma macro, use **\!UNDEF.** Para obter mais informações, consulte [Políticas de pré\-processamento de Makefile](../build/makefile-preprocessing-directives.md).  
  
## Consulte também  
 [Definindo uma macro NMAKE](../build/defining-an-nmake-macro.md)