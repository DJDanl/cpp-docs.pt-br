---
title: debugbreak | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- __debugbreak_cpp
- __debugbreak
dev_langs:
- C++
helpviewer_keywords:
- breakpoints, __debugbreak intrinsic
- __debugbreak intrinsic
ms.assetid: 1d1e1c0c-891a-4613-ae4b-d790094ba830
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f2ba9322f4fe94c1c857b0494dc79b417e5d65d8
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46433870"
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
|`__debugbreak`|x86, ARM, x64|\<intrin.h>|

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

Essa rotina só está disponível como função intrínseca.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)