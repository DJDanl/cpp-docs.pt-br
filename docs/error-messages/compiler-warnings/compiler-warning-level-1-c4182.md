---
title: "Compilador C4182 de aviso (n&#237;vel 1) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C4182"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4182"
ms.assetid: 8970f3c6-e2dd-407e-b2ec-964360eb8b43
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4182 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

\#include é o nível de aninhamento 'número' profundidade; recursão infinita possíveis  
  
 O compilador ficou sem espaço na pilha devido ao número de aninhada incluem arquivos. Um arquivo de inclusão é aninhado quando ele está incluído em outro arquivo de inclusão.  
  
 Essa mensagem é informativa e precede erro [C1076](../Topic/Fatal%20Error%20C1076.md).