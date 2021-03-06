---
title: __thiscall
description: Saiba mais sobre a Convenção de chamada de __thiscall específica da Microsoft para funções de membro de classe x86 no Microsoft C++.
ms.date: 05/22/2020
f1_keywords:
- __thiscall
- __thiscall_cpp
helpviewer_keywords:
- __thiscall keyword [C++]
ms.assetid: a6a22dd2-0101-4885-b33b-22f6057965df
ms.openlocfilehash: 9b11dcf8dee928b687f942639ed72ead3659614b
ms.sourcegitcommit: 25f6d52eb9e5d84bd0218c46372db85572af81da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2020
ms.locfileid: "94448445"
---
# `__thiscall`

A Convenção de chamada **específica da Microsoft** **`__thiscall`** é usada em funções de membro de classe C++ na arquitetura x86. É a Convenção de chamada padrão usada pelas funções de membro que não usam argumentos variáveis ( `vararg` Functions).

Em **`__thiscall`** , o receptor limpa a pilha, o que é impossível para as `vararg` funções. Os argumentos são enviados por push na pilha da direita para a esquerda. O **`this`** ponteiro é transmitido por meio do Registro ECX e não da pilha.

Em máquinas ARM, ARM64 e x64, **`__thiscall`** é aceita e ignorado pelo compilador. Isso ocorre porque eles usam uma Convenção de chamada baseada em registro por padrão.

Um motivo para usar **`__thiscall`** está em classes cujas funções de membro usam **`__clrcall`** por padrão. Nesse caso, você pode usar **`__thiscall`** para tornar as funções de membro individuais que podem ser chamadas do código nativo.

Ao compilar com [`/clr:pure`](../build/reference/clr-common-language-runtime-compilation.md) , todas as funções e ponteiros de função são **`__clrcall`** , a menos que especificado o contrário. As **`/clr:pure`** **`/clr:safe`** Opções de compilador e são preteridas no visual Studio 2015 e sem suporte no visual Studio 2017.

`vararg` as funções de membro usam a **`__cdecl`** Convenção de chamada. Todos os argumentos de função são enviados por push na pilha, com o **`this`** ponteiro colocado na pilha por último.

Como essa Convenção de chamada se aplica apenas ao C++, ela não tem um esquema de decoração de nome de C.

Quando você define uma função de membro de classe não estática fora de linha, especifique o modificador de Convenção de chamada somente na declaração. Você não precisa especificá-lo novamente na definição fora de linha. O compilador usa a Convenção de chamada especificada durante a declaração no ponto de definição.

## <a name="see-also"></a>Confira também

[Passagem de argumentos e convenções de nomenclatura](../cpp/argument-passing-and-naming-conventions.md)
