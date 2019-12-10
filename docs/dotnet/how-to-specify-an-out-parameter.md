---
title: Como especificar um parâmetro out
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- function parameters
- out parameters
ms.assetid: 02862448-603c-4e9d-a5c5-b45fe38446e3
ms.openlocfilehash: 5f0b462e672de4408d50bf95d65c749bf1881078
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988431"
---
# <a name="how-to-specify-an-out-parameter"></a>Como especificar um parâmetro out

Este exemplo mostra como especificar que um parâmetro de função é um parâmetro out e como chamar essa função de um C# programa.

Um parâmetro out é especificado no Visual C++ com <xref:System.Runtime.InteropServices.OutAttribute>.

## <a name="example"></a>Exemplo

A primeira parte deste exemplo é uma DLL Visual C++ com um tipo que contém uma função com um parâmetro out.

```cpp
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

Esse é um C# cliente que consome o componente Visual C++ criado no exemplo anterior.

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
