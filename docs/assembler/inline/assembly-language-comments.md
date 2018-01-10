---
title: "Comentários da linguagem de assembly | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- assembly language [C++], comments
- comments [C++], assembly language
- macros [C++], assembly language
- __asm keyword [C++], instructions
ms.assetid: 0dc10850-77f5-426e-9dab-185ea28e06e4
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ee9ab1975a1146b598d7955d15b8e91a0f396724
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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