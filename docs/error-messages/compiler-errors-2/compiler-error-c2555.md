---
title: Erro do compilador C2555
description: Referência para erro do compilador Visual Studio C++ C2555.
ms.date: 03/30/2020
f1_keywords:
- C2555
helpviewer_keywords:
- C2555
ms.assetid: 5e49ebb8-7c90-457a-aa12-7ca7ab6574b2
ms.openlocfilehash: fe0e6379e783387506e6098c9b14a047baa8e6c8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374180"
---
# <a name="compiler-error-c2555"></a>Erro do compilador C2555

> '*class1*::*function1*': sobrepondo o tipo de retorno da função virtual difere e não é covariante da '*classe2*::*function2*'

Uma função virtual e uma função de substituição derivada têm listas de parâmetros idênticas, mas diferentes tipos de retorno.

## <a name="remarks"></a>Comentários

Em C++, uma função de substituição em uma classe derivada não pode diferir apenas pelo tipo de retorno de uma função virtual em uma classe base.

Há uma exceção a esta regra para certos tipos de retorno. Quando uma classe derivada substitui uma classe de base pública, ela pode retornar um ponteiro ou referência à classe derivada em vez de um ponteiro de classe base ou referência. Esses tipos de retorno são chamados *de covariante,* porque variam de acordo com o tipo. Essa exceção de regra não permite tipos de referência covariante para ponteiro ou ponteiro.

Uma maneira de resolver o erro é retornar o mesmo tipo que a classe base. Em seguida, lance o valor de retorno após a função virtual ter sido chamada. Outra é também alterar a lista de parâmetros, para fazer com que o membro da classe derivado funcione uma sobrecarga em vez de uma substituição.

## <a name="examples"></a>Exemplos

Você pode ver este erro **`/clr`** se você compilar com . Por exemplo, o equivalente c++ à seguinte declaração C#:

```csharp
Guid[] CheckSources(Guid sourceID, Guid[] carouselIDs);
```

is

```cpp
Guid CheckSources(Guid sourceID, Guid carouselIDs[]) [];
```

A seguinte amostra gera C2555:

```cpp
// C2555.cpp
// compile with: /c
struct X {
   virtual void func();
};
struct Y : X {
   char func();  // C2555
   void func2();   // OK
};
```

Para corrigi-lo, altere `Y::func` `void`o tipo de retorno para .
