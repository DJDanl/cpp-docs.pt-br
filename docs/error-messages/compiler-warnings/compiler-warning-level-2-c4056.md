---
title: "Aviso do compilador (n&#237;vel 2) C4056 | Microsoft Docs"
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
  - "C4056"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4056"
ms.assetid: a3c3a9b8-ec30-452d-96cb-3694adcce789
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 2) C4056
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

estouro aritmético na constante de ponto flutuante  
  
 A constante de aritmética de ponto flutuante gerencie um resultado que excede o valor máximo permitido.  
  
 Esse aviso pode ser causado por otimizações de compilador executadas durante a aritmética constante.  Você pode ignorar com segurança esse aviso se parte quando você desativar a otimização[\/Od](../../build/reference/od-disable-debug.md)\(\).  
  
 O seguinte exemplo gera C4056:  
  
```  
// C4056.cpp  
// compile with: /W2 /LD  
#pragma warning (default : 4056)  
float fp_val = 1.0e300 * 1.0e300;   // C4056  
```