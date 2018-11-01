---
title: __thiscall
ms.date: 11/04/2016
f1_keywords:
- __thiscall
- __thiscall_cpp
helpviewer_keywords:
- __thiscall keyword [C++]
ms.assetid: a6a22dd2-0101-4885-b33b-22f6057965df
ms.openlocfilehash: fc5a32fedf52377889b61103856e2125733cd696
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50448835"
---
# <a name="thiscall"></a>__thiscall

**Seção específica da Microsoft**

O **thiscall** convenção de chamada é usada em funções membro e é a convenção de chamada padrão usada pelas funções de membro de C++ que não usam argumentos variáveis. Sob **thiscall**, o receptor limpa a pilha, que é impossível `vararg` funções. Os argumentos são empurrados na pilha da direita para esquerda, com o **isso** ponteiro que está sendo passado por meio do registro ECX e não na pilha, em x86 arquitetura.

Um motivo para usar **thiscall** está em classes cujas funções membro usam `__clrcall` por padrão. Nesse caso, você pode usar **thiscall** para tornar funções membro individuais que pode ser chamado do código nativo.

Ao compilar com [/clr: pure](../build/reference/clr-common-language-runtime-compilation.md), todas as funções e ponteiros de função são `__clrcall` , a menos que especificado o contrário. O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Nas versões anteriores do Visual C++ 2005, o **thiscall** convenção de chamada não pôde ser explicitamente especificada em um programa, porque **thiscall** não era uma palavra-chave.

`vararg` funções membro usam o **cdecl** convenção de chamada. Todos os argumentos de função são enviados por push na pilha, com o **isso** ponteiro é colocado na pilha pela última vez

Como esta convenção de chamada se aplica apenas a C++, não há nenhum esquema de decoração de nome de C.

No ARM e x64 máquinas **thiscall** é aceito e ignorado pelo compilador.

Para funções de classe não estáticas, se a função for definida como fora da linha, o modificador da convenção de chamada não precisará ser especificado na definição fora da linha. Ou seja, para métodos de membro de classe não estática, a convenção de chamada especificada durante a declaração é assumida no ponto de definição.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Convenções de passagem e nomenclatura de argumentos](../cpp/argument-passing-and-naming-conventions.md)