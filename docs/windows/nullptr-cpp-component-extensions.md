---
title: nullptr (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- __nullptr keyword (C++)
- nullptr keyword [C++]
ms.assetid: 594cfbf7-06cb-4366-9ede-c0b703e1d095
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0596276589790ee6fae8e071e50b4d9b55dd8b85
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46439608"
---
# <a name="nullptr--c-component-extensions"></a>nullptr (Extensões de Componentes C++)

O **nullptr** palavra-chave representa um *valor de ponteiro nulo*. Use um valor de ponteiro nulo para indicar que um identificador de objeto, ponteiro interior ou tipo de ponteiro nativo não aponta para um objeto.

Use **nullptr** com código gerenciado ou nativo. O compilador emite instruções apropriadas, mas diferentes para valores de ponteiro nulo gerenciado e nativo. Para obter informações sobre como usar a versão de C++ padrão ISO dessa palavra-chave, consulte [nullptr](../cpp/nullptr.md).

O **nullptr** palavra-chave é uma palavra-chave específicas da Microsoft que tem o mesmo significado que **nullptr**, mas aplica-se a somente código nativo. Se você usar **nullptr** com o C/C++ nativo de código e, em seguida, compile com o [/clr](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador, o compilador não pode determinar se **nullptr** indica um nativo ou gerenciado o valor de ponteiro nulo. Para tornar sua intenção clara para o compilador, use **nullptr** para especificar um valor gerenciado ou **nullptr** para especificar um valor nativo.

O **nullptr** palavra-chave é equivalente a **nada** no Visual Basic e **nulo** em c#.

## <a name="usage"></a>Uso

O **nullptr** palavra-chave pode ser usado em qualquer lugar em um identificador, um ponteiro nativo ou um argumento de função pode ser usado.

O **nullptr** palavra-chave não é um tipo e não há suporte para uso com:

- [sizeof](../cpp/sizeof-operator.md)

- [TypeId](../cpp/typeid-operator.md)

- `throw nullptr` (embora `throw (Object^)nullptr;` funcionará)

O **nullptr** palavra-chave pode ser usado na inicialização dos seguintes tipos de ponteiro:

- Ponteiro nativo

- Identificador de tempo de execução do Windows

- Identificador gerenciado

- Ponteiro interior gerenciado

O **nullptr** palavra-chave pode ser usado para testar se uma referência de ponteiro ou identificador for nula, antes que a referência é usada.

Chamadas de função entre os idiomas que usam valores de ponteiro nulo para verificação de erro devem ser interpretadas corretamente.

Você não pode inicializar um identificador para zero. somente **nullptr** pode ser usado. Atribuição de constante 0 para um identificador de objeto produz um demarcado `Int32` e uma conversão para `Object^`.

## <a name="example"></a>Exemplo

O exemplo de código a seguir demonstra que o **nullptr** palavra-chave pode ser usada sempre que um identificador de ponteiro nativo, ou o argumento de função pode ser usado. E o exemplo demonstra que o **nullptr** palavra-chave pode ser usado para verificar uma referência antes de ser usada.

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

O exemplo de código a seguir mostra que **nullptr** e zero pode ser usado alternadamente em ponteiros nativos.

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

O exemplo de código a seguir mostra que **nullptr** é interpretado como um identificador para qualquer tipo ou um ponteiro nativo para qualquer tipo. No caso de sobrecarga com alças para diferentes tipos de funções, será gerado um erro de ambiguidade. O **nullptr** teria que ser explicitamente convertido em um tipo.

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

O exemplo de código a seguir mostra essa conversão **nullptr** é permitido e retorna um ponteiro ou identificador para o tipo de conversão que contém o **nullptr** valor.

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

O exemplo de código a seguir mostra que, quando identificadores são declarados e não explicitamente inicializados, eles são padrão inicializado para **nullptr**.

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

O exemplo de código a seguir mostra que **nullptr** podem ser atribuídos a um ponteiro nativo quando você compilar com `/clr`.

```cpp
// mcpp_nullptr_6.cpp
// compile with: /clr
int main() {
   int * i = 0;
   int * j = nullptr;
}
```

## <a name="requirements"></a>Requisitos

Opção de compilador: (não obrigatório; compatíveis com todas as opções de geração de código, incluindo `/ZW` e `/clr`)

## <a name="see-also"></a>Consulte também

[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)<br/>
[nullptr](../cpp/nullptr.md)