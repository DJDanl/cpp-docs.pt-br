---
title: Comentários da linguagem de assembly | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 048635a874db604f872b4fa87d72bd06d0455438
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="assembly-language-comments"></a>Comentários da linguagem de assembly
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Instruções em um `__asm` bloco pode usar comentários da linguagem de assembly:  
  
```  
__asm mov ax, offset buff ; Load address of buff  
```  
  
 Como macros C expandem para uma única linha lógica, evite usar comentários da linguagem de assembly em macros. (Consulte [definindo blocos ASM como Macros C](../../assembler/inline/defining-asm-blocks-as-c-macros.md).) Um `__asm` blocos também podem conter comentários de estilo C; para obter mais informações, consulte [usando C ou C++ em blocos ASM](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md).  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)