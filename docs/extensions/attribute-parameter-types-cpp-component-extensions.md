---
title: Tipos de parâmetro de atributo (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- custom attributes, parameter types
ms.assetid: d9f127a3-7f08-456f-acc6-256805632712
ms.openlocfilehash: cf33014c455bef145f7b7ec7ee353f27d1157f24
ms.sourcegitcommit: 43cee7a0d41a062661229043c2f7cbc6ace17fa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/13/2020
ms.locfileid: "92008599"
---
# <a name="attribute-parameter-types--ccli-and-ccx"></a>Tipos de parâmetro de atributo (C++/CLI e C++/CX)

Os valores passados ​​para atributos devem ser conhecidos para o compilador no tempo de compilação.  Os parâmetros de atributos podem ser dos seguintes tipos:

- **`bool`**

- **`char`**, **`unsigned char`**

- **`short`**, **`unsigned short`**

- **`int`**, **`unsigned int`**

- **`long`**, **`unsigned long`**

- **`__int64`**, **__int64 não assinado**

- **`float`**, **`double`**

- **`wchar_t`**

- **`char*`** ou `wchar_t*` ou `System::String*`

- `System::Type ^`

- `System::Object ^`

- **`enum`**

## <a name="example-attribute-parameter-types"></a>Exemplo: tipos de parâmetro de atributo

### <a name="code"></a>Código

```cpp
// attribute_parameter_types.cpp
// compile with: /clr /c
using namespace System;
ref struct AStruct {};

[AttributeUsage(AttributeTargets::ReturnValue)]
ref struct Attr : public Attribute {
   Attr(AStruct ^ i){}
   Attr(bool i){}
   Attr(){}
};

ref struct MyStruct {
   static AStruct ^ x = gcnew AStruct;
   [returnvalue:Attr(x)] int Test() { return 0; }   // C3104
   [returnvalue:Attr] int Test2() { return 0; }   // OK
   [returnvalue:Attr(true)] int Test3() { return 0; }   // OK
};
```

## <a name="example-unnamed-arguments-precede-named-arguments"></a>Exemplo: argumentos sem nome precedem argumentos nomeados

### <a name="description"></a>Description

Ao especificar atributos, todos os argumentos não nomeados (posicionais) devem preceder quaisquer argumentos nomeados.

### <a name="code"></a>Código

```cpp
// extending_metadata_c.cpp
// compile with: /clr /c
using namespace System;
[AttributeUsage(AttributeTargets::Class)]
ref class MyAttr : public Attribute {
public:
   MyAttr() {}
   MyAttr(int i) {}
   property int Priority;
   property int Version;
};

[MyAttr]
ref class ClassA {};   // No arguments

[MyAttr(Priority = 1)]
ref class ClassB {};   // Named argument

[MyAttr(123)]
ref class ClassC {};   // Positional argument

[MyAttr(123, Version = 1)]
ref class ClassD {};   // Positional and named
```

## <a name="example-one-dimensional-array-attribute-parameter"></a>Exemplo: parâmetro de atributo de matriz unidimensional

### <a name="description"></a>Description

Parâmetros de atributos podem ser matrizes unidimensionais dos tipos anteriores.

### <a name="code"></a>Código

```cpp
// extending_metadata_d.cpp
// compile with: /clr /c
using namespace System;

[AttributeUsage(AttributeTargets::Class)]
public ref struct ABC : public Attribute {
   ABC(array<int>^){}
   array<double> ^ param;
};

[ABC( gcnew array<int> {1,2,3}, param = gcnew array<double>{2.71, 3.14})]
ref struct AStruct{};
```

## <a name="see-also"></a>Veja também

[Atributos definidos pelo usuário](user-defined-attributes-cpp-component-extensions.md)
