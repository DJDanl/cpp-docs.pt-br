---
title: "Erro do Compilador C2496 | Microsoft Docs"
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
  - "C2496"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2496"
ms.assetid: 9a25237d-5bbb-4112-98f3-29cd99d3f89f
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2496
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: “selectany” só pode ser aplicado aos itens de dados com vinculação externo  
  
 O atributo de [selectany](../../cpp/selectany.md) pode ser aplicado somente aos itens de dados externa visíveis e globais.  
  
 O seguinte exemplo gera C2496:  
  
```  
// C2496.cpp  
// compile with: /c  
__declspec(selectany) int x1 = 1;  
const __declspec(selectany) int x2 = 2;   // C2496  
static __declspec(selectany) int x6 = 6;   // C2496  
  
extern const __declspec(selectany) int x3 = 3;  
  
__declspec(selectany) int x4;  
  
// dynamic initialization of x5  
int f();  
__declspec(selectany) int x5 = f();  
  
extern const int x7;  
// OK - redeclaration of x7 that is extern  
const __declspec(selectany) int x7 = 7;  
```