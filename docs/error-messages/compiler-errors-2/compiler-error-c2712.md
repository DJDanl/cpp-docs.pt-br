---
title: Erro do compilador C2712
ms.date: 11/04/2016
f1_keywords:
- C2712
helpviewer_keywords:
- C2712
ms.assetid: f7d4ffcc-7ed2-459b-8067-a728ce647071
ms.openlocfilehash: a25c59fa5c9ba0102666f6c8922a61b063e7627a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80202300"
---
# <a name="compiler-error-c2712"></a>Erro do compilador C2712

> Não é possível usar __try em funções que exigem o desenrolamento de objeto

## <a name="remarks"></a>Comentários

O erro C2712 pode ocorrer se você usar o [/EHsc](../../build/reference/eh-exception-handling-model.md), e uma função com manipulação de exceção estruturada também tiver objetos que exigem desenrolamento (destruição).

Soluções possíveis:

- Mover o código que requer SEH para outra função

- Reescreva funções que usam SEH para evitar o uso de variáveis locais e parâmetros que têm destruidores. Não use SEH em construtores ou destruidores

- Compilar sem/EHsc

O erro C2712 também pode ocorrer se você chamar um método declarado usando a palavra-chave [__event](../../cpp/event.md) . Como o evento pode ser usado em um ambiente multi-threaded, o compilador gera um código que impede a manipulação do objeto de evento subjacente e, em seguida, inclui o código gerado em uma [instrução try-finally](../../cpp/try-finally-statement.md)de SEH. Consequentemente, o erro C2712 ocorrerá se você chamar o método de evento e passar por valor um argumento cujo tipo tem um destruidor. Uma solução nesse caso é passar o argumento como uma referência constante.

C2712 também pode ocorrer se você compilar com **/CLR: Pure** e declarar uma matriz estática de ponteiros para funções em um bloco de `__try`. Um membro estático requer que o compilador use a inicialização dinâmica em **/CLR: Pure**, que C++ implica no tratamento de exceção. No entanto, C++ o tratamento de exceção não é permitido em um bloco de `__try`.

As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

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
