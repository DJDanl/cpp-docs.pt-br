---
title: "Aviso do compilador (n&#237;vel 4) C4668 | Microsoft Docs"
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
  - "C4668"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4668"
ms.assetid: c6585460-bc4a-4a15-9242-4cbfce53c961
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4668
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o símbolo “” não foi definida como uma macro de pré\-processador, substituindo por “0 " para “políticas  
  
 Um símbolo que não foi definido foi usado com uma política de pré\-processador.  O símbolo de será avaliada como false.  Para definir um símbolo, você pode usar [política de \#define](../../preprocessor/hash-define-directive-c-cpp.md) ou a opção do compilador de [\/D](../../build/reference/d-preprocessor-definitions.md) .  
  
 Esse aviso é desativada por padrão.  Consulte [Avisos do compilador que estão por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para obter mais informações.  
  
## Exemplo  
 O seguinte exemplo gera C4668:  
  
```  
// C4668.cpp  
// compile with: /W4  
#include <stdio.h>  
  
#pragma warning (default : 4668)   // turn warning on  
  
int main()   
{  
    #if q   // C4668, q is not defined  
        printf_s("defined");  
    #else  
        printf_s("undefined");  
    #endif  
}  
```