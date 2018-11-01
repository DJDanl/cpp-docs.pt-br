---
title: PROTO
ms.date: 10/22/2018
f1_keywords:
- PROTO
helpviewer_keywords:
- PROTO directive
ms.assetid: 0487ee16-9dc7-43d1-9445-cd1601f5a080
ms.openlocfilehash: 616b6be2a5c191ebc67d61288cb5fa6c183091fa
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50536696"
---
# <a name="proto"></a>PROTO

Protótipos de uma função ou procedimento. Você pode chamar a função prototipada pela diretiva PROTO usando o [INVOKE](invoke.md) diretiva.

## <a name="syntax"></a>Sintaxe

> *rótulo* **PROTO** \[ *distância*] \[ *langtype*] \[ __,__ \[ *parâmetro*]__:__*marca*]...

### <a name="parameters"></a>Parâmetros

*label*<br/>
O nome da função com protótipo.

*distance*<br/>
(Opcional) Usado em modelos de memória de 16 bits para substituir o padrão e indicar **NEAR** ou **EXTREMO** chamadas.

*langtype*<br/>
(Opcional) Define a convenção de nomenclatura e chamada de procedimentos e os símbolos públicos. Convenções com suporte são:

- 32 bits **simples** modelo: **C**, **STDCALL**

- modelos de 16 bits: **C**, **BASIC**, **FORTRAN**, **PASCAL**, **SYSCALL**, **STDCALL**

*parameter*<br/>
O nome opcional para um parâmetro de função.

*Marca*<br/>
O tipo de um parâmetro de função.

O *parâmetro* e *marca* parâmetros podem aparecer várias vezes, uma vez para cada argumento passado.

## <a name="example"></a>Exemplo

Este exemplo mostra uma **PROTO** declaração para uma função chamada `addup3` que usa um **NEAR** chamada para substituir o padrão de modelo de 16 bits para chamadas de procedimento e usa o **C**convenção de chamada de pilha de parâmetros e valores de retorno. Ele usa dois argumentos, uma **WORD** e uma **VARARG**.

```MASM
addup3 PROTO NEAR C, argcount:WORD, arg1:VARARG
```

## <a name="see-also"></a>Consulte também

[Referência de diretivas](directives-reference.md)<br/>
[. Referência de modelo](dot-model.md)<br/>
