---
title: Visão geral de instruções C
ms.date: 11/04/2016
helpviewer_keywords:
- semicolon, in C statements
- statements, C
- semicolon
- statements, about statements
- Visual C, statements
ms.assetid: 0d49837a-5399-4881-b60c-af5f4e9720de
ms.openlocfilehash: 6b6cf9ee7aab3f14b3cb4b48c10e59125391c14c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211769"
---
# <a name="overview-of-c-statements"></a>Visão geral de instruções C

As instruções C consistem em tokens, expressões e outras instruções. Uma instrução que forma um componente de outra instrução chama-se o “corpo” da instrução pertinente. Cada tipo de instrução fornecido pela sintaxe a seguir será discutido nesta seção.

## <a name="syntax"></a>Sintaxe

*statement*: [labeled-statement](../c-language/goto-and-labeled-statements-c.md)

[compound-statement](../c-language/compound-statement-c.md)

[expression-statement](../c-language/expression-statement-c.md)

[instrução de seleção](../c-language/if-statement-c.md)

[iteration-statement](../c-language/do-while-statement-c.md)

[jump-statement](../c-language/break-statement-c.md)

[try-Except-Statement](../c-language/try-except-statement-c.md) /* específico da Microsoft\*/

[try-finally-statement](../c-language/try-finally-statement-c.md)  / instrução \* try – finally Específico da Microsoft\*/

Geralmente, o corpo da instrução é uma “instrução composta”. Uma instrução composta consiste em outras instruções que podem incluir palavras-chave. A instrução compound é delimitada por chaves (**{ }**). Todas as outras instruções C terminam com ponto-e-vírgula (**;**). O ponto-e-vírgula é um terminador de instrução.

A instrução da expressão contém a expressão C que pode conter operadores aritméticos ou lógicos introduzidos em [Expressões e atribuições](../c-language/expressions-and-assignments.md). A instrução null é uma instrução vazia.

Qualquer instrução C pode começar com um rótulo de identificação que consiste em um nome e dois-pontos. Como apenas a **`goto`** instrução reconhece os rótulos de instrução, os rótulos de instrução são discutidos com **`goto`** . Consulte [as instruções goto e labeled](../c-language/goto-and-labeled-statements-c.md) para obter mais informações.

## <a name="see-also"></a>Confira também

[Instruções](../c-language/statements-c.md)
