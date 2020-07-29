---
title: Comentários da linguagem de assembly
ms.date: 08/30/2018
helpviewer_keywords:
- assembly language [C++], comments
- comments [C++], assembly language
- macros [C++], assembly language
- __asm keyword [C++], instructions
ms.assetid: 0dc10850-77f5-426e-9dab-185ea28e06e4
ms.openlocfilehash: 2e993bd48c7ec801abd440676c80a5bd8f7b42ec
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87192724"
---
# <a name="assembly-language-comments"></a>Comentários da linguagem de assembly

**Específico da Microsoft**

As instruções em um **`__asm`** bloco podem usar comentários de linguagem de assembly:

```cpp
__asm mov ax, offset buff ; Load address of buff
```

Como as macros C se expandem para uma única linha lógica, evite usar comentários de linguagem de assembly em macros. (Consulte [definindo blocos de __asm como macros C](../../assembler/inline/defining-asm-blocks-as-c-macros.md).) Um **`__asm`** bloco também pode conter comentários em estilo C; para obter mais informações, consulte [usando C ou C++ em blocos de __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md).

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Usando o idioma do assembly em blocos de __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>
