---
title: "Erro do Compilador C2435 | Microsoft Docs"
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
  - "C2435"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2435"
ms.assetid: be6aa8f8-579b-42ea-bdd8-2d01393646ad
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2435
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

var “”: a inicialização dinâmico requer o CRT gerenciado, não pode criar com \/clr:safe  
  
 A inicialização da variável global de domínio do aplicativo requer o CRT compilado com `/clr:pure`, que não gerencia uma imagem verificável.  
  
 Para obter mais informações, consulte [appdomain](../Topic/appdomain.md) e [processo](../../cpp/process.md).  
  
 O seguinte exemplo gera C2435:  
  
```  
// C2435.cpp  
// compile with: /clr:safe /c  
int globalvar = 0;   // C2435  
  
__declspec(process)  
int globalvar2 = 0;  
```