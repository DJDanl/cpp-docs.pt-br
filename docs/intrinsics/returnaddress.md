---
title: _ReturnAddress | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: _ReturnAddress
dev_langs: C++
helpviewer_keywords:
- _ReturnAddress intrinsic
- ReturnAddress intrinsic
ms.assetid: 7f4a5811-35e6-4f64-ba7c-21203380eeda
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d207fcba6846d0a5e599d6273f5b35bb554bda40
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="returnaddress"></a>_ReturnAddress
## <a name="microsoft-specific"></a>Específico da Microsoft  
 O `_ReturnAddress` intrínseco fornece o endereço da instrução na função de chamada que será executada depois que o controle retorna ao chamador.  
  
 Crie o seguinte programa e passar por no depurador. Conforme você avança através do programa, anote o endereço que é retornado de `_ReturnAddress`. Em seguida, imediatamente depois do retorno da função onde `_ReturnAddress` foi usado, abra o [como: usar a janela de desmontagem](/visualstudio/debugger/how-to-use-the-disassembly-window) e observe que o endereço da próxima instrução a ser executada corresponde ao endereço retornado de `_ReturnAddress`.  
  
 Otimizações como inlining pode afetar o endereço de retorno. Por exemplo, se o programa de exemplo a seguir é compilado com [/Ob1](../build/reference/ob-inline-function-expansion.md), `inline_func` será embutida para a função chamada, `main`. Portanto, as chamadas para `_ReturnAddress` de `inline_func` e `main` cada produzirá o mesmo valor.  
  
 Quando `_ReturnAddress` é usado em um programa compilado com [/clr](../build/reference/clr-common-language-runtime-compilation.md), a função que contém o `_ReturnAddress` chamada será compilada como uma função nativa. Quando uma função é compilado como gerenciado chama a função que contém `_ReturnAddress`, `_ReturnAddress` podem não se comportar conforme o esperado.  
  
## <a name="requirements"></a>Requisitos  
 **Arquivo de cabeçalho** \<intrin.h >  
  
## <a name="example"></a>Exemplo  
  
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
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [_AddressOfReturnAddress](../intrinsics/addressofreturnaddress.md)   
 [Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)