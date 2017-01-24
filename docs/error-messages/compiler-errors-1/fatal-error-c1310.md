---
title: "Erro fatal C1310 | Microsoft Docs"
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
  - "C1310"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1310"
ms.assetid: ac48aa51-8023-42fe-b844-3f8bf228fbef
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1310
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

otimizações de guiada por perfil não estão disponíveis com o OpenMP  
  
 Você não poderá vincular com [\/LTCG:PGI](../../build/reference/ltcg-link-time-code-generation.md) qualquer módulo que foi compilado com [\/GL](../../build/reference/gl-whole-program-optimization.md).  
  
 O exemplo a seguir gera C1310:  
  
```  
// C1310.cpp // compile with: /openmp /GL /link /LTCG:PGI // C1310 expected int main() { int i = 0, j = 10; #pragma omp parallel { #pragma omp for for (i = 0; i < 0; i++) --j; } }  
```