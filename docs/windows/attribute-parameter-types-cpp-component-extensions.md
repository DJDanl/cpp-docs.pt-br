---
title: Tipos de parâmetro de atributo (C + + c++ /CLI e c++ /CLI CX) | Microsoft Docs
ms.custom: ''
ms.date: 10/12/2018
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- custom attributes, parameter types
ms.assetid: d9f127a3-7f08-456f-acc6-256805632712
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8db82e2b31984429165ce39a328abc28ba6e2cfd
ms.sourcegitcommit: 3f4e92266737ecb70507871e87dc8e2965ad7e04
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/15/2018
ms.locfileid: "49328162"
---
# <a name="attribute-parameter-types--ccli-and-ccx"></a>Tipos de parâmetro de atributo (C + + c++ /CLI e c++ /CLI CX)

Valores passados para atributos devem ser conhecidos para o compilador em tempo de compilação.  Parâmetros de atributo podem ser dos seguintes tipos:

- **bool**

- **char**, **unsigned char**

- **short**, **unsigned short**

- **int**, **int sem sinal**

- **longo**, **unsigned long**

- **__int64**, **__int64 sem sinal**

- **float**, **duplo**

- **wchar_t**

- `char*` ou `wchar_t*` ou `System::String*`

- `System::Type ^`

- `System::Object ^`

- **enum**

## <a name="example"></a>Exemplo

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

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

Ao especificar atributos, todos os argumentos (posicionais) sem nome devem preceder argumentos nomeados.

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

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

Parâmetros de atributo podem ser matrizes unidimensionais de tipos anteriores.

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

## <a name="see-also"></a>Consulte também

[Atributos definidos pelo usuário](../windows/user-defined-attributes-cpp-component-extensions.md)