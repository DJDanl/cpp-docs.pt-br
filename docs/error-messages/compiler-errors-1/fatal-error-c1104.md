---
title: "Erro fatal C1104 | Microsoft Docs"
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
  - "C1104"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1104"
ms.assetid: 45bd85c4-77d3-4d3c-b167-49c563aefb4d
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1104
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Erro fatal ID da biblioteca de importação: 'mensagem'  
  
 O compilador detectou um problema durante a importação de uma biblioteca de tipos.  Por exemplo, você não pode especificar uma biblioteca de tipos com ID da biblioteca e também especificar `no_registry`.  
  
 Para obter mais informações, consulte [Diretiva \#import](../Topic/%23import%20Directive%20\(C++\).md).  
  
 O exemplo a seguir gerará C1104:  
  
```  
// C1104.cpp #import "libid:11111111.1111.1111.1111.111111111111" version("4.0") lcid("9") no_registry auto_search   // C1104  
```