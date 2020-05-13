---
title: Listas de Argumentos Variáveis (...) (C++/CLI)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- variable argument lists
- parameter arrays
ms.assetid: db1a27f4-02a8-4318-8690-1f2893f52b38
ms.openlocfilehash: 8ea4d71bf9a22fc96c794a92ba43bed6548cf5d1
ms.sourcegitcommit: 89d9e1cb08fa872483d1cde98bc2a7c870e505e9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "82032298"
---
# <a name="variable-argument-lists--ccli"></a>Listas de Argumentos Variáveis (...) (C++/CLI)

Este exemplo mostra como você pode usar a sintaxe `...` em C++/CLI para implementar funções que tenham um número variável de argumentos.

> [!NOTE]
> Este tópico refere-se a C++/CLI. Para obter informações `...` sobre como usar o padrão ISO C++, consulte [Ellipsis e modelos variados](../cpp/ellipses-and-variadic-templates.md) e Ellipsis e argumentos padrão em [expressões Postfix](../cpp/postfix-expressions.md).

O parâmetro que usa `...` deve ser o último parâmetro na lista de parâmetros.

## <a name="example"></a>Exemplo

### <a name="code"></a>Código

```cpp
// mcppv2_paramarray.cpp
// compile with: /clr
using namespace System;
double average( ... array<Int32>^ arr ) {
   int i = arr->GetLength(0);
   double answer = 0.0;

   for (int j = 0 ; j < i ; j++)
      answer += arr[j];

   return answer / i;
}

int main() {
   Console::WriteLine("{0}", average( 1, 2, 3, 6 ));
}
```

```Output
3
```

## <a name="code-example"></a>Exemplo de código

O exemplo a seguir mostra como chamar uma função do Visual C++ que leva um número variável de argumentos a partir de C#.

```cpp
// mcppv2_paramarray2.cpp
// compile with: /clr:safe /LD
using namespace System;

public ref class C {
public:
   void f( ... array<String^>^ a ) {}
};
```

A função `f` pode ser chamada de C# ou Visual Basic, por exemplo, como se fosse uma função que pode receber um número variável de argumentos.

Em C#, um argumento que é passado para um parâmetro `ParamArray` pode ser chamado por um número variável de argumentos. O exemplo de código a seguir está em C#.

```csharp
// mcppv2_paramarray3.cs
// compile with: /r:mcppv2_paramarray2.dll
// a C# program

public class X {
   public static void Main() {
      // Visual C# will generate a String array to match the
      // ParamArray attribute
      C myc = new C();
      myc.f("hello", "there", "world");
   }
}
```

Uma chamada para `f` no Visual C++ pode transmitir uma matriz inicializada ou uma matriz de comprimento variável.

```cpp
// mcpp_paramarray4.cpp
// compile with: /clr
using namespace System;

public ref class C {
public:
   void f( ... array<String^>^ a ) {}
};

int main() {
   C ^ myc = gcnew C();
   myc->f("hello", "world", "!!!");
}
```

## <a name="see-also"></a>Confira também

[Matrizes](arrays-cpp-component-extensions.md)
