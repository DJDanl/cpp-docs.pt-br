---
title: Comentários da linguagem de assembly
ms.date: 08/30/2018
helpviewer_keywords:
- assembly language [C++], comments
- comments [C++], assembly language
- macros [C++], assembly language
- __asm keyword [C++], instructions
ms.assetid: 0dc10850-77f5-426e-9dab-185ea28e06e4
ms.openlocfilehash: a8b2c98c61d58d72e78dbffd4f3b6ed7707d2d7a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169598"
---
# <a name="assembly-language-comments"></a>Comentários da linguagem de assembly

**Seção específica da Microsoft**

As instruções em um bloco de `__asm` podem usar comentários de linguagem de assembly:

```cpp
__asm mov ax, offset buff ; Load address of buff
```

Como as macros C se expandem para uma única linha lógica, evite usar comentários de linguagem de assembly em macros. (Consulte [definindo blocos de __asm como macros C](../../assembler/inline/defining-asm-blocks-as-c-macros.md).) Um bloco de `__asm` também pode conter comentários em estilo C; para obter mais informações, consulte [usando C C++ ou em blocos de __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>
