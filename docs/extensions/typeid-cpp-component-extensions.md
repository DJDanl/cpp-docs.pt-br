---
title: typeid (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- typeid keyword [C++]
ms.assetid: e9706cae-e7c4-4d6d-b474-646d73df3e70
ms.openlocfilehash: 8b22481fecb4b7de5106921fec1c3a43fab81a48
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80181740"
---
# <a name="typeid--ccli-and-ccx"></a>typeid (C++/CLI e C++/CX)

Obtém um valor que indica o tipo de um objeto.

> [!NOTE]
> Este tópico refere-se à versão de extensões de componente C++ do typeid. Para a versão C++ do ISO dessa palavra-chave, confira [Operador typeid](../cpp/typeid-operator.md).

## <a name="all-runtimes"></a>Todos os Runtimes

### <a name="syntax"></a>Sintaxe

```cpp
T::typeid
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O nome de um tipo.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="syntax"></a>Sintaxe

```cpp
Platform::Type^ type = T::typeid;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O nome de um tipo.

### <a name="remarks"></a>Comentários

No C++/CX, typeid retorna um [Platform::Type](../cppcx/platform-type-class.md) que é construído a partir de informações de tipo do runtime.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="syntax"></a>Sintaxe

```
type::typeid
```

### <a name="parameters"></a>parâmetros

*tipo*<br/>
O nome de um tipo (declarador abstrato) para o qual você deseja o objeto `System::Type`.

### <a name="remarks"></a>Comentários

`typeid` é usado para obter o <xref:System.Type> para um tipo em tempo de compilação.

`typeid` é semelhante a obter o System::Type para um tipo em tempo de execução usando <xref:System.Type.GetType%2A> ou <xref:System.Object.GetType%2A>. No entanto, typeid aceita apenas um nome de tipo como um parâmetro.  Se quiser usar uma instância de um tipo para obter seu nome System::Type, use GetType.

`typeid` deve ser capaz de avaliar um nome de tipo (tipo) no tempo de compilação, enquanto GetType avalia o tipo a retornar no tempo de execução.

`typeid` pode ter um nome de tipo nativo ou um alias de Common Language runtime para o nome do tipo nativo; saiba mais em [Equivalentes do .NET Framework aos tipos nativos do C++ (C++/CLI)](../dotnet/dotnet-framework-equivalents-to-cpp-native-types-cpp-cli.md).

`typeid` também trabalha com tipos nativos, embora ainda retorne um System::Type.  Para obter uma estrutura type_info, use [Operador typeid](../cpp/typeid-operator.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo a seguir compara a palavra-chave typeid ao membro `GetType()`.

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

O exemplo a seguir mostra que uma variável do tipo System::Type pode ser usada para obter os atributos em um tipo.  Também mostra que, para alguns tipos, é preciso criar um typedef para usar `typeid`.

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

## <a name="see-also"></a>Confira também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)
