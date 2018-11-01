---
title: Erro do compilador C2712
ms.date: 11/04/2016
f1_keywords:
- C2712
helpviewer_keywords:
- C2712
ms.assetid: f7d4ffcc-7ed2-459b-8067-a728ce647071
ms.openlocfilehash: 19b9c5a54bf405114bd4d596c2a2cc4708aadcc9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50507898"
---
# <a name="compiler-error-c2712"></a>Erro do compilador C2712

> não é possível usar try em funções que exigem a liberação de objeto

## <a name="remarks"></a>Comentários

C2712 de erro pode ocorrer se você usar [/EHsc](../../build/reference/eh-exception-handling-model.md), e uma função com tratamento de exceções estruturado também tem os objetos que exigem o desenrolamento (destruição).

Soluções possíveis:

- Mover o código que requer o SEH para outra função

- Reescreva funções que usam o SEH para evitar o uso de variáveis locais e parâmetros que têm destruidores. Não use SEH em construtores ou destruidores

- Compilar sem /EHsc

Erro C2712 também pode ocorrer se você chamar um método declarado usando a [Event](../../cpp/event.md) palavra-chave. Como o evento pode ser usado em um ambiente multithreaded, o compilador gera código que impede que a manipulação do objeto de evento subjacente e, em seguida, inclui o código gerado em um SEH [instrução try-finally](../../cpp/try-finally-statement.md). Consequentemente, o erro C2712 ocorrerá se você chamar o método de evento e passa por valor de um argumento cujo tipo tem um destruidor. Nesse caso, uma solução é passar o argumento como uma referência constante.

C2712 também pode ocorrer se você compilar com **/clr: pure** e declarar uma matriz estática de ponteiros para funções em um `__try` bloco. Um membro estático exige que o compilador para usar inicialização dinâmica sob **/clr: pure**, que significa que o tratamento de exceções C++. No entanto, o tratamento de exceções C++ não é permitido em um `__try` bloco.

O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

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