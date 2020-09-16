---
title: literal (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- literal
- literal_cpp
helpviewer_keywords:
- literal keyword [C++]
ms.assetid: 6b1a1f36-2e1d-4a23-8eb6-172f4f3c477f
ms.openlocfilehash: 2687352c02bed609ffaa60ee8b1df40b51126d21
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686724"
---
# <a name="literal-ccli-and-ccx"></a>literal (C++/CLI e C++/CX)

Uma variável (membro de dados) marcada como **literal** em uma compilação **/clr** é o equivalente nativo de uma variável **static const**.

## <a name="all-platforms"></a>Todas as plataformas

### <a name="remarks"></a>Comentários

(Não há comentários para esse recurso de linguagem que se apliquem a todos os runtimes.)

## <a name="windows-runtime"></a>Windows Runtime

### <a name="remarks"></a>Comentários

(Não há comentários para esse recurso de linguagem que se apliquem somente ao Windows Runtime.)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

## <a name="remarks"></a>Comentários

Um membro de dados marcado como **literal** deve ser inicializado quando declarado, e o valor deve ser um tipo de cadeia, enumeração ou integral constante. A conversão do tipo da expressão de inicialização no tipo do membro de dados const estático não deve exigir uma conversão definida pelo usuário.

Nenhuma memória é alocada para o campo literal em runtime. O compilador só insere seu valor nos metadados da classe.

Uma variável marcada como **static const** não estará disponível em metadados para outros compiladores.

Confira mais informações em [Static](../cpp/storage-classes-cpp.md) e [const](../cpp/const-cpp.md).

**literal** é uma palavra-chave sensível ao contexto. Confira mais informações em [Palavras-chave sensíveis ao contexto](context-sensitive-keywords-cpp-component-extensions.md).

## <a name="examples"></a>Exemplos

Este exemplo mostra que uma variável **literal** implica **`static`** .

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

O exemplo a seguir mostra o efeito do literal nos metadados:

```cpp
// mcppv2_literal2.cpp
// compile with: /clr /LD
public ref struct A {
   literal int lit = 0;
   static const int sc = 1;
};
```

Observe a diferença nos metadados para `sc` e `lit`: a diretiva `modopt` é aplicada a `sc`, o que significa que pode ser ignorada por outros compiladores.

```
.field public static int32 modopt([mscorlib]System.Runtime.CompilerServices.IsConst) sc = int32(0x0000000A)
```

```
.field public static literal int32 lit = int32(0x0000000A)
```

A amostra a seguir, criada em C#, faz referência aos metadados criados na amostra anterior e mostra o efeito das variáveis **literal** e **static const**:

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

## <a name="see-also"></a>Confira também

[Extensões de componente para .NET e UWP](component-extensions-for-runtime-platforms.md)
