---
title: Atributos definidos pelo usuário (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- metadata, extending
- custom attributes, extending metadata
ms.assetid: 98b29048-a3ea-4698-8441-f149cdaec9fb
ms.openlocfilehash: 6d200c36946e7bc7d441c2c4db1bdfe96d4aeef9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65515991"
---
# <a name="user-defined-attributes--ccli-and-ccx"></a>Atributos definidos pelo usuário (C++/CLI e C++/CX)

C++/CLI e C++/CX permitem que você crie atributos específicos da plataforma que estendem os metadados de uma interface, classe ou estrutura, método, parâmetro ou enumeração. Esses atributos são distintos dos [atributos C++ padrão](../cpp/attributes.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

Você pode aplicar atributos C++/CX a propriedades, mas não a construtores ou métodos.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

As informações e a sintaxe apresentadas neste tópico destinam-se a substituir as informações apresentadas em [Atributo](../windows/attributes/attribute.md).

Você pode definir um atributo personalizado definindo um tipo e tornando <xref:System.Attribute> uma classe base para o tipo e, opcionalmente, aplicando o atributo <xref:System.AttributeUsageAttribute>.

Para obter mais informações, confira:

- [Destinos do atributo](attribute-targets-cpp-component-extensions.md)

- [Tipos de parâmetro de atributo](attribute-parameter-types-cpp-component-extensions.md)

Saiba mais sobre como assinar assemblies no Visual C++ em [Assemblies de nome forte (assinatura de assembly) (C++/CLI)](../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo a seguir mostra como definir um atributo personalizado.

```cpp
// user_defined_attributes.cpp
// compile with: /clr /c
using namespace System;

[AttributeUsage(AttributeTargets::All)]
ref struct Attr : public Attribute {
   Attr(bool i){}
   Attr(){}
};

[Attr]
ref class MyClass {};
```

O exemplo a seguir ilustra alguns recursos importantes de atributos personalizados. Por exemplo, este exemplo mostra um uso comum dos atributos personalizados: criar a instância de um servidor que pode se descrever completamente para os clientes.

```cpp
// extending_metadata_b.cpp
// compile with: /clr
using namespace System;
using namespace System::Reflection;

public enum class Access { Read, Write, Execute };

// Defining the Job attribute:
[AttributeUsage(AttributeTargets::Class, AllowMultiple=true )]
public ref class Job : Attribute {
public:
   property int Priority {
      void set( int value ) { m_Priority = value; }
      int get() { return m_Priority; }
   }

   // You can overload constructors to specify Job attribute in different ways
   Job() { m_Access = Access::Read; }
   Job( Access a ) { m_Access = a; }
   Access m_Access;

protected:
   int m_Priority;
};

interface struct IService {
   void Run();
};

   // Using the Job attribute:
   // Here we specify that QueryService is to be read only with a priority of 2.
   // To prevent namespace collisions, all custom attributes implicitly
   // end with "Attribute".

[Job( Access::Read, Priority=2 )]
ref struct QueryService : public IService {
   virtual void Run() {}
};

// Because we said AllowMultiple=true, we can add multiple attributes
[Job(Access::Read, Priority=1)]
[Job(Access::Write, Priority=3)]
ref struct StatsGenerator : public IService {
   virtual void Run( ) {}
};

int main() {
   IService ^ pIS;
   QueryService ^ pQS = gcnew QueryService;
   StatsGenerator ^ pSG = gcnew StatsGenerator;

   //  use QueryService
   pIS = safe_cast<IService ^>( pQS );

   // use StatsGenerator
   pIS = safe_cast<IService ^>( pSG );

   // Reflection
   MemberInfo ^ pMI = pIS->GetType();
   array <Object ^ > ^ pObjs = pMI->GetCustomAttributes(false);

   // We can now quickly and easily view custom attributes for an
   // Object through Reflection */
   for( int i = 0; i < pObjs->Length; i++ ) {
      Console::Write("Service Priority = ");
      Console::WriteLine(static_cast<Job^>(pObjs[i])->Priority);
      Console::Write("Service Access = ");
      Console::WriteLine(static_cast<Job^>(pObjs[i])->m_Access);
   }
}
```

```Output
Service Priority = 0

Service Access = Write

Service Priority = 3

Service Access = Write

Service Priority = 1

Service Access = Read
```

O tipo `Object^` substitui o tipo de dados variante. O exemplo a seguir define um atributo personalizado que usa uma matriz de `Object^` como parâmetro.

Argumentos de atributos devem ser constantes do tempo de compilação; na maioria dos casos, eles devem ser literais constantes.

Confira [typeid](typeid-cpp-component-extensions.md) para saber mais sobre como retornar um valor System::Type de um bloco de atributo personalizado.

```cpp
// extending_metadata_e.cpp
// compile with: /clr /c
using namespace System;
[AttributeUsage(AttributeTargets::Class | AttributeTargets::Method)]
public ref class AnotherAttr : public Attribute {
public:
   AnotherAttr(array<Object^>^) {}
   array<Object^>^ var1;
};

// applying the attribute
[ AnotherAttr( gcnew array<Object ^> { 3.14159, "pi" }, var1 = gcnew array<Object ^> { "a", "b" } ) ]
public ref class SomeClass {};
```

O tempo de execução requer que a parte pública da classe de atributo personalizado possa ser serializada.  Ao criar atributos personalizados, os argumentos nomeados de seu atributo personalizado estão limitados às constantes do tempo de compilação.  (Considere isso uma sequência de bits anexada ao layout da classe nos metadados.)

```cpp
// extending_metadata_f.cpp
// compile with: /clr /c
using namespace System;
ref struct abc {};

[AttributeUsage( AttributeTargets::All )]
ref struct A : Attribute {
   A( Type^ ) {}
   A( String ^ ) {}
   A( int ) {}
};

[A( abc::typeid )]
ref struct B {};
```

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)