---
title: Definindo blocos __asm como macros do C
ms.date: 08/30/2018
helpviewer_keywords:
- macros, __asm blocks
- Visual C, macros
- __asm keyword [C++], as C macros
ms.assetid: 677ba11c-21c8-4609-bba7-cd47312243b0
ms.openlocfilehash: c48298cf802600995dbbf68885896b6feccb807d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62167020"
---
# <a name="defining-asm-blocks-as-c-macros"></a>Definindo blocos __asm como macros do C

**Seção específica da Microsoft**

Macros C oferecem uma maneira conveniente de inserir o código de assembly em seu código-fonte, mas elas exigem cuidado extra porque uma macro se expande em uma única linha lógica. Para criar macros sem problemas, siga estas regras:

- Coloque o `__asm` bloquear entre chaves.

- Coloque o `__asm` palavra-chave na frente de cada instrução de assembly.

- Use comentários de C antiga ( `/* comment */`) em vez de comentários de estilo de assembly ( `; comment`) ou comentários de C de linha única ( `// comment`).

Para ilustrar, o exemplo a seguir define uma macro simples:

```cpp
#define PORTIO __asm      \
/* Port output */         \
{                         \
   __asm mov al, 2        \
   __asm mov dx, 0xD007   \
   __asm out dx, al       \
}
```

À primeira vista, os três últimos `__asm` palavras-chave parecem supérfluas. Eles são necessários, no entanto, porque a macro se expande em uma única linha:

```cpp
__asm /* Port output */ { __asm mov al, 2  __asm mov dx, 0xD007 __asm out dx, al }
```

A terceira e quarta `__asm` palavras-chave são necessárias como separadores de instrução. Os separadores de instrução única reconhecido em `__asm` blocos são o caractere de nova linha e `__asm` palavra-chave. Como um bloco definido como uma macro é uma linha lógica, você deve separar cada instrução com `__asm`.

As chaves também são essenciais. Se você omiti-los, o compilador pode ser confundido por instruções de C ou C++ na mesma linha à direita da invocação de macro. Sem a chave de fechamento, o compilador não pode determinar onde o código de assembly para e ele vê instruções C ou C++ o `__asm` bloco como instruções de assembly.

Comentários de estilo de assembly que começam com um ponto e vírgula (**;**) continuam até o final da linha. Isso causa problemas nas macros, porque o compilador ignora tudo após o comentário, até o fim da linha lógica. O mesmo é verdadeiro para comentários de linha única de C ou C++ ( `// comment`). Para evitar erros, use comentários de C antiga ( `/* comment */`) no `__asm` blocos definidos como macros.

Um `__asm` bloco gravado como uma macro de C pode receber argumentos. Ao contrário de uma comum macro de C, no entanto, um `__asm` macro não é possível retornar um valor. Portanto, você não pode usar essas macros em expressões de C ou C++.

Tenha cuidado para não invocar macros desse tipo indiscriminadamente. Por exemplo, invocar uma macro de linguagem de assembly em uma função declarada com o `__fastcall` convenção pode causar resultados inesperados. (Consulte [usando e preservando registros no Assembly embutido](../../assembler/inline/using-and-preserving-registers-in-inline-assembly.md).)

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>