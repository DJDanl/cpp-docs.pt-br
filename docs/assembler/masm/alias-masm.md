---
title: "ALIAS (MASM) | Microsoft Docs"
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
  - "Alias"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ALIAS directive"
ms.assetid: d9725c49-58de-41da-ab01-b06a56cf5cf2
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ALIAS (MASM)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O  **ALIAS** diretiva cria um nome alternativo para uma função.  Isso permite criar vários nomes para uma função ou criar bibliotecas que permitem que o vinculador \(link. exe\) para mapear uma função antiga para uma nova função.  
  
## Sintaxe  
  
```  
  
ALIAS  <  
alias  
> = <  
actual-name  
>  
  
```  
  
#### Parâmetros  
 `actual-name`  
 O nome real da função ou procedimento.  Os colchetes angulares são obrigatórios.  
  
 `alias`  
 O nome do alias ou alternativo.  Os colchetes angulares são obrigatórios.  
  
## Consulte também  
 [Directives Reference](../../assembler/masm/directives-reference.md)