---
title: "Blocos | Microsoft Docs"
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
  - "C"
helpviewer_keywords: 
  - "blocos"
  - "instruções compostas"
  - "definições de função, blocos no código"
  - "instruções, composto"
ms.assetid: be231a92-c712-464e-ae25-a4becb20f7f5
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Blocos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma sequência de declarações, definições e instruções entre chaves \(**{ }**\) é denominada "bloco". Existem dois tipos de blocos em C.  A "instrução composta", uma instrução composta por uma ou mais instruções \(consulte [A instrução composta](../c-language/compound-statement-c.md)\), é um tipo de bloco.  O outro, a "definição de função", consiste em uma instrução composta \(o corpo da função\) com o "cabeçalho" associado à função \(o nome da função, o tipo de retorno e os parâmetros, formais\).  Um bloco dentro de outros blocos é chamado de "aninhado".  
  
 Observe que, ainda que todas as instruções compostas estejam entre chaves, nem tudo que está entre chaves constitui uma instrução composta.  Por exemplo, embora as especificações de matriz, estrutura ou dos elementos de enumeração possam aparecer entre chaves, elas não são instruções compostas.  
  
## Consulte também  
 [Arquivos e programas de origem](../c-language/source-files-and-source-programs.md)