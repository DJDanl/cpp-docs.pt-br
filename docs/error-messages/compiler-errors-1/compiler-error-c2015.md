---
title: "Erro do Compilador C2015 | Microsoft Docs"
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
  - "C2015"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2015"
ms.assetid: 8f40af0a-3a5a-4d6a-8ed7-125966e6bfed
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2015
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

muitos caracteres da constante  
  
 Uma constante de caractere contém mais de dois caracteres.  O limite é um caractere para constantes de caractere padrão e dois caracteres para constantes de caracteres longas.  
  
 Uma sequência de escape, como \\ t, é convertida em um caractere único.  
  
## Exemplo  
 O seguinte exemplo gera C2015:  
  
```  
// C2015.cpp  
// compile with: /c  
  
char test1 = 'error';   // C2015  
char test2 = 'e';   // OK  
```  
  
## Exemplo  
 C2015 também pode ocorrer ao usar uma extensão da Microsoft, constantes de caractere convertidos em inteiros.  O seguinte exemplo gera C2015:  
  
```  
// C2015b.cpp  
#include <stdio.h>  
  
int main()   
{  
    int a = 'abcde';   // C2015  
  
    int b = 'a';   // 'a' = ascii 0x61  
    printf_s("%x\n", b);  
}  
```