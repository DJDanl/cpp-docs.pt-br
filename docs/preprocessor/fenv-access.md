---
title: "fenv_access | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc-pragma.fenv_access"
  - "fenv_access_CPP"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "fenv_access (pragma)"
  - "pragmas, fenv_access"
ms.assetid: 2ccea292-0ae4-42ce-9c67-cc189299857b
caps.latest.revision: 12
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fenv_access
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Desabilita \(ativa\) ou habilita \(desativa\) otimizações que poderiam alterar testes de sinalizadores e alterações de modo.  
  
## Sintaxe  
  
```  
#pragma fenv_access [ON | OFF]  
```  
  
## Comentários  
 Por padrão, `fenv_access` é desativado.  
  
 Para obter mais informações sobre o comportamento do ponto flutuante, consulte [\/fp \(especificar comportamento de ponto flutuante\)](../build/reference/fp-specify-floating-point-behavior.md).  
  
 Os tipos de otimizações sujeitos a `fenv_access` são:  
  
-   Eliminação de subexpressão comum global  
  
-   Movimentação de código  
  
-   Dobra de constante  
  
 Outros pragmas de ponto flutuante incluem:  
  
-   [float\_control](../Topic/float_control.md)  
  
-   [fp\_contract](../preprocessor/fp-contract.md)  
  
## Exemplo  
  
```  
// pragma_directive_fenv_access_x86.cpp  
// compile with: /O2  
// processor: x86  
#include <stdio.h>  
#include <float.h>   
#include <errno.h>  
#pragma fenv_access (on)  
  
int main() {  
   double z, b = 0.1, t = 0.1;  
   unsigned int currentControl;  
   errno_t err;  
  
   err = _controlfp_s(&currentControl, _PC_24, _MCW_PC);  
   if (err != 0) {  
      printf_s("The function _controlfp_s failed!\n");  
      return -1;  
   }  
   z = b * t;  
   printf_s ("out=%.15e\n",z);  
}  
```  
  
  **out\=9.999999776482582e\-003**   
## Exemplo  
 O exemplo a seguir é de um compilador gerando arquivos de saída para processadores Itanium.  **\/fp:precise** mantém os resultados intermediários na precisão estendida onde os valores maiores que FLT\_MAX \(3.402823466e\+38F\) podem ser calculados e, como resultado dessa soma, ter o resultado como 1,0, como se tivessem de ser calculados manualmente.  **\/fp:strict** mantém resultados intermediários em sua precisão de origem \(float\) para que a primeira adição gere infinidade, que é mantida em toda a expressão.  
  
```  
// pragma_directive_fenv_access_IPF.cpp  
// compile with: /O2 /fp:precise  
// processor: IPF  
// compiling with /fp:precise prints 1.0F  
// compile with /fp:strict to print infinity  
  
#include <stdio.h>  
float arr[5] = {3.402823465e+38F,   
               3.402823462e+38F,  
               3.402823464e+38F,  
               3.402823463e+38F,  
               1.0F};  
  
int main() {  
   float sum = 0;  
   sum = arr[0] + arr[1] - arr[2] - arr[3] + arr[4];  
   printf_s("%f\n", sum);  
}  
```  
  
  **1.000000**   
## Exemplo  
 Ao comentar `#pragma fenv_access (on)` do exemplo anterior, observe que a saída é diferente porque o compilador faz a avaliação do tempo de compilação, que não usa o modo de controle.  
  
```  
// pragma_directive_fenv_access_2.cpp  
// compile with: /O2  
#include <stdio.h>  
#include <float.h>   
  
int main() {  
   double z, b = 0.1, t = 0.1;  
   unsigned int currentControl;  
   errno_t err;  
  
   err = _controlfp_s(&currentControl, _PC_24, _MCW_PC);  
   if (err != 0) {  
      printf_s("The function _controlfp_s failed!\n");  
      return -1;  
   }  
   z = b * t;  
   printf_s ("out=%.15e\n",z);  
}  
```  
  
  **out\=1.000000000000000e\-002**   
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)