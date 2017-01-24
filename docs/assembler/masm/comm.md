---
title: "COMM | Microsoft Docs"
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
  - "COMM"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "COMM directive"
ms.assetid: a23548c4-ad04-41fa-91da-945f228de742
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# COMM
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria uma variável communal com os atributos especificados na `definition`.  
  
## Sintaxe  
  
```  
  
COMM definition [[, definition]] ...  
```  
  
## Comentários  
 Cada `definition` tem a seguinte forma:  
  
 \[*langtype*\]\] \[**NEAR** &#124; **FAR**\]*label***:**`type`\[**:***count*\]  
  
 O  *rótulo* é o nome da variável.  O `type` pode ser qualquer especificador de tipo \([bytes](../../assembler/masm/byte-masm.md),  [WORD](../../assembler/masm/word.md)e assim por diante\) ou um inteiro especificando o número de bytes.  O  *contagem* Especifica o número de objetos de dados \(um é o padrão\).  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)