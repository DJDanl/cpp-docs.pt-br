---
title: Comentários da linguagem de assembly | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- assembly language [C++], comments
- comments [C++], assembly language
- macros [C++], assembly language
- __asm keyword [C++], instructions
ms.assetid: 0dc10850-77f5-426e-9dab-185ea28e06e4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 02f4c493bac5c2a066dc0b24e2a566d49345288d
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43683320"
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