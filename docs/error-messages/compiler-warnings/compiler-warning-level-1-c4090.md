---
title: "Aviso do compilador (n&#237;vel 1) C4090 | Microsoft Docs"
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
  - "C4090"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4090"
ms.assetid: baad469d-23d4-45aa-ad9c-305b32d61e9a
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4090
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“operação”: qualificadores diferentes de “modificador”  
  
 Uma variável usada em uma operação é definido com um modificador especificado que impede que seja alterada sem detecção pelo compilador.  A expressão é compilada sem modificação.  
  
 Esse aviso pode ser causado quando um ponteiro para um item de **const** ou de `volatile` é atribuído a um ponteiro não declarado como apontando para **const** ou a `volatile`.  
  
 Esse aviso é emitido para programas de 2.0 c.  Em um programa C\/C\+\+ criando, o compilador emite um erro: [C2440](../../error-messages/compiler-errors-1/compiler-error-c2440.md).  
  
 O seguinte exemplo gera C4090:  
  
```  
// C4090.c  
// compile with: /W1  
int *volatile *p;  
int *const *q;  
int **r;  
  
int main() {  
   p = q;   // C4090  
   p = r;  
   q = p;   // C4090  
   q = r;  
   r = p;   // C4090  
   r = q;   // C4090  
}  
```