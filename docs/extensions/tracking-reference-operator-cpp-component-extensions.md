---
title: Operador de referência de acompanhamento (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- '%'
helpviewer_keywords:
- tracking references
- '% tracking reference [C++]'
ms.assetid: 142a7269-ab69-4b54-a6d7-833bef06228f
ms.openlocfilehash: c6fef4562545b03e212d0e4e58742a1209a6ab81
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65516011"
---
# <a name="tracking-reference-operator-ccli-and-ccx"></a>Operador de referência de acompanhamento (C++/CLI e C++/CX)

Uma *referência de acompanhamento* (`%`) se comporta como uma referência comum do C++ (`&`), exceto que quando um objeto é atribuído a uma referência de acompanhamento, a contagem de referência do objeto é incrementada.

## <a name="all-platforms"></a>Todas as Plataformas

Uma referência de acompanhamento possui as características a seguir.

- A atribuição de um objeto a uma referência de acompanhamento faz com que a contagem de referência do objeto seja incrementada.

- Uma referência nativa (`&`) é o resultado quando você desfaz uma referência a um `*`. Uma referência de acompanhamento (`%`) é o resultado quando você desfaz uma referência a um `^`. Contanto que você tenha um `%` para um objeto, o objeto permanecerá vivo na memória.

- O operador de acesso de membro dot (`.`) é usado para acessar um membro do objeto.

- As referências de acompanhamento são válidas para tipos de valores e identificadores (por exemplo, `String^`).

- Uma referência de acompanhamento não pode receber um valor null ou **nullptr**. Uma referência de acompanhamento pode ser reatribuída a outro objeto válido quantas vezes for necessário.

- Uma referência de acompanhamento não pode ser usada como um operador take-address unário.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

Uma referência de acompanhamento se comporta como uma referência padrão do C++, exceto pelo fato de que um % é contado por referência. O trecho de código a seguir mostra como converter entre os tipos % e ^:

```cpp
Foo^ spFoo = ref new Foo();
Foo% srFoo = *spFoo;
Foo^ spFoo2 = %srFoo;
```

O exemplo a seguir mostra como passar um ^ para uma função que recebe um %.

```cpp
ref class Foo sealed {};

    // internal or private
    void UseFooHelper(Foo% f)
    {
        auto x = %f;
    }

    // public method on ABI boundary
    void UseFoo(Foo^ f)
    {
        if (f != nullptr) { UseFooHelper(*f); }
    }
```

## <a name="common-language-runtime"></a>Common Language Runtime

No C++ ou na CLI, é possível usar uma referência de acompanhamento para um identificador ao vincular-se a um objeto de um tipo CLR no heap coletado como lixo.

No CLR, o valor de uma variável de referência de acompanhamento é atualizado automaticamente sempre que o coletor de lixo move o objeto referenciado.

Uma referência de acompanhamento pode ser declarada apenas na pilha. Uma referência de acompanhamento não pode ser um membro de uma classe.

Não é possível ter uma referência de C++ nativa para um objeto no heap coletado como lixo.

Saiba mais sobre referências de acompanhamento no C++/CLI em:

- [Como: usar referências de rastreamento no C++/CLI](../dotnet/how-to-use-tracking-references-in-cpp-cli.md)

### <a name="examples"></a>Exemplos

O exemplo a seguir para C++/CLI mostra como usar uma referência de acompanhamento com tipos nativos e gerenciados.

```cpp
// tracking_reference_1.cpp
// compile with: /clr
ref class MyClass {
public:
   int i;
};

value struct MyStruct {
   int k;
};

int main() {
   MyClass ^ x = ref new MyClass;
   MyClass ^% y = x;   // tracking reference handle to reference object

   int %ti = x->i;   // tracking reference to member of reference type

   int j = 0;
   int %tj = j;   // tracking reference to object on the stack

   int * pi = new int[2];
   int % ti2 = pi[0];   // tracking reference to object on native heap

   int *% tpi = pi;   // tracking reference to native pointer

   MyStruct ^ x2 = ref new MyStruct;
   MyStruct ^% y2 = x2;   // tracking reference to value object

   MyStruct z;
   int %tk = z.k;   // tracking reference to member of value type

   delete[] pi;
}
```

O exemplo a seguir para C++/CLI mostra como vincular uma referência de acompanhamento a uma matriz.

```cpp
// tracking_reference_2.cpp
// compile with: /clr
using namespace System;

int main() {
   array<int> ^ a = ref new array<Int32>(5);
   a[0] = 21;
   Console::WriteLine(a[0]);
   array<int> ^% arr = a;
   arr[0] = 222;
   Console::WriteLine(a[0]);
}
```

```Output
21
222
```