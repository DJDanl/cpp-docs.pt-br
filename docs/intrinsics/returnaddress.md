---
title: _ReturnAddress
ms.date: 09/02/2019
f1_keywords:
- _ReturnAddress
helpviewer_keywords:
- _ReturnAddress intrinsic
- ReturnAddress intrinsic
ms.assetid: 7f4a5811-35e6-4f64-ba7c-21203380eeda
ms.openlocfilehash: 2a830ff1e8a2c9551dec52cf10a3d5cf126bde3b
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218050"
---
# <a name="_returnaddress"></a>_ReturnAddress

**Seção específica da Microsoft**

O `_ReturnAddress` intrínseco fornece o endereço da instrução na função de chamada que será executada após o controle retornar ao chamador.

Compile o programa a seguir e percorra-o no depurador. Ao percorrer o programa, observe o endereço que é retornado de `_ReturnAddress`. Em seguida, imediatamente após retornar da função em `_ReturnAddress` que foi usado, abra [o como: Use a janela](/visualstudio/debugger/how-to-use-the-disassembly-window) de desmontagem e observe que o endereço da próxima instrução a ser executada corresponde ao endereço retornado de `_ReturnAddress`.

Otimizações como inlinear podem afetar o endereço de retorno. Por exemplo, se o programa de exemplo abaixo for compilado com [/Ob1](../build/reference/ob-inline-function-expansion.md), `inline_func` será embutido na função de chamada, `main`. Portanto, as chamadas para `_ReturnAddress` de `inline_func` e `main` serão produzidas com o mesmo valor.

Quando `_ReturnAddress` é usado em um programa compilado com [/CLR](../build/reference/clr-common-language-runtime-compilation.md), a função que contém `_ReturnAddress` a chamada será compilada como uma função nativa. Quando uma função compilada como chamadas gerenciadas para a `_ReturnAddress`função `_ReturnAddress` que contém o, pode não se comportar conforme o esperado.

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho** \<> intrin. h

## <a name="example"></a>Exemplo

```cpp
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

[_AddressOfReturnAddress](../intrinsics/addressofreturnaddress.md)\
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[Palavras-chave](../cpp/keywords-cpp.md)
