---
title: literal (C++/CLI)
description: A palavra-chave literal é uma palavra-chave sensível ao contexto do Microsoft C++/CLI para uma constante de tempo de compilação.
ms.date: 10/20/2020
ms.topic: reference
f1_keywords:
- literal
- literal_cpp
helpviewer_keywords:
- literal keyword [C++]
ms.openlocfilehash: 2d71a535252ba51f89407670b474a34b407eaffc
ms.sourcegitcommit: 59b7c18703d1ffd66827db0e2eeece490d3d8789
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2020
ms.locfileid: "92337207"
---
# <a name="literal-ccli"></a>`literal` (C++/CLI)

Uma variável (membro de dados) marcada como **`literal`** em uma **`/clr`** compilação é uma constante de tempo de compilação. É o equivalente nativo de uma variável C# [`const`](/dotnet/csharp/language-reference/keywords/const) .

## <a name="all-platforms"></a>Todas as plataformas

### <a name="remarks"></a>Comentários

(Não há comentários para esse recurso de linguagem que se apliquem a todos os runtimes.)

## <a name="windows-runtime"></a>Windows Runtime

### <a name="remarks"></a>Comentários

(Não há comentários para esse recurso de linguagem que se apliquem somente ao Windows Runtime.)

## <a name="common-language-runtime"></a>Common Language Runtime

## <a name="remarks"></a>Comentários

Um membro de dados marcado como **`literal`** deve ser inicializado quando declarado. E, o valor deve ser um tipo inteiro, de enumeração ou de cadeia de caracteres constante. A conversão do tipo da expressão de inicialização para o tipo do **`literal`** membro de dados não pode exigir uma conversão definida pelo usuário.

Nenhuma memória é alocada para o **`literal`** campo em tempo de execução; o compilador só insere seu valor nos metadados da classe. O **`literal`** valor é tratado como uma constante de tempo de compilação. O equivalente mais próximo no C++ padrão é **`constexpr`** , mas um membro de dados não pode estar **`constexpr`** em c++/CLI.

Uma variável marcada como **`literal`** difere de uma marcada **`static const`** . Um **`static const`** membro de dados não é disponibilizado em metadados para outros compiladores. Para obter mais informações, confira [`static`](../cpp/storage-classes-cpp.md) e [`const`](../cpp/const-cpp.md).

**`literal`** é uma palavra-chave sensível ao contexto. Para obter mais informações, consulte [palavras-chave sensíveis ao contexto](context-sensitive-keywords-cpp-component-extensions.md).

## <a name="examples"></a>Exemplos

Este exemplo mostra que uma **`literal`** variável implica **`static`** .

```cpp
// mcppv2_literal.cpp
// compile with: /clr
ref struct X {
   literal int i = 4;
};

int main() {
   int value = X::i;
}
```

O exemplo a seguir mostra o efeito de **`literal`** nos metadados:

```cpp
// mcppv2_literal2.cpp
// compile with: /clr /LD
public ref struct A {
   literal int lit = 0;
   static const int sc = 1;
};
```

Observe a diferença nos metadados para `sc` e `lit`: a diretiva `modopt` é aplicada a `sc`, o que significa que pode ser ignorada por outros compiladores.

```MSIL
.field public static int32 modopt([mscorlib]System.Runtime.CompilerServices.IsConst) sc = int32(0x00000001)
```

```MSIL
.field public static literal int32 lit = int32(0x00000000)
```

O exemplo a seguir, criado em C#, faz referência aos metadados criados no exemplo anterior e mostra o efeito de **`literal`** **`static const`** variáveis e:

```csharp
// mcppv2_literal3.cs
// compile with: /reference:mcppv2_literal2.dll
// A C# program
class B {
   public static void Main() {
      // OK
      System.Console.WriteLine(A.lit);
      System.Console.WriteLine(A.sc);

      // C# does not enforce C++ const
      A.sc = 9;
      System.Console.WriteLine(A.sc);

      // C# enforces const for a literal
      A.lit = 9;   // CS0131

      // you can assign a C++ literal variable to a C# const variable
      const int i = A.lit;
      System.Console.WriteLine(i);

      // but you cannot assign a C++ static const variable
      // to a C# const variable
      const int j = A.sc;   // CS0133
      System.Console.WriteLine(j);
   }
}
```

## <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

## <a name="see-also"></a>Veja também

[Extensões de componente para .NET e UWP](component-extensions-for-runtime-platforms.md)
