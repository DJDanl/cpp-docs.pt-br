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
ms.openlocfilehash: 16b298b92a4ba40d9091499a1821ad4f3c413d6c
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74854518"
---
# <a name="using-c-or-c-in-__asm-blocks"></a>Usando C ou C++ em blocos __asm

**Seção específica da Microsoft**

Como as instruções de assembly embutidas podem ser misturadas com C ou C++ instruções, elas podem C++ se referir a c ou variáveis por nome e usar muitos outros elementos desses idiomas.

Um bloco de `__asm` pode usar os seguintes elementos de linguagem:

- Símbolos, incluindo rótulos e nomes de variáveis e funções

- Constantes, incluindo constantes simbólicas e membros de `enum`

- Macros e diretivas de pré-processador

- Comentários ( __/\* \*/__ e __//__ )

- Nomes de tipos (onde quer que um tipo MASM seja legal)

- nomes de `typedef`, geralmente usados com operadores como **PTR** e **Type** ou para especificar membros de estrutura ou União

Em um bloco de `__asm`, você pode especificar constantes de inteiro com notação C ou notação de base do assembler (0x100 e 100h são equivalentes, por exemplo). Isso permite que você defina (usando `#define`) uma constante em C e, em seguida, use-a C++ nas partes c ou e assembly do programa. Você também pode especificar constantes em octal precedendo-as com um 0. Por exemplo, 0777 especifica uma constante octal.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Usando operadores em blocos __asm](../../assembler/inline/using-operators-in-asm-blocks.md)

- [Usando blocos de C++ __Asm do C ou Symbols_in](../../assembler/inline/using-c-or-cpp-symbols-in-asm-blocks.md)

- [Acessando dados C ou C++ em blocos __asm](../../assembler/inline/accessing-c-or-cpp-data-in-asm-blocks.md)

- [Escrevendo funções com assembly embutido](../../assembler/inline/writing-functions-with-inline-assembly.md)

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Assembler embutido](../../assembler/inline/inline-assembler.md)<br/>
