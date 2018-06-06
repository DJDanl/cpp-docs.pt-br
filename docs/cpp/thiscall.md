---
title: thiscall | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __thiscall
- __thiscall_cpp
dev_langs:
- C++
helpviewer_keywords:
- __thiscall keyword [C++]
ms.assetid: a6a22dd2-0101-4885-b33b-22f6057965df
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4912628529ae0b47a5a5b938ab8e6d25a9099510
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34704397"
---
# <a name="thiscall"></a>__thiscall

**Seção específica da Microsoft**

A convenção de chamada `__thiscall` é usada em funções membro e é a convenção de chamada padrão usada por funções membro do C++ que não usam argumentos variáveis. Sob `__thiscall`, o receptor limpa a pilha, o que é impossível para funções `vararg`. Os argumentos são enviados por push na pilha da direita para a esquerda, com o ponteiro `this` passado por meio do registro de ECX, e não na pilha, na arquitetura x86.

Uma razão para usar `__thiscall` está em classes cujas funções membro usam `__clrcall` por padrão. Nesse caso, você pode usar `__thiscall` para tornar funções membro individuais a partir de código nativo.

Ao compilar com [/clr: pure](../build/reference/clr-common-language-runtime-compilation.md), todas as funções e os ponteiros de função são `__clrcall` , a menos que especificado o contrário. O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

Em versões do Visual C++ 2005, o `__thiscall` convenção de chamada não pôde ser explicitamente especificada em um programa, como `__thiscall` não era uma palavra-chave.

As funções membro `vararg` usam a convenção de chamada `__cdecl`. Todos os argumentos de função são enviadas por push na pilha, com o ponteiro `this` posicionado na última pilha

Como esta convenção de chamada se aplica apenas a C++, não há nenhum esquema de decoração de nome de C.

Em ARM e x64 máquinas, `__thiscall` é aceita e ignorado pelo compilador.

Para funções de classe não estáticas, se a função for definida como fora da linha, o modificador da convenção de chamada não precisará ser especificado na definição fora da linha. Ou seja, para métodos de membro de classe não estática, a convenção de chamada especificada durante a declaração é assumida no ponto de definição.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

- [Convenções de passagem e nomenclatura de argumentos](../cpp/argument-passing-and-naming-conventions.md)
