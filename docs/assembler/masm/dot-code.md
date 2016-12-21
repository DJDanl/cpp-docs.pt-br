---
title: ".CODE | Microsoft Docs"
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
  - ".CODE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - ".CODE directive"
ms.assetid: 2b8c882c-c0d2-4fa3-8335-e6b12717a4f4
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# .CODE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando usado com  [.MODELO](../../assembler/masm/dot-model.md), indica o início de um segmento de código.  
  
## Sintaxe  
  
```  
.CODE [[name]]  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`name`|Parâmetro opcional que especifica o nome do segmento de código.  O nome padrão é \_TEXT para minúsculo, pequeno, compact e tela plana  [modelos de](../../assembler/masm/dot-model.md).  O nome padrão é  *modulename*\_TEXT para outros modelos.|  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)   
 [.DATA](../../assembler/masm/dot-data.md)