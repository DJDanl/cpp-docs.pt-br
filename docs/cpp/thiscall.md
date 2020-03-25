---
title: __thiscall
ms.date: 11/04/2016
f1_keywords:
- __thiscall
- __thiscall_cpp
helpviewer_keywords:
- __thiscall keyword [C++]
ms.assetid: a6a22dd2-0101-4885-b33b-22f6057965df
ms.openlocfilehash: 8772159dca71bb7605af5e5919425065423d503d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188149"
---
# <a name="__thiscall"></a>__thiscall

**Seção específica da Microsoft**

A Convenção de chamada **__thiscall** é usada em funções de membro e é a Convenção de chamada C++ padrão usada por funções de membro que não usam argumentos variáveis. Em **__thiscall**, o receptor limpa a pilha, o que é impossível para `vararg` funções. Os argumentos são enviados por push na pilha da direita para a esquerda, **com o ponteiro** que está sendo passado por meio do registro ecx, e não na pilha, na arquitetura x86.

Um motivo para usar **__thiscall** é em classes cujas funções de membro usam `__clrcall` por padrão. Nesse caso, você pode usar **__thiscall** para tornar as funções de membro individuais que podem ser chamadas de código nativo.

Ao compilar com [/CLR: Pure](../build/reference/clr-common-language-runtime-compilation.md), todas as funções e ponteiros de função são `__clrcall`, a menos que especificado de outra forma. As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Em versões anteriores ao Visual Studio 2005, a Convenção de chamada **__thiscall** não pôde ser especificada explicitamente em um programa, porque **__thiscall** não era uma palavra-chave.

`vararg` funções de membro usam a Convenção de chamada **__cdecl** . Todos os argumentos de função são enviados por push na pilha, **com o ponteiro** colocado na pilha por último

Como esta convenção de chamada se aplica apenas a C++, não há nenhum esquema de decoração de nome de C.

Em máquinas ARM e x64, **__thiscall** é aceita e ignorada pelo compilador.

Para funções de classe não estáticas, se a função for definida como fora da linha, o modificador da convenção de chamada não precisará ser especificado na definição fora da linha. Ou seja, para métodos de membro de classe não estática, a convenção de chamada especificada durante a declaração é assumida no ponto de definição.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Convenções de passagem e nomenclatura de argumentos](../cpp/argument-passing-and-naming-conventions.md)
