---
title: "MMWORD | Microsoft Docs"
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
  - "MMWORD"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "MMWORD directive"
ms.assetid: b4c5a104-9078-4fb4-afc3-d1e63abe562a
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# MMWORD
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado para os operandos de multimídia de 64 bits com instruções MMX e SSE \(XMM\).  
  
## Sintaxe  
  
```  
MMWORD  
```  
  
## Comentários  
 `MMWORD`é um tipo.  Antes para MMWORD que está sendo adicionado ao MASM, funcionalidade equivalente poderia foram obtida com:  
  
```  
mov mm0, qword ptr [ebx]  
```  
  
 Enquanto as duas instruções funcionam em operandos de 64 bits, `QWORD` é do tipo para números inteiros sem sinal de 64 bits e `MMWORD` é do tipo para um valor de multimídia de 64 bits.  
  
 `MMWORD`serve para representar o mesmo tipo que [\_\_m64](../../cpp/m64.md).  
  
## Exemplo  
  
```  
movq     mm0, mmword ptr [ebx]  
```