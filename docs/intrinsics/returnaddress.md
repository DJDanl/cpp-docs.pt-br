---
title: "_ReturnAddress | Microsoft Docs"
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
  - "_ReturnAddress"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_ReturnAddress intrínseco"
  - "ReturnAddress intrínseco"
ms.assetid: 7f4a5811-35e6-4f64-ba7c-21203380eeda
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _ReturnAddress
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específicos do Microsoft  
 O `_ReturnAddress` intrínseca fornece o endereço da instrução na função de chamada que será executada após o controle retorna para o chamador.  
  
 Crie o seguinte programa e em passo no depurador.  Como depurar o programa, anote o endereço retornado de `_ReturnAddress`.  Então, imediatamente após retornar da função onde `_ReturnAddress` foi usado, abra o [Como usar a janela Desmontagem](../Topic/How%20to:%20Use%20the%20Disassembly%20Window.md) e observe que o endereço da próxima instrução a ser executada corresponde o endereço retornado de `_ReturnAddress`.  
  
 Otimizações como inlining pode afetar o endereço de retorno.  Por exemplo, se o programa de exemplo abaixo é compilado com  [\/Ob1](../build/reference/ob-inline-function-expansion.md), `inline_func` será embutido na função de chamada, `main`.  Portanto, as chamadas para `_ReturnAddress` de `inline_func` e `main` cada produzirá o mesmo valor.  
  
 Quando `_ReturnAddress` é usado em um programa compilado com  [\/clr](../build/reference/clr-common-language-runtime-compilation.md), a função que contém o `_ReturnAddress` chamada será compilada como uma função nativa.  Quando uma função é compilado como gerenciado chamadas para a função que contém `_ReturnAddress`, `_ReturnAddress` pode não se comportar conforme o esperado.  
  
## Requisitos  
 **Arquivo de cabeçalho** \<intrin.h\>  
  
## Exemplo  
  
```  
// compiler_intrinsics__ReturnAddress.cpp  
#include <stdio.h>  
#include <intrin.h>  
  
#pragma intrinsic(_ReturnAddress)  
  
__declspec(noinline)  
void noinline_func(void)  
{  
   printf("Return address from %s: %p\n", __FUNCTION__, _ReturnAddress());  
}  
  
__forceinline  
void inline_func(void)  
{  
   printf("Return address from %s: %p\n", __FUNCTION__, _ReturnAddress());  
}  
  
int main(void)  
{  
   noinline_func();   
   inline_func();  
   printf("Return address from %s: %p\n", __FUNCTION__, _ReturnAddress());  
  
   return 0;  
}  
```  
  
## END Microsoft específicos  
  
## Consulte também  
 [\_AddressOfReturnAddress](../intrinsics/addressofreturnaddress.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)