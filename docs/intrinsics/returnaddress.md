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
ms.openlocfilehash: 5c739590e5e208d9f83fa059f191ae80612a0dbd
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46380861"
---
# <a name="returnaddress"></a>_ReturnAddress

## <a name="microsoft-specific"></a>Específico da Microsoft

O `_ReturnAddress` intrínseco fornece o endereço da instrução da função de chamada que será executada depois que o controle retorna ao chamador.

Crie os seguintes programas e em passo no depurador. Conforme você percorre o programa, anote o endereço retornado do `_ReturnAddress`. Em seguida, imediatamente depois do retorno da função em que `_ReturnAddress` foi usado, abra o [como: usar a janela de desmontagem](/visualstudio/debugger/how-to-use-the-disassembly-window) e observe que o endereço da próxima instrução a ser executada corresponde ao endereço retornado do `_ReturnAddress`.

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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[_AddressOfReturnAddress](../intrinsics/addressofreturnaddress.md)<br/>
[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)