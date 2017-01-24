---
title: "Erro do Compilador C2021 | Microsoft Docs"
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
  - "C2021"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2021"
ms.assetid: 064f32e2-3794-48d5-9767-991003dcb36a
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2021
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

valor esperado do expoente, não “caractere”  
  
 O caractere usado como o expoente de uma constante de ponto flutuante não é um número válido.  Certifique\-se de usar um expoente que está no intervalo.  
  
## Exemplo  
 O seguinte exemplo gera C2021:  
  
```  
// C2021.cpp  
float test1=1.175494351E;   // C2021  
```  
  
## Exemplo  
 Solução possível:  
  
```  
// C2021b.cpp  
// compile with: /c  
float test2=1.175494351E8;  
```