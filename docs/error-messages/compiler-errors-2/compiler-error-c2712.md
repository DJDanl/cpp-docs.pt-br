---
title: Erro do compilador C2712
description: Descreve o erro C2712 do compilador C/C++ do Microsoft.
ms.date: 08/25/2020
f1_keywords:
- C2712
helpviewer_keywords:
- C2712
ms.assetid: f7d4ffcc-7ed2-459b-8067-a728ce647071
ms.openlocfilehash: 2f0b883607241473a429919e06de9e975fa2e3c1
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898700"
---
# <a name="compiler-error-c2712"></a>Erro do compilador C2712

> Não é possível usar `__try` em funções que exigem o desenrolamento de objeto

## <a name="remarks"></a>Comentários

O erro C2712 pode ocorrer se você usar [`/EHsc`](../../build/reference/eh-exception-handling-model.md) o, e uma função com manipulação de exceção estruturada também tiver objetos que exigem desenrolamento (destruição).

Soluções possíveis:

- Mover o código que requer SEH para outra função

- Reescreva funções que usam SEH para evitar o uso de variáveis locais e parâmetros que têm destruidores. Não use SEH em construtores ou destruidores

- Compilar sem/EHsc

O erro C2712 também pode ocorrer se você chamar um método declarado usando a [`__event`](../../cpp/event.md) palavra-chave. Como o evento pode ser usado em um ambiente multi-threaded, o compilador gera um código que impede a manipulação do objeto de evento subjacente e, em seguida, inclui o código gerado em uma [ `try-finally` instrução](../../cpp/try-finally-statement.md)SEH. Consequentemente, o erro C2712 ocorrerá se você chamar o método de evento e passar por valor um argumento cujo tipo tem um destruidor. Uma solução nesse caso é passar o argumento como uma referência constante.

C2712 também pode ocorrer se você compilar com **`/clr:pure`** e declarar uma matriz estática de ponteiros para funções em um **`__try`** bloco. Um membro estático requer que o compilador use a inicialização dinâmica em **`/clr:pure`** , o que implica a manipulação de exceção do C++. No entanto, a manipulação de exceção do C++ não é permitida em um **`__try`** bloco.

As **`/clr:pure`** **`/clr:safe`** Opções de compilador e são preteridas no visual Studio 2015 e sem suporte no visual Studio 2017.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2712 e mostra como corrigi-lo.

```cpp
// C2712.cpp
// compile with: /clr:pure /c
struct S1 {
   static int smf();
   void fnc();
};

void S1::fnc() {
   __try {
      static int (*array_1[])() = {smf,};   // C2712

      // OK
      static int (*array_2[2])();
      array_2[0] = smf;
    }
    __except(0) {}
}
```
