---
title: TypeId (C + + c++ /CLI e c++ /CLI CX) | Microsoft Docs
ms.custom: ''
ms.date: 10/12/2018
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- typeid keyword [C++]
ms.assetid: e9706cae-e7c4-4d6d-b474-646d73df3e70
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1196956208d490674d4705a8d1e61ea3381d94a2
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50065181"
---
# <a name="typeid--ccli-and-ccx"></a>TypeId (C + + c++ /CLI e c++ /CLI CX)

Obtém um valor que indica o tipo de um objeto.

> [!NOTE]
> Este tópico refere-se para a versão de extensões de componentes C++ do typeid. Para obter a versão ISO C++ essa palavra-chave, consulte [operador typeid](../cpp/typeid-operator.md).

## <a name="all-runtimes"></a>Todos os Tempos de Execução

### <a name="syntax"></a>Sintaxe

```cpp
T::typeid
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O nome de um tipo.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="syntax"></a>Sintaxe

```cpp
Platform::Type^ type = T::typeid;
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
O nome de um tipo.

### <a name="remarks"></a>Comentários

No C + + c++ /CLI typeid CX, retorna um [Platform:: Type](../cppcx/platform-type-class.md) que é construído a partir de informações de tipo de tempo de execução.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="syntax"></a>Sintaxe

```
type::typeid
```

### <a name="parameters"></a>Parâmetros

*type*<br/>
O nome de um tipo (declarador abstrato) para o qual você deseja o `System::Type` objeto.

### <a name="remarks"></a>Comentários

`typeid` é usado para obter o <xref:System.Type> para um tipo em tempo de compilação.

`typeid` é semelhante à obtenção de System:: Type para um tipo em tempo de execução usando <xref:System.Type.GetType%2A> ou <xref:System.Object.GetType%2A>. No entanto, o typeid só aceita um nome de tipo como um parâmetro.  Se você quiser usar uma instância de um tipo para obter seu nome de System:: Type, use GetType.

`typeid` deve ser capaz de avaliar um nome de tipo (tipo) no tempo de compilação, enquanto GetType avalia o tipo a ser retornado em tempo de execução.

`typeid` pode levar um nome de tipo nativo ou o alias de tempo de execução de linguagem comum para o nome de tipo nativo; ver [equivalentes do .NET Framework para tipos nativos do C++ (C + + / CLI)](../dotnet/dotnet-framework-equivalents-to-cpp-native-types-cpp-cli.md) para obter mais informações.

`typeid` também funciona com tipos nativos, embora ainda retornará um System:: Type.  Para obter uma estrutura type_info, use [operador typeid](../cpp/typeid-operator.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo a seguir compara a palavra-chave typeid para o `GetType()` membro.

```cpp
// keyword__typeid.cpp
// compile with: /clr
using namespace System;

ref struct G {
   int i;
};

int main() {
   G ^ pG = gcnew G;
   Type ^ pType = pG->GetType();
   Type ^ pType2 = G::typeid;

   if (pType == pType2)
      Console::WriteLine("typeid and GetType returned the same System::Type");
   Console::WriteLine(G::typeid);

   typedef float* FloatPtr;
   Console::WriteLine(FloatPtr::typeid);
}
```

```Output
typeid and GetType returned the same System::Type
G

System.Single*
```

O exemplo a seguir mostra que uma variável do tipo que System:: Type pode ser usado para obter os atributos em um tipo.  Ele também mostra que para alguns tipos, você terá que criar um typedef para usar `typeid`.

```cpp
// keyword__typeid_2.cpp
// compile with: /clr
using namespace System;
using namespace System::Security;
using namespace System::Security::Permissions;

typedef int ^ handle_to_int;
typedef int * pointer_to_int;

public ref class MyClass {};

class MyClass2 {};

[attribute(AttributeTargets::All)]
ref class AtClass {
public:
   AtClass(Type ^) {
      Console::WriteLine("in AtClass Type ^ constructor");
   }
};

[attribute(AttributeTargets::All)]
ref class AtClass2 {
public:
   AtClass2() {
      Console::WriteLine("in AtClass2 constructor");
   }
};

// Apply the AtClass and AtClass2 attributes to class B
[AtClass(MyClass::typeid), AtClass2]
[AttributeUsage(AttributeTargets::All)]
ref class B : Attribute {};

int main() {
   Type ^ MyType = B::typeid;

   Console::WriteLine(MyType->IsClass);

   array<Object^>^ MyArray = MyType -> GetCustomAttributes(true);
   for (int i = 0 ; i < MyArray->Length ; i++ )
      Console::WriteLine(MyArray[i]);

   if (int::typeid != pointer_to_int::typeid)
      Console::WriteLine("int::typeid != pointer_to_int::typeid, as expected");

   if (int::typeid == handle_to_int::typeid)
      Console::WriteLine("int::typeid == handle_to_int::typeid, as expected");
}
```

```Output
True

in AtClass2 constructor

in AtClass Type ^ constructor

AtClass2

System.AttributeUsageAttribute

AtClass

int::typeid != pointer_to_int::typeid, as expected

int::typeid == handle_to_int::typeid, as expected
```

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)