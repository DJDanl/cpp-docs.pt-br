---
title: PROTO
ms.date: 10/22/2018
f1_keywords:
- PROTO
helpviewer_keywords:
- PROTO directive
ms.assetid: 0487ee16-9dc7-43d1-9445-cd1601f5a080
ms.openlocfilehash: 24ec2a9abc6c8b76fc81f6d412019296c53160f4
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74394749"
---
# <a name="proto"></a>PROTO

Protótipos de uma função ou procedimento. Você pode chamar a função com protótipo pela diretiva PROTO usando a diretiva [Invoke](invoke.md) .

## <a name="syntax"></a>Sintaxe

> *rótulo* **proto** ⟦*Distance*⟧ ⟦*idioma-tipo*⟧ ⟦ __,__ ⟦*parâmetro*⟧ __:__ *marca* ... ⟧

### <a name="parameters"></a>Parâmetros

*rótulo*\
O nome da função com protótipo.

\ de *distância*
Adicional Usado em modelos de memória de 16 bits para substituir o padrão e indicar chamadas **próximas** ou **distantes** .

\ *de tipo de idioma*
Adicional Define a Convenção de nomenclatura e a chamada para procedimentos e símbolos públicos. As convenções com suporte são:

- modelo **simples** de 32 bits: **C**, **stdcall**

- modelos de 16 bits: **C**, **Basic**, **Fortran**, **Pascal**, **syscall**, **stdcall**

\ de *parâmetro*
O nome opcional para um parâmetro de função.

*marca*\
O tipo de um parâmetro de função.

Os parâmetros de *marca* e *parâmetro* podem aparecer várias vezes, uma vez para cada argumento passado.

## <a name="example"></a>Exemplo

Este exemplo mostra uma declaração **proto** para uma função chamada `addup3` que usa uma chamada **Near** para substituir o padrão de modelo de 16 bits para chamadas de procedimento e usa a Convenção de chamada **C** para parâmetros de pilha e valores de retorno. Ele usa dois argumentos, uma **palavra** e uma **vararg**.

```MASM
addup3 PROTO NEAR C, argcount:WORD, arg1:VARARG
```

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)\
[. Referência de modelo](dot-model.md)
