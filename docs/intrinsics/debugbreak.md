---
title: __debugbreak
ms.date: 11/04/2016
f1_keywords:
- __debugbreak_cpp
- __debugbreak
helpviewer_keywords:
- breakpoints, __debugbreak intrinsic
- __debugbreak intrinsic
ms.assetid: 1d1e1c0c-891a-4613-ae4b-d790094ba830
ms.openlocfilehash: ed75b94e8bf0aca9369c56f23e8ff00ea6953642
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69509504"
---
# <a name="__debugbreak"></a>__debugbreak

**Seção específica da Microsoft**

Cria um ponto de interrupção no código, onde o sistema solicitará que o usuário execute o depurador.

## <a name="syntax"></a>Sintaxe

```
void __debugbreak();
```

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|Cabeçalho|
|---------------|------------------|------------|
|`__debugbreak`|x86, x64, ARM, ARM64|\<intrin.h>|

## <a name="remarks"></a>Comentários

O `__debugbreak` compilador intrínseco, semelhante a [DebugBreak](/windows/win32/api/debugapi/nf-debugapi-debugbreak), é uma maneira do Win32 portátil de causar um ponto de interrupção.

> [!NOTE]
>  Ao compilar com **/CLR**, uma função contendo `__debugbreak` será compilada para MSIL. `asm int 3` faz com que a função seja compilada como nativa. Para obter mais informações, consulte [__asm](../assembler/inline/asm.md).

Por exemplo:

```
main() {
   __debugbreak();
}
```

é similar a:

```
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

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
