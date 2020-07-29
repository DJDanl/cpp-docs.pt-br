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
ms.openlocfilehash: 05e63d666f3fc39126d6f48e8fc523c4a02e76df
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87191411"
---
# <a name="using-c-or-c-in-__asm-blocks"></a>Usando C ou C++ em blocos __asm

**Específico da Microsoft**

Como as instruções de assembly embutidas podem ser misturadas com instruções C ou C++, elas podem se referir a variáveis C ou C++ por nome e usar muitos outros elementos desses idiomas.

Um **`__asm`** bloco pode usar os seguintes elementos de linguagem:

- Símbolos, incluindo rótulos e nomes de variáveis e funções

- Constantes, incluindo constantes e membros simbólicos **`enum`**

- Macros e diretivas de pré-processador

- __ / \* Comentários \* ( / __ e __//__ )

- Nomes de tipos (onde quer que um tipo MASM seja legal)

- **`typedef`** nomes, geralmente usados com operadores como **PTR** e **Type** ou para especificar membros de estrutura ou União

Em um **`__asm`** bloco, você pode especificar constantes de inteiro com notação C ou notação de base do assembler (0x100 e 100h são equivalentes, por exemplo). Isso permite que você defina (usando `#define` ) uma constante em c e, em seguida, use-a nas partes c ou C++ e assembly do programa. Você também pode especificar constantes em octal precedendo-as com um 0. Por exemplo, 0777 especifica uma constante octal.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Usando operadores em blocos de __asm](../../assembler/inline/using-operators-in-asm-blocks.md)

- [Usando blocos de __asm de Symbols_in do C ou C++](../../assembler/inline/using-c-or-cpp-symbols-in-asm-blocks.md)

- [Acessando dados C ou C++ em blocos de __asm](../../assembler/inline/accessing-c-or-cpp-data-in-asm-blocks.md)

- [Gravando funções com assembly embutido](../../assembler/inline/writing-functions-with-inline-assembly.md)

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
