---
title: "Aviso do compilador (n&#237;vel 1) C4005 | Microsoft Docs"
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
  - "C4005"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4005"
ms.assetid: 7f2dc79a-9fcb-4d5b-be61-120d9cb487ad
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4005
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“identificador”: redefinição macro  
  
 O identificador macro é definido duas vezes.  O compilador usa a segunda definição macro.  
  
### Para corrigir verificando as seguintes causas possíveis  
  
1.  Definindo uma macro na linha de comando e em código com uma política de `#define` .  
  
2.  Macros importados do incluem arquivos.  
  
### Para corrigir usando as seguintes soluções possíveis  
  
1.  Remover uma das definições.  
  
2.  Use uma política de [\#undef](../../preprocessor/hash-undef-directive-c-cpp.md) antes da segunda definição.  
  
 O seguinte exemplo gera C4005:  
  
```  
// C4005.cpp  
// compile with: /W1 /EHsc  
#include <iostream>  
using namespace std;  
  
#define TEST "test1"  
#define TEST "test2"   // C4005 delete or rename to resolve the warning  
  
int main() {  
   cout << TEST << endl;  
}  
```