---
title: _ReturnAddress | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- _ReturnAddress
dev_langs:
- C++
helpviewer_keywords:
- _ReturnAddress intrinsic
- ReturnAddress intrinsic
ms.assetid: 7f4a5811-35e6-4f64-ba7c-21203380eeda
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0431302ae745a1e4a03da4b3fd660fda7d2cfa72
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33333164"
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