---
title: "Erro do Compilador C2085 | Microsoft Docs"
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
  - "C2085"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2085"
ms.assetid: 0a86785c-8e6f-481b-8c7b-412220c1950d
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2085
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: na lista de parâmetro formal  
  
 O identificador foi declarado em uma definição de função mas não na lista de parâmetro formal. \(ANSI C somente 2.0\)  
  
 O seguinte exemplo gera C2085:  
  
```  
// C2085.c  
void func1( void )  
int main( void ) {}   // C2085  
```  
  
 Solução possível:  
  
```  
// C2085b.c  
void func1( void );  
int main( void ) {}  
```  
  
 Com os ausentes de ponto\-e\-vírgula, os aspectos de `func1()` funciona como uma definição de função, não um protótipo, portanto `main` é definida dentro de `func1()`, gerando o erro C2085 para o identificador `main`.