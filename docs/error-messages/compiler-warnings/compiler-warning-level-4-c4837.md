---
title: "Aviso do compilador (n&#237;vel 4) C4837 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C4837"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4837"
ms.assetid: 9a3c7b6b-ffe4-443d-96af-43deb80d85b4
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4837
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

trigraph detectado: “?? %c” substituído “por” %c  
  
 O trigraph detectado é substituído por caractere indicado.  
  
 O compilador converte trigraphs antes que qualquer outro processamento é concluído.  Use a sequência de escape de caractere, `\?`, para evitar a interpretação errônea de uma sequência de caracteres semelhante a um trigraph.  Para obter mais informações sobre os trigraphs, consulte [Trígrafos](../Topic/Trigraphs.md).  Para obter mais informações sobre as sequências de escape, consulte [Sequências de escape](../../c-language/escape-sequences.md).  
  
 C4837 é desativada por padrão.  Consulte [Avisos de compilador desativados por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para maiores informações.  
  
### Para corrigir este erro  
  
1.  Use a sequência de escape de caractere, `\?`, em vez de um “?” caracteres no código\-fonte.  
  
## Consulte também  
 [Trígrafos](../Topic/Trigraphs.md)   
 [Sequências de escape](../../c-language/escape-sequences.md)   
 [Avisos de compilador desativados por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md)