---
title: _ReturnAddress
ms.date: 11/04/2016
f1_keywords:
- _ReturnAddress
helpviewer_keywords:
- _ReturnAddress intrinsic
- ReturnAddress intrinsic
ms.assetid: 7f4a5811-35e6-4f64-ba7c-21203380eeda
ms.openlocfilehash: e5013b20f9e7ed0349d940d9be61cc1b4afc95d4
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59041131"
---
# <a name="returnaddress"></a>_ReturnAddress

## <a name="microsoft-specific"></a>Específico da Microsoft

O `_ReturnAddress` intrínseco fornece o endereço da instrução da função de chamada que será executada depois que o controle retorna ao chamador.

Crie os seguintes programas e em passo no depurador. Conforme você percorre o programa, anote o endereço retornado do `_ReturnAddress`. Em seguida, imediatamente depois do retorno da função em que `_ReturnAddress` foi usado, abra o [como: Use a janela de desmontagem](/visualstudio/debugger/how-to-use-the-disassembly-window) e observe que o endereço da próxima instrução a ser executada corresponde ao endereço retornado do `_ReturnAddress`.

Otimizações como inlining pode afetar o endereço de retorno. Por exemplo, se o programa de exemplo abaixo é compilado com [/Ob1](../build/reference/ob-inline-function-expansion.md), `inline_func` será embutida para a função de chamada, `main`. Portanto, as chamadas para `_ReturnAddress` partir `inline_func` e `main` cada produzirá o mesmo valor.

Quando `_ReturnAddress` é usado em um programa compilado com [/clr](../build/reference/clr-common-language-runtime-compilation.md), a função que contém o `_ReturnAddress` chamada será compilada como uma função nativa. Quando uma função é compilado como gerenciado chama a função contendo `_ReturnAddress`, `_ReturnAddress` podem não se comportar conforme o esperado.

## <a name="requirements"></a>Requisitos

**Arquivo de cabeçalho** \<intrin. h >

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

**FIM de Específico da Microsoft**

## <a name="see-also"></a>Consulte também

[_AddressOfReturnAddress](../intrinsics/addressofreturnaddress.md)<br/>
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)