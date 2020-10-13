---
title: nullptr  (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- __nullptr keyword (C++)
- nullptr keyword [C++]
ms.assetid: 594cfbf7-06cb-4366-9ede-c0b703e1d095
ms.openlocfilehash: 7e9cf88fdc0444f736f1cfac0d06dfc675a162cc
ms.sourcegitcommit: 43cee7a0d41a062661229043c2f7cbc6ace17fa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/13/2020
ms.locfileid: "92008354"
---
# <a name="nullptr--ccli-and-ccx"></a>nullptr  (C++/CLI e C++/CX)

A **`nullptr`** palavra-chave representa um *valor de ponteiro nulo*. Use um valor de ponteiro nulo para indicar que um tipo de identificador de objeto, ponteiro interno ou ponteiro nativo não aponta para um objeto.

Use **`nullptr`** o com código gerenciado ou nativo. O compilador emite instruções apropriadas, mas diferentes, para valores de ponteiro nulo gerenciados e nativos. Confira mais informações sobre como usar a versão C++ do padrão ISO dessa palavra-chave em [nullptr](../cpp/nullptr.md).

A palavra-chave **__nullptr** é uma palavra-chave específica da Microsoft que tem o mesmo significado que **`nullptr`** , mas se aplica somente a código nativo. Se você usar **`nullptr`** com código C/C++ nativo e depois compilar com a opção de compilador [/CLR](../build/reference/clr-common-language-runtime-compilation.md) , o compilador não poderá determinar se **`nullptr`** indica um valor de ponteiro NULL nativo ou gerenciado. Para tornar sua intenção clara para o compilador, use **`nullptr`** para especificar um valor gerenciado ou **__nullptr** para especificar um valor nativo.

A **`nullptr`** palavra-chave é equivalente a **Nothing** em Visual Basic e **NULL** em C#.

## <a name="usage"></a>Uso

A **`nullptr`** palavra-chave pode ser usada em qualquer lugar que um identificador, ponteiro nativo ou argumento de função possa ser usado.

A **`nullptr`** palavra-chave não é um tipo e não tem suporte para uso com:

- [sizeof](../cpp/sizeof-operator.md)

- [identificação](../cpp/typeid-operator.md)

- `throw nullptr` (embora `throw (Object^)nullptr;` funcione)

A **`nullptr`** palavra-chave pode ser usada na inicialização dos seguintes tipos de ponteiro:

- Ponteiro nativo

- Identificador do Windows Runtime

- Identificador gerenciado

- Ponteiro interno gerenciado

A **`nullptr`** palavra-chave pode ser usada para testar se uma referência de ponteiro ou identificador é nula antes de a referência ser usada.

Chamadas de função entre linguagens que usam valores de ponteiro nulo para verificação de erros devem ser interpretadas corretamente.

Não é possível inicializar um identificador para zero; **`nullptr`** pode ser usado somente. A atribuição da constante 0 a um identificador de objeto produz um `Int32` com conversão boxing e uma conversão em `Object^`.

## <a name="example-nullptr-keyword"></a>Exemplo: `nullptr` palavra-chave

O exemplo de código a seguir demonstra que a **`nullptr`** palavra-chave pode ser usada sempre que um identificador, ponteiro nativo ou argumento de função pode ser usado. E o exemplo demonstra que a **`nullptr`** palavra-chave pode ser usada para verificar uma referência antes de ser usada.

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

## <a name="example-use-nullptr-and-zero-interchangeably"></a>Exemplo: use `nullptr` e zero de forma intercambiável

O exemplo de código a seguir mostra que **`nullptr`** e zero podem ser usados de maneira intercambiável em ponteiros nativos.

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

## <a name="example-interpret-nullptr-as-a-handle"></a>Exemplo: interpretar `nullptr` como um identificador

O exemplo de código a seguir mostra que **`nullptr`** é interpretado como um identificador para qualquer tipo ou um ponteiro nativo para qualquer tipo. Em caso de sobrecarga de função com identificadores para tipos diferentes, um erro de ambiguidade será gerado. O **`nullptr`** teria que ser convertido explicitamente em um tipo.

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

## <a name="example-cast-nullptr"></a>Exemplo: Cast `nullptr`

O exemplo de código a seguir mostra que a conversão **`nullptr`** é permitida e retorna um ponteiro ou um identificador para o tipo de conversão que contém o **`nullptr`** valor.

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

## <a name="example-pass-nullptr-as-a-function-parameter"></a>Exemplo: passar `nullptr` como um parâmetro de função

O exemplo de código a seguir mostra que **`nullptr`** pode ser usado como um parâmetro de função.

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

## <a name="example-default-initialization"></a>Exemplo: inicialização padrão

O exemplo de código a seguir mostra que quando os identificadores são declarados e não são inicializados explicitamente, eles são inicializados como padrão para **`nullptr`** .

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

## <a name="example-assign-nullptr-to-a-native-pointer"></a>Exemplo: atribuir `nullptr` a um ponteiro nativo

O exemplo de código a seguir mostra que **`nullptr`** pode ser atribuído a um ponteiro nativo quando você compila com `/clr` .

```cpp
// mcpp_nullptr_6.cpp
// compile with: /clr
int main() {
   int * i = 0;
   int * j = nullptr;
}
```

## <a name="requirements"></a>Requisitos

Opção do compilador: (não é necessário; com suporte de todas as opções de geração de código, incluindo `/ZW` e `/clr` )

## <a name="see-also"></a>Veja também

[Extensões de componente para .NET e UWP](component-extensions-for-runtime-platforms.md)<br/>
[nullptr](../cpp/nullptr.md)
