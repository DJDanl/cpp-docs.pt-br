---
title: "Erro do Compilador C3199 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C3199"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3199"
ms.assetid: e7a478d3-115a-40a3-991b-c7454fd2e28e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3199
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

uso inválido de pragmas de ponto flutuante: as exceções não têm suporte no modo não preciso  
  
 O pragma de [float\_control](../Topic/float_control.md) foi usada para especificar o modelo de ponto flutuante de exceção em [\/fp](../../build/reference/fp-specify-floating-point-behavior.md) que define a não ser **\/fp:precise**.  
  
 O seguinte exemplo gera C3199:  
  
```  
// C3199.cpp  
// compile with: /fp:fast  
#pragma float_control(except, on)   // C3199  
```