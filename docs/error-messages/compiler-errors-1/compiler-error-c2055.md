---
title: "Erro do Compilador C2055 | Microsoft Docs"
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
  - "C2055"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2055"
ms.assetid: 6cec79cc-6bec-443f-9897-fbf5452718c7
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2055
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

lista de parâmetro formal prevista, não uma lista de classificação  
  
 Uma definição de função contém uma lista de tipo de parâmetro em vez de uma lista de parâmetro formal.  ANSI C requer parâmetros formais ser chamado a menos que sejam nulos ou um sinal de reticências \(`...`\).  
  
 O seguinte exemplo gera C2055:  
  
```  
// C2055.c  
// compile with: /c  
void func(int, char) {}  // C2055  
void func (int i, char c) {}   // OK  
```