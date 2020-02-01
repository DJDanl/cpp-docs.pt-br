---
title: Como especificar um parâmetro out
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- function parameters
- out parameters
ms.assetid: 02862448-603c-4e9d-a5c5-b45fe38446e3
ms.openlocfilehash: 4bd6ad1d3009adcc124bdeb90d9d67de07112de2
ms.sourcegitcommit: c4528a7424d35039454f17778baf1b5f98fbbee7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/01/2020
ms.locfileid: "76912792"
---
# <a name="how-to-specify-an-out-parameter"></a>Como especificar um parâmetro out

Este exemplo mostra como especificar que um parâmetro de função é um `out` parâmetro e como chamar essa função de um C# programa.

Um parâmetro `out` é especificado no C++ usando <xref:System.Runtime.InteropServices.OutAttribute>.

## <a name="example"></a>Exemplo

A primeira parte deste exemplo cria uma C++ dll. Ele define um tipo que contém uma função com um parâmetro `out`.

```cpp
// cpp_out_param.cpp
// compile with: /LD /clr
using namespace System;
public value struct TestStruct {
   static void Test([Runtime::InteropServices::Out] String^ %s) {
      s = "a string";
   }
};
```

Esse arquivo de origem é C# um cliente que consome o C++ componente criado no exemplo anterior.

```csharp
// cpp_out_param_2.cs
// compile with: /reference:cpp_out_param.dll
using System;
class TestClass {
   public static void Main() {
      String t;
      TestStruct.Test(out t);
      System.Console.WriteLine(t);
   }
}
```

```Output
a string
```

## <a name="see-also"></a>Veja também

[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)
