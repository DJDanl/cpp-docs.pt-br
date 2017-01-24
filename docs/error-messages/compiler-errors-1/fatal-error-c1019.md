---
title: "Erro fatal C1019 | Microsoft Docs"
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
  - "C1019"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1019"
ms.assetid: c4f8968b-bc62-4200-b3ca-69d06c163236
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1019
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

inesperado \#else  
  
 A `#else` diretiva aparece fora de um `#if`, `#ifdef`, ou `#ifndef` Construir. Use `#else` apenas dentro de uma dessas construções.  
  
 O exemplo a seguir gera C1019:  
  
```  
// C1019.cpp #else   // C1019 #endif int main() {}  
```  
  
 Resolução possível:  
  
```  
// C1019b.cpp #if 1 #else #endif int main() {}  
```