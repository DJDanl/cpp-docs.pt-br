---
title: Comentários da linguagem de assembly
ms.date: 08/30/2018
helpviewer_keywords:
- assembly language [C++], comments
- comments [C++], assembly language
- macros [C++], assembly language
- __asm keyword [C++], instructions
ms.assetid: 0dc10850-77f5-426e-9dab-185ea28e06e4
ms.openlocfilehash: fc37658eccd99b61d45aa9a9a7a2675ef90eee89
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62167238"
---
# <a name="assembly-language-comments"></a>Comentários da linguagem de assembly

**Seção específica da Microsoft**

Instruções em um `__asm` bloco pode usar comentários da linguagem de assembly:

```cpp
__asm mov ax, offset buff ; Load address of buff
```

Como macros C expandem em uma única linha lógica, evite o uso de comentários da linguagem de assembly em macros. (Consulte [definindo blocos ASM como Macros C](../../assembler/inline/defining-asm-blocks-as-c-macros.md).) Uma `__asm` bloco também pode conter comentários de estilo C; para obter mais informações, consulte [usando C ou C++ em blocos ASM](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>