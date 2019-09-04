---
title: __debugbreak
ms.date: 09/02/2019
f1_keywords:
- __debugbreak_cpp
- __debugbreak
helpviewer_keywords:
- breakpoints, __debugbreak intrinsic
- __debugbreak intrinsic
ms.assetid: 1d1e1c0c-891a-4613-ae4b-d790094ba830
ms.openlocfilehash: e4cf2c85818a878417c560ddb5a80f8690e60a93
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70217926"
---
# <a name="__debugbreak"></a>__debugbreak

**Seção específica da Microsoft**

Cria um ponto de interrupção no código, onde o sistema solicitará que o usuário execute o depurador.

## <a name="syntax"></a>Sintaxe

```C
void __debugbreak();
```

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|Cabeçalho|
|---------------|------------------|------------|
|`__debugbreak`|x86, x64, ARM, ARM64|\<intrin.h>|

## <a name="remarks"></a>Comentários

O `__debugbreak` compilador intrínseco, semelhante a [DebugBreak](/windows/win32/api/debugapi/nf-debugapi-debugbreak), é uma maneira do Win32 portátil de causar um ponto de interrupção.

> [!NOTE]
> Ao compilar com **/CLR**, uma função contendo `__debugbreak` será compilada para MSIL. `asm int 3` faz com que a função seja compilada como nativa. Para obter mais informações, consulte [__asm](../assembler/inline/asm.md).

Por exemplo:

```C
main() {
   __debugbreak();
}
```

é similar a:

```C
main() {
   __asm {
      int 3
   }
}
```

em computadores x86.

Em ARM64, o `__debugbreak` intrínseco é compilado na instrução. `brk #0xF000`

Essa rotina só está disponível como função intrínseca.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)\
[Palavras-chave](../cpp/keywords-cpp.md)
