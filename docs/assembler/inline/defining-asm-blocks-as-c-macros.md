---
title: Definindo blocos ASM como Macros C | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- macros, __asm blocks
- Visual C, macros
- __asm keyword [C++], as C macros
ms.assetid: 677ba11c-21c8-4609-bba7-cd47312243b0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 69e1e7f2d4b980045a4e8993e39a69fc353a4f39
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32050487"
---
# <a name="defining-asm-blocks-as-c-macros"></a>Definindo blocos __asm como macros do C
**Seção específica da Microsoft**  
  
 Macros C oferecem uma maneira conveniente de inserir o código de assembly em seu código-fonte, mas que eles exigem muito cuidado porque uma macro expande em uma única linha lógica. Para criar macros sem problemas, siga estas regras:  
  
-   Coloque o `__asm` bloquear entre chaves.  
  
-   Coloque o `__asm` palavra-chave na frente de cada instrução de assembly.  
  
-   Use comentários de C de estilo antigo ( `/* comment */`) em vez de comentários de estilo de assembly ( `; comment`) ou comentários C de linha única ( `// comment`).  
  
 Para ilustrar, o exemplo a seguir define uma macro simples:  
  
```  
#define PORTIO __asm      \  
/* Port output */         \  
{                         \  
   __asm mov al, 2        \  
   __asm mov dx, 0xD007   \  
   __asm out dx, al       \  
}  
```  
  
 À primeira vista, os três últimos `__asm` palavras-chave parecerem supérfluas. Eles são necessários, no entanto, porque a macro expande em uma única linha:  
  
```  
__asm /* Port output */ { __asm mov al, 2  __asm mov dx, 0xD007 __asm out dx, al }  
```  
  
 A terceira e quarta `__asm` palavras-chave são necessárias como separadores de instrução. Os separadores de única instrução reconhecidos no `__asm` blocos são o caractere de nova linha e `__asm` palavra-chave. Como um bloco definido como uma macro é uma linha lógica, você deve separar cada instrução com `__asm`.  
  
 As chaves também são essenciais. Se você omiti-los, o compilador pode ser confuso com instruções C ou C++ na mesma linha à direita da invocação de macro. Sem a chave de fechamento, o compilador não pode determinar onde o código de assembly para e ele vê instruções C ou C++ o `__asm` bloco como instruções de assembly.  
  
 Comentários de estilo do assembly que começam com um ponto e vírgula (**;**) continuar até o final da linha. Isso causa problemas em macros porque o compilador ignora tudo após o comentário, até o final da linha lógica. O mesmo é verdadeiro para comentários de linha única de C ou C++ ( `// comment`). Para evitar erros, use os comentários de C de estilo antigo ( `/* comment */`) em `__asm` blocos definidos como macros.  
  
 Um `__asm` bloco gravado como uma macro C pode receber argumentos. Ao contrário de uma comum macro de C, no entanto, um `__asm` macro não pode retornar um valor. Portanto você não pode usar essas macros em expressões de C ou C++.  
  
 Tenha cuidado para não chamar macros desse tipo de modo indiscriminado. Por exemplo, invocar uma macro de linguagem de assembly em uma função declarada com o `__fastcall` convenção pode causar resultados inesperados. (Consulte [usando e preservando registros em Assembly embutido](../../assembler/inline/using-and-preserving-registers-in-inline-assembly.md).)  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Assembler embutido](../../assembler/inline/inline-assembler.md)