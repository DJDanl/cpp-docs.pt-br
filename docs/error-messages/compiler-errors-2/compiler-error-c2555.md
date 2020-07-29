---
title: Erro do compilador C2555
description: Referência para o erro C2555 do compilador do Visual Studio C++.
ms.date: 03/30/2020
f1_keywords:
- C2555
helpviewer_keywords:
- C2555
ms.assetid: 5e49ebb8-7c90-457a-aa12-7ca7ab6574b2
ms.openlocfilehash: ecac92bc663a6344e9ddafe13c194a92ab944c51
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87207791"
---
# <a name="compiler-error-c2555"></a>Erro do compilador C2555

> '*Class1*::*function1*': tipo de retorno da função virtual de substituição difere e não é covariant de '*class2*::*function2*'

Uma função virtual e uma função de substituição derivada têm listas de parâmetros idênticas, mas diferentes tipos de retorno.

## <a name="remarks"></a>Comentários

Em C++, uma função de substituição em uma classe derivada não pode diferir somente pelo tipo de retorno de uma função virtual em uma classe base.

Há uma exceção a essa regra para determinados tipos de retorno. Quando uma classe derivada substitui uma classe base pública, ela pode retornar um ponteiro ou uma referência à classe derivada em vez de um ponteiro de classe base ou referência. Esses tipos de retorno são chamados *covariant*, pois eles variam junto com o tipo. Essa exceção de regra não permite tipos de referência de covariant-to-pointer ou ponteiro para ponteiro.

Uma maneira de resolver o erro é retornar o mesmo tipo que a classe base. Em seguida, converta o valor de retorno depois que a função virtual for chamada. Outro é também alterar a lista de parâmetros, para tornar a função de membro de classe derivada uma sobrecarga em vez de uma substituição.

## <a name="examples"></a>Exemplos

Você poderá ver esse erro se você compilar com **`/clr`** . Por exemplo, o C++ equivalente à seguinte declaração de C#:

```csharp
Guid[] CheckSources(Guid sourceID, Guid[] carouselIDs);
```

está

```cpp
Guid CheckSources(Guid sourceID, Guid carouselIDs[]) [];
```

O exemplo a seguir gera C2555:

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

Para corrigi-lo, altere o tipo de retorno de `Y::func` para **`void`** .
