---
title: nullptr  (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- __nullptr keyword (C++)
- nullptr keyword [C++]
ms.assetid: 594cfbf7-06cb-4366-9ede-c0b703e1d095
ms.openlocfilehash: 05aaaa8a0d0056e0f5318f5e9329d90824760728
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65515631"
---
# <a name="nullptr--ccli-and-ccx"></a>nullptr  (C++/CLI e C++/CX)

A palavra-chave **nullptr** representa um *valor de ponteiro nulo*. Use um valor de ponteiro nulo para indicar que um tipo de identificador de objeto, ponteiro interno ou ponteiro nativo não aponta para um objeto.

Use **nullptr** com código gerenciado ou nativo. O compilador emite instruções apropriadas, mas diferentes, para valores de ponteiro nulo gerenciados e nativos. Confira mais informações sobre como usar a versão C++ do padrão ISO dessa palavra-chave em [nullptr](../cpp/nullptr.md).

A palavra-chave **__nullptr** é específica da Microsoft e tem o mesmo significado que **nullptr**, mas aplica-se somente a um código nativo. Se você usar **nullptr** com código C/C++ nativo e, em seguida, compilar com a opção do compilador [/clr](../build/reference/clr-common-language-runtime-compilation.md), o compilador não conseguirá determinar se **nullptr** indica um valor de ponteiro nulo nativo ou gerenciado. Para tornar sua intenção clara para o compilador, use **nullptr** para especificar um valor gerenciado ou **__nullptr** para especificar um valor nativo.

A palavra-chave **nullptr** é equivalente a **Nothing** no Visual Basic e **null** em C#.

## <a name="usage"></a>Uso

A palavra-chave **nullptr** pode ser usada em qualquer lugar em que um identificador, um ponteiro ou uma função possa ser usado.

A palavra-chave **nullptr** não é um tipo e não é compatível com:

- [sizeof](../cpp/sizeof-operator.md)

- [typeid](../cpp/typeid-operator.md)

- `throw nullptr` (embora `throw (Object^)nullptr;` funcione)

A palavra-chave **nullptr** pode ser usada na inicialização dos seguintes tipos de ponteiro:

- Ponteiro nativo

- Identificador do Windows Runtime

- Identificador gerenciado

- Ponteiro interno gerenciado

A palavra-chave **nullptr** pode ser usada para testar se uma referência de ponteiro ou identificador é nula antes de essa referência ser usada.

Chamadas de função entre linguagens que usam valores de ponteiro nulo para verificação de erros devem ser interpretadas corretamente.

Você não pode inicializar um identificador para zero. Somente **nullptr** pode ser usado. A atribuição da constante 0 a um identificador de objeto produz um `Int32` com conversão boxing e uma conversão em `Object^`.

## <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra que a palavra-chave **nullptr** pode ser usada sempre que um identificador, um ponteiro nativo ou um argumento de função pode ser usado. Além disso, ele demonstra que a palavra-chave **nullptr** pode ser usada para verificar uma referência antes que esta seja usada.

```cpp
// mcpp_nullptr.cpp
// compile with: /clr
value class V {};
ref class G {};
void f(System::Object ^) {}

int main() {
// Native pointer.
   int *pN = nullptr;
// Managed handle.
   G ^pG = nullptr;
   V ^pV1 = nullptr;
// Managed interior pointer.
   interior_ptr<V> pV2 = nullptr;
// Reference checking before using a pointer.
   if (pN == nullptr) {}
   if (pG == nullptr) {}
   if (pV1 == nullptr) {}
   if (pV2 == nullptr) {}
// nullptr can be used as a function argument.
   f(nullptr);   // calls f(System::Object ^)
}
```

## <a name="example"></a>Exemplo

O exemplo de código a seguir mostra que **nullptr** e zero podem ser usados alternadamente em ponteiros nativos.

```cpp
// mcpp_nullptr_1.cpp
// compile with: /clr
class MyClass {
public:
   int i;
};

int main() {
   MyClass * pMyClass = nullptr;
   if ( pMyClass == nullptr)
      System::Console::WriteLine("pMyClass == nullptr");

   if ( pMyClass == 0)
      System::Console::WriteLine("pMyClass == 0");

   pMyClass = 0;
   if ( pMyClass == nullptr)
      System::Console::WriteLine("pMyClass == nullptr");

   if ( pMyClass == 0)
      System::Console::WriteLine("pMyClass == 0");
}
```

```Output
pMyClass == nullptr

pMyClass == 0

pMyClass == nullptr

pMyClass == 0
```

## <a name="example"></a>Exemplo

O exemplo de código a seguir mostra que **nullptr** é interpretada como um identificador para qualquer tipo ou um ponteiro nativo para qualquer tipo. Em caso de sobrecarga de função com identificadores para tipos diferentes, um erro de ambiguidade será gerado. A palavra-chave **nullptr** teria que ser explicitamente convertida em um tipo.

```cpp
// mcpp_nullptr_2.cpp
// compile with: /clr /LD
void f(int *){}
void f(int ^){}

void f_null() {
   f(nullptr);   // C2668
   // try one of the following lines instead
   f((int *) nullptr);
   f((int ^) nullptr);
}
```

## <a name="example"></a>Exemplo

O exemplo de código a seguir mostra que a conversão de **nullptr** é permitida e retorna um ponteiro ou identificador para o tipo de conversão que contém o valor **nullptr**.

```cpp
// mcpp_nullptr_3.cpp
// compile with: /clr /LD
using namespace System;
template <typename T>
void f(T) {}   // C2036 cannot deduce template type because nullptr can be any type

int main() {
   f((Object ^) nullptr);   // T = Object^, call f(Object ^)

   // Delete the following line to resolve.
   f(nullptr);

   f(0);   // T = int, call f(int)
}
```

## <a name="example"></a>Exemplo

O exemplo de código a seguir mostra que **nullptr** pode ser usado como um parâmetro de função.

```cpp
// mcpp_nullptr_4.cpp
// compile with: /clr
using namespace System;
void f(Object ^ x) {
   Console::WriteLine("test");
}

int main() {
   f(nullptr);
}
```

```Output
test
```

## <a name="example"></a>Exemplo

O exemplo de código a seguir mostra que, quando identificadores são declarados e não são inicializados explicitamente, eles são inicializados por padrão como **nullptr**.

```cpp
// mcpp_nullptr_5.cpp
// compile with: /clr
using namespace System;
ref class MyClass {
public:
   void Test() {
      MyClass ^pMyClass;   // gc type
      if (pMyClass == nullptr)
         Console::WriteLine("NULL");
   }
};

int main() {
   MyClass ^ x = gcnew MyClass();
   x -> Test();
}
```

```Output
NULL
```

## <a name="example"></a>Exemplo

O exemplo de código a seguir mostra que **nullptr** pode ser atribuído a um ponteiro nativo quando você compila com `/clr`.

```cpp
// mcpp_nullptr_6.cpp
// compile with: /clr
int main() {
   int * i = 0;
   int * j = nullptr;
}
```

## <a name="requirements"></a>Requisitos

Opção do compilador: (Não é necessário. É compatível com todas as opções de geração de código, incluindo `/ZW` e `/clr`)

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)<br/>
[nullptr](../cpp/nullptr.md)