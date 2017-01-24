---
title: "Uso da pilha | Microsoft Docs"
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
ms.assetid: 383f0072-0438-489f-8829-cca89582408c
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Uso da pilha
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Qualquer memória além de endereço atual de RSP é considerada volátil: O sistema operacional, ou um depurador, podem substituir essa memória durante uma sessão de depuração do usuário, ou um manipulador de interrupção.  Assim, RSP deve sempre ser definido antes de tentar ler ou gravar valores em um quadro de pilha.  
  
 Esta seção discute a alocação de espaço de pilha para variáveis locais e o intrínsecos de **alloca** .  
  
-   [Alocação de pilha](../build/stack-allocation.md)  
  
-   [Compilação da área de pilha do parâmetro dinâmico](../Topic/Dynamic%20Parameter%20Stack%20Area%20Construction.md)  
  
-   [Tipos de função](../build/function-types.md)  
  
-   [alinhamento de malloc](../build/malloc-alignment.md)  
  
-   [alloca](../build/alloca.md)  
  
## Consulte também  
 [Convenções de software x64](../build/x64-software-conventions.md)