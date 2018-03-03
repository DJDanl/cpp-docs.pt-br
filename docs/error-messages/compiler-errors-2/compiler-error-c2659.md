---
title: C2659 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2659
dev_langs:
- C++
helpviewer_keywords:
- C2659
ms.assetid: b0883600-4d27-4ca7-a931-8ca6bd48654d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5c69af55d7a5fd61508505bd96091ffcbed41c5a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2659"></a>C2659 de erro do compilador
'operador' : função como operando esquerdo  
  
 Uma função estava no lado esquerdo do operador especificado. O motivo mais comum para esse erro é que o compilador analisou o identificador no lado esquerdo do operador como função quando o desenvolvedor pretendia que ele fosse uma variável. Para obter mais informações, consulte Wikipedia artigo [análise mais irritantes](http://en.wikipedia.org/wiki/Most_vexing_parse). Este exemplo mostra uma declaração de função e uma definição de variável a são facilmente confundidas:  
  
```  
// C2659a.cpp  
// Compile using: cl /W4 /EHsc C2659a.cpp  
#include <string>  
using namespace std;  
  
int main()   
{  
   string string1(); // string1 is a function returning string  
   string string2{}; // string2 is a string initialized to empty   
  
   string1 = "String 1"; // C2659  
   string2 = "String 2";  
}  
```  
  
 Para resolver esse problema, altere a declaração do identificador de modo que não ela não seja analisada como uma declaração de função.  
  
 O erro C2659 também pode ocorrer quando a função tem um tipo que não pode ser usado na expressão no lado esquerdo do operador especificado. Este exemplo gera C2659 quando o código atribui um ponteiro de função para uma função:  
  
```  
// C2659b.cpp  
// Compile using: cl /W4 /EHsc C2659b.cpp  
int func0(void) { return 42; }  
int (*func1)(void);  
  
int main()  
{  
   func1 = func0;  
   func0 = func1; // C2659  
}  
```