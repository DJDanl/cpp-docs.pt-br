---
title: C2712 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2712
dev_langs:
- C++
helpviewer_keywords:
- C2712
ms.assetid: f7d4ffcc-7ed2-459b-8067-a728ce647071
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 27db5f8ae3fd56078a3085c8d216e7dd34edb2fc
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34704250"
---
# <a name="compiler-error-c2712"></a>C2712 de erro do compilador

> não é possível usar try em funções que exigem a liberação de objeto

## <a name="remarks"></a>Comentários

C2712 de erro pode ocorrer se você usar [/EHsc](../../build/reference/eh-exception-handling-model.md), e uma função com tratamento de exceções estruturado também tiver objetos que exigem o desenrolamento (destruição).

Soluções possíveis:

- Mova o código que requer SEH para outra função

- Reescreva funções que usam SEH para evitar o uso de variáveis locais e parâmetros que têm destruidores. Não use SEH em construtores ou destrutores

- Compilar sem /EHsc

C2712 erro também poderá ocorrer se você chamar um método declarado usando a [Event](../../cpp/event.md) palavra-chave. Como o evento pode ser usado em um ambiente multithreaded, o compilador gera o código que impede a manipulação do objeto de evento subjacente e, em seguida, inclui o código gerado em um SEH [instrução try-finally](../../cpp/try-finally-statement.md). Consequentemente, o erro C2712 ocorrerá se você chamar o método de evento e passa por valor de um argumento cujo tipo tenha um destruidor. Nesse caso, uma solução é passar o argumento como uma referência constante.

C2712 também pode ocorrer se você compilar com **/clr: pure** e declarar uma matriz estática de ponteiros para funções em um `__try` bloco. Um membro estático requer que o compilador para usar a inicialização dinâmica em **/clr: pure**, que implica que o tratamento de exceções C++. No entanto, o tratamento de exceções C++ não é permitido em um `__try` bloco.

O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

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