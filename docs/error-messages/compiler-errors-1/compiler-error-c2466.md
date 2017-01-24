---
title: "Erro do Compilador C2466 | Microsoft Docs"
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
  - "C2466"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2466"
ms.assetid: 75b251d1-7d0b-4a86-afca-26adedf74486
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2466
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o não pode alocar uma matriz de tamanho constante 0  
  
 Uma matriz é atribuída ou declarada com tamanho zero.  A expressão constante para o tamanho da matriz deve ser um número inteiro maior que zero.  Uma declaração de matriz com um subscrito zero é válido somente para uma classe, uma estrutura, ou um sindicalista e apenas com extensões da Microsoft \([\/Ze](../../build/reference/za-ze-disable-language-extensions.md)\).  
  
 O seguinte exemplo gera C2466:  
  
```  
// C2466.cpp  
// compile with: /c  
int i[0];   // C2466  
int j[1];   // OK  
char *p;  
```