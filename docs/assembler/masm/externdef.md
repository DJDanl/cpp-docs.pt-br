---
title: "EXTERNDEF | Microsoft Docs"
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
  - "EXTERNDEF"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "EXTERNDEF directive"
ms.assetid: 95a10de6-c345-4428-a2f2-90f7d411dc86
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# EXTERNDEF
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define um ou mais variáveis externas, rótulos ou símbolos chamados  *nome* cujo tipo é `type`.  
  
## Sintaxe  
  
```  
  
EXTERNDEF [[langtype]] name:type [[, [[langtype]] name:type]]...  
```  
  
## Comentários  
 Se  *nome* é definido no módulo, ele é tratado como  [pública](../Topic/PUBLIC%20\(MASM\).md).  Se  *nome* é referenciado no módulo, ele é tratado como  [EXTERN](../../assembler/masm/extern-masm.md).  Se  *nome* não é referenciado, ele será ignorado.  O `type` pode ser  [ABS](../../assembler/masm/operator-abs.md), que importa  *nome* como uma constante.  Normalmente usada em incluir arquivos.  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)