---
title: Definindo blocos __asm como macros do C
ms.date: 08/30/2018
helpviewer_keywords:
- macros, __asm blocks
- Visual C, macros
- __asm keyword [C++], as C macros
ms.assetid: 677ba11c-21c8-4609-bba7-cd47312243b0
ms.openlocfilehash: 4195624078c53f6c1f20cd2a03ed53dac937d9cd
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87192100"
---
# <a name="defining-__asm-blocks-as-c-macros"></a>Definindo blocos __asm como macros do C

**Específico da Microsoft**

As macros C oferecem uma maneira conveniente de inserir o código do assembly em seu código-fonte, mas exigem cuidado extra porque uma macro se expande para uma única linha lógica. Para criar macros sem problemas, siga estas regras:

- Coloque o **`__asm`** bloco entre chaves.

- Coloque a **`__asm`** palavra-chave na frente de cada instrução de assembly.

- Use comentários C de estilo antigo ( `/* comment */` ) em vez de comentários em estilo de assembly ( `; comment` ) ou comentários c de linha única ( `// comment` ).

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

À primeira vista, as últimas três **`__asm`** palavras-chave parecem supérfluas. Eles são necessários, no entanto, porque a macro se expande em uma única linha:

```cpp
__asm /* Port output */ { __asm mov al, 2  __asm mov dx, 0xD007 __asm out dx, al }
```

A terceira e a quarta **`__asm`** palavras-chave são necessárias como separadores de instrução. Os únicos separadores de instrução reconhecidos em **`__asm`** blocos são o caractere de nova linha e a **`__asm`** palavra-chave. Como um bloco definido como uma macro é uma linha lógica, você deve separar cada instrução com **`__asm`** .

As chaves também são essenciais. Se você omiti-los, o compilador poderá ser confundido por instruções C ou C++ na mesma linha à direita da chamada de macro. Sem a chave de fechamento, o compilador não pode informar onde o código do assembly é interrompido e vê as instruções C ou C++ após o **`__asm`** bloco como instruções de assembly.

Os comentários de estilo de assembly que começam com um ponto e vírgula (**;**) continuam até o final da linha. Isso causa problemas em macros porque o compilador ignora tudo após o comentário, até o final da linha lógica. O mesmo é verdadeiro para comentários C ou C++ de linha única ( `// comment` ). Para evitar erros, use os comentários C de estilo antigo ( `/* comment */` ) em **`__asm`** blocos definidos como macros.

Um **`__asm`** bloco gravado como uma macro C pode receber argumentos. No entanto, ao contrário de uma macro C comum, uma **`__asm`** macro não pode retornar um valor. Portanto, você não pode usar essas macros em expressões C ou C++.

Tenha cuidado para não invocar macros desse tipo indiscriminadamente. Por exemplo, invocar uma macro de linguagem de assembly em uma função declarada com a **`__fastcall`** Convenção pode causar resultados inesperados. (Consulte [usando e preservando os registros em assembly embutido](../../assembler/inline/using-and-preserving-registers-in-inline-assembly.md).)

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
