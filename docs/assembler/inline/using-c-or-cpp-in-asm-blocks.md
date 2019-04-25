---
title: Usando C ou C++ em blocos __asm
ms.date: 08/30/2018
helpviewer_keywords:
- inline assembly, mixing instructions with C/C++ statements
- symbols, in __asm blocks
- macros, __asm blocks
- preprocessor directives, used in __asm blocks
- type names, used in __asm blocks
- preprocessor directives
- preprocessor, directives
- constants, in __asm blocks
- comments, in __asm blocks
- typedef names, used in __asm blocks
- __asm keyword [C++], C/C++ elements in
ms.assetid: ae8b2b52-6b75-42e3-ac0c-ad02d922ed97
ms.openlocfilehash: 0949eba769bed33da8fe39bb41500a2ba02af224
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62166549"
---
# <a name="using-c-or-c-in-asm-blocks"></a>Usando C ou C++ em blocos __asm

* * Específico da Microsoft * *

Porque as instruções de assembly embutido podem ser misturadas com instruções C ou C++, podem se referir a variáveis de C ou C++ por nome e usar muitos outros elementos de um desses idiomas.

Um `__asm` bloco pode usar os seguintes elementos de linguagem:

- Símbolos, incluindo rótulos e nomes de variável e de função

- Constantes, incluindo constantes simbólicas e `enum` membros

- Macros e diretivas do pré-processador

- Comentários (ambos __/ \* \* /__ e __//__ )

- Digite nomes (onde quer que um tipo MASM seria legal)

- `typedef` nomes, geralmente usados com operadores, como **PTR** e **tipo** ou para especificar os membros de estrutura ou união

Dentro de um `__asm` bloco, você pode especificar constantes de inteiro com a notação de C ou notação de base do assembler (0x100 e 100 h são equivalentes, por exemplo). Isso permite que você defina (usando `#define`) uma constante em C e, em seguida, usá-lo em C ou C++ e assembly partes do programa. Você também pode especificar constantes em octal, precedendo-as com um 0. Por exemplo, 0777 Especifica uma constante octal.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Usando operadores em blocos __asm](../../assembler/inline/using-operators-in-asm-blocks.md)

- [Usando C ou C++ Symbols_in blocos de ASM](../../assembler/inline/using-c-or-cpp-symbols-in-asm-blocks.md)

- [Acessando dados C ou C++ em blocos __asm](../../assembler/inline/accessing-c-or-cpp-data-in-asm-blocks.md)

- [Escrevendo funções com assembly embutido](../../assembler/inline/writing-functions-with-inline-assembly.md)

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
