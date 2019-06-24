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
ms.openlocfilehash: 97932dfe0e187a13b72ae5fe70d761224721c3ff
ms.sourcegitcommit: 1acb6755e11379026a96f63facac4d33f4dc47ae
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/21/2019
ms.locfileid: "67314254"
---
# <a name="debugbreak"></a>__debugbreak

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

O `__debugbreak` compilador intrínseco, semelhante ao [DebugBreak](https://msdn.microsoft.com/library/windows/desktop/ms679297.aspx), é uma maneira portátil do Win32 para fazer com que um ponto de interrupção.

> [!NOTE]
>  Ao compilar com **/clr**, uma função contendo `__debugbreak` serão compilados para MSIL. `asm int 3` faz com que a função seja compilada como nativa. Para obter mais informações, consulte [ASM](../assembler/inline/asm.md).

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

Arm64, o `__debugbreak` intrínseco é compilado na instrução `brk #0xF000`.

Essa rotina só está disponível como função intrínseca.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
