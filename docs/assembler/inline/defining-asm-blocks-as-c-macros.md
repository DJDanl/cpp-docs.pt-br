---
title: Definindo blocos __asm como macros do C
ms.date: 08/30/2018
helpviewer_keywords:
- macros, __asm blocks
- Visual C, macros
- __asm keyword [C++], as C macros
ms.assetid: 677ba11c-21c8-4609-bba7-cd47312243b0
ms.openlocfilehash: 46f0a23fcfd949843e3548354f52970b10b6d63b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169481"
---
# <a name="defining-__asm-blocks-as-c-macros"></a>Definindo blocos __asm como macros do C

**Seção específica da Microsoft**

As macros C oferecem uma maneira conveniente de inserir o código do assembly em seu código-fonte, mas exigem cuidado extra porque uma macro se expande para uma única linha lógica. Para criar macros sem problemas, siga estas regras:

- Coloque o bloco de `__asm` entre chaves.

- Coloque a palavra-chave `__asm` na frente de cada instrução de assembly.

- Use comentários C de estilo antigo (`/* comment */`) em vez de comentários de estilo de assembly (`; comment`) ou comentários C de linha única (`// comment`).

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

À primeira vista, as últimas três palavras-chave de `__asm` parecem supérfluas. Eles são necessários, no entanto, porque a macro se expande em uma única linha:

```cpp
__asm /* Port output */ { __asm mov al, 2  __asm mov dx, 0xD007 __asm out dx, al }
```

A terceira e a quarta `__asm` palavras-chave são necessárias como separadores de instrução. Os únicos separadores de instrução reconhecidos em blocos de `__asm` são o caractere de nova linha e a palavra-chave `__asm`. Como um bloco definido como uma macro é uma linha lógica, você deve separar cada instrução com `__asm`.

As chaves também são essenciais. Se você omiti-los, o compilador poderá ser confundido por C++ C ou instruções na mesma linha à direita da chamada de macro. Sem a chave de fechamento, o compilador não pode informar onde o código do assembly é interrompido e C++ vê C ou instruções após o bloco de `__asm` como instruções de assembly.

Os comentários de estilo de assembly que começam com um ponto e vírgula ( **;** ) continuam até o final da linha. Isso causa problemas em macros porque o compilador ignora tudo após o comentário, até o final da linha lógica. O mesmo é verdadeiro para C ou C++ Comments de linha única (`// comment`). Para evitar erros, use os comentários C de estilo antigo (`/* comment */`) em blocos de `__asm` definidos como macros.

Um bloco de `__asm` gravado como uma macro C pode receber argumentos. No entanto, ao contrário de uma macro C comum, uma macro `__asm` não pode retornar um valor. Portanto, você não pode usar essas macros C++ em C ou expressões.

Tenha cuidado para não invocar macros desse tipo indiscriminadamente. Por exemplo, invocar uma macro de linguagem de assembly em uma função declarada com a Convenção de `__fastcall` pode causar resultados inesperados. (Consulte [usando e preservando os registros em assembly embutido](../../assembler/inline/using-and-preserving-registers-in-inline-assembly.md).)

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
