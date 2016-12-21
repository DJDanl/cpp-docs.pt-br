---
title: "Aviso do compilador (n&#237;vel 4) C4702 | Microsoft Docs"
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
  - "C4702"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4702"
ms.assetid: d8198c1e-8762-42a6-9e6b-cb568b7a1686
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 4) C4702
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

código inacessível  
  
 Esse aviso é o resultado do trabalho de conformidade do compilador que foi feito para Visual Studio .NET 2003:. código inacessível.  Quando o compilador \(back\-end\) detecta o código inacessível, gerará C4702, nível 4 que a direita.  
  
 Para o código que é válido em versões do Visual Studio .NET. 2003 e do Visual Studio .NET do Visual C\+\+, remova o código inacessível ou assegure\-o que todo o código\-fonte é possível acessá\-lo por um determinado fluxo de execução.  
  
## Exemplo  
 O exemplo a seguir produz C4702.  
  
```  
// C4702.cpp  
// compile with: /W4  
#include <stdio.h>  
  
int main() {  
   return 1;  
   printf_s("I won't print.\n");   // C4702 unreachable  
}  
```  
  
## Exemplo  
 Ao criar com **\/GX**, **\/EHc**, **\/EHsc**, ou **\/EHac** e as funções extern C, o código podem se tornar inacessíveis porque as funções extern de C que 2.0 são assumidas para não lançar, assim o bloco de captura não é possível acessá\-lo.  Se você achar que esse aviso não é válido porque uma função é possível lançar, compile com **\/EHa** ou **\/EHs**, dependendo da exceção gerada.  
  
 Para obter mais informações, consulte [\/EH \(modelo de tratamento de exceções\)](../../build/reference/eh-exception-handling-model.md) para obter mais informações.  
  
 O exemplo a seguir produz C4702.  
  
```  
// C4702b.cpp  
// compile with: /W4 /EHsc  
#include <iostream>  
  
using namespace std;  
extern "C" __declspec(dllexport) void Function2(){}  
  
int main() {  
   try {  
      Function2();  
   }  
   catch (...) {  
      cout << "Exp: Function2!" << endl;   // C4702  
   }  
}  
```