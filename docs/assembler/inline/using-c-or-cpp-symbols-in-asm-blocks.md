---
title: "Usando símbolos de C ou C++ em blocos ASM | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- __asm keyword [C++], syntax
- symbols, in __asm blocks
- Visual C, symbols in __asm blocks
- __asm keyword [C++], C/C++ elements in
- Visual C++, in __asm blocks
ms.assetid: 0758ffdc-dfe9-41c8-a5e1-fd395bcac328
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b6a39b747c8c576d148bafff19a664a95fcb43e9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-c-or-c-symbols-in-asm-blocks"></a>Usando símbolos de C ou C++ em blocos __asm
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Um `__asm` bloco pode se referir a qualquer símbolo de C ou C++ no escopo em que o bloco é exibido. (Símbolos de C e C++ são nomes de variáveis, nomes de função e rótulos; que seja, nomes que não são constantes simbólicas ou `enum` membros. Você não pode chamar o membro de C++ funções.)  
  
 Algumas restrições se aplicam ao uso de símbolos de C e C++:  
  
-   Cada instrução de linguagem assembly pode conter apenas um C ou símbolo de C++. Vários símbolos podem aparecer na instrução de assembly apenas com **comprimento**, **tipo**, e **tamanho** expressões.  
  
-   As funções referenciadas em um `__asm` bloco deve ser declarado anteriormente no programa (prototipado). Caso contrário, o compilador não pode distinguir entre os nomes de função e rótulos no `__asm` bloco.  
  
-   Um `__asm` bloco não é possível usar qualquer símbolos de C ou C++ com a mesma ortografia como palavras MASM reservado (independentemente do caso). Palavras MASM reservada incluem nomes de instrução como **PUSH** e registrar nomes como SI.  
  
-   Marcas de união e estrutura não são reconhecidas na `__asm` blocos.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Usando C ou C++ em blocos __asm](../../assembler/inline/using-c-or-cpp-in-asm-blocks.md)