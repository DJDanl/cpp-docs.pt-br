---
title: Como especificar um parâmetro out
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- function parameters
- out parameters
ms.assetid: 02862448-603c-4e9d-a5c5-b45fe38446e3
ms.openlocfilehash: 8c3499a2916eda7ab96f7958df190c803206741e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50437059"
---
# <a name="how-to-specify-an-out-parameter"></a>Como especificar um parâmetro out

Este exemplo mostra como especificar que um parâmetro de função é um parâmetro de saída e como chamar essa função de um programa c#.

Um parâmetro de saída é especificado no Visual C++ com <xref:System.Runtime.InteropServices.OutAttribute> .

## <a name="example"></a>Exemplo

A primeira parte deste exemplo é uma DLL do Visual C++ com um tipo que contém uma função com um parâmetro de saída.

```
// cpp_out_param.cpp
// compile with: /LD /clr:safe
using namespace System;
public value struct TestStruct {
   static void Test([Runtime::InteropServices::Out] String^ %s) {
      s = "a string";
   }
};
```

## <a name="example"></a>Exemplo

Esse é um cliente c# que consome o componente do Visual C++ criado no exemplo anterior.

```
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

## <a name="see-also"></a>Consulte também

[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)