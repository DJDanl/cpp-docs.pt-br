---
title: "Erro do Compilador C3198 | Microsoft Docs"
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
  - "C3198"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3198"
ms.assetid: ec4ecf61-0067-4aa4-b443-a91013a1e59d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3198
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

uso inválido de pragmas de ponto flutuante: o pragma de fenv\_access funciona apenas no modo preciso  
  
 o pragma de[fenv\_access](../../preprocessor/fenv-access.md) foi usado em [\/fp](../../build/reference/fp-specify-floating-point-behavior.md) que define a não ser **\/fp:precise**.  
  
 O seguinte exemplo gera C3198:  
  
```  
// C3198.cpp  
// compile with: /fp:fast  
#pragma fenv_access(on)   // C3198  
```