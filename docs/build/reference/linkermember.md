---
title: "/LINKERMEMBER | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/linkermember"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /LINKERMEMBER (dumpbin)"
  - "opção dumpbin LINKERMEMBER"
  - "opção dumpbin -LINKERMEMBER"
ms.assetid: c96868c1-d70e-4651-ae36-c55b58b16406
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /LINKERMEMBER
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/LINKERMEMBER[:{1|2}]  
```  
  
## Comentários  
 Esta opção exibe os símbolos públicos definidos em uma biblioteca.  Especifique o argumento 1 para exibir símbolos na ordem do objeto, junto com os deslocamentos.  Especifique o argumento 2 para exibir deslocamentos e números de índice de objetos, e listar os símbolos em ordem alfabética, junto com o índice do objeto para cada um.  Para obter as duas saídas, especifique \/LINKERMEMBER sem o argumento do número.  
  
 Somente a opção de DUMPBIN de [\/HEADERS](../../build/reference/headers.md) está disponível para uso em arquivos gerados com a opção do compilador de [\/GL](../../build/reference/gl-whole-program-optimization.md) .  
  
## Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)