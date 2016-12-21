---
title: "Erro do Compilador C2809 | Microsoft Docs"
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
  - "C2809"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2809"
ms.assetid: ce796b8e-1a8c-4074-995d-1ad09afd0e93
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2809
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o operador operador” não tem nenhum parâmetro formal  
  
 O operador não tiver parâmetros necessários.  
  
 O seguinte exemplo gera C2809:  
  
```  
// C2809.cpp  
// compile with: /c  
class A{};  
int operator+ ();   // C2809  
int operator+ (A);   // OK  
```