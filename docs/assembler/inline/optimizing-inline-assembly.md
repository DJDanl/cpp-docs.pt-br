---
title: "Otimizando assembly embutido | Microsoft Docs"
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
  - "Palavra-chave __asm [C++], otimizando"
  - "assembly embutido, otimizando"
  - "otimização, assembly embutido"
  - "otimizando o desempenho, assembly embutido"
  - "armazenamento, otimizando em assembly embutido"
ms.assetid: 52a7ec83-9782-4d96-94c1-53bb2ac9e8c8
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Otimizando assembly embutido
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 A presença de um bloco de `__asm` em uma função afeta a otimização de várias maneiras.  Primeiro, o compilador não tenta otimizar o próprio bloco de `__asm` .  O qual você grava na linguagem assembly é exatamente o que você obtém.  Segundo, a presença de afeta de um bloco de `__asm` registra o armazenamento variável.  O compilador impede enregistering variáveis por meio de um bloco de `__asm` se o conteúdo do registro seriam modificados pelo bloco de `__asm` .  Finalmente, qualquer outra com otimizações que serão afetados pela inclusão de linguagem assembly em uma função.  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)