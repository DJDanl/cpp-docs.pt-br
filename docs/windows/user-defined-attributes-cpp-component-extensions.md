---
title: Atributos (extensões de componentes C++) definidos pelo usuário | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- metadata, extending
- custom attributes, extending metadata
ms.assetid: 98b29048-a3ea-4698-8441-f149cdaec9fb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 605759e241498e83174f4d6b16435c3119c56671
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42600375"
---
# <a name="user-defined-attributes--c-component-extensions"></a>Atributos Definidos pelo Usuário (Extensões de Componentes C++)

Atributos personalizados permitem estender os metadados de uma interface, classe ou estrutura, parâmetro, método ou enumeração.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

Todos os tempos de execução dá suporte a atributos personalizados.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

C + + / atributos CX dão suporte a apenas propriedades, mas não métodos ou construtores de atributo.

### <a name="remarks"></a>Comentários

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

Atributos personalizados permitem que você estenda os metadados de um elemento gerenciado. Para obter mais informações, consulte [Atributos](/dotnet/standard/attributes/index).

### <a name="remarks"></a>Comentários

As informações e a sintaxe apresentadas neste tópico destina-se para substituir as informações apresentadas [atributo](../windows/attribute.md).

Você pode definir um atributo personalizado definindo um tipo e fazendo <xref:System.Attribute> uma classe base para o tipo e, opcionalmente, aplicando o <xref:System.AttributeUsageAttribute> atributo.

Por exemplo, em Microsoft Transaction Server (MTS) 1.0, comportamento em relação a transações, sincronização, o balanceamento de carga, e assim por diante foi especificado por meio de GUIDs personalizados inseridos na biblioteca de tipos usando o atributo personalizado de ODL. Portanto, um cliente de um servidor do MTS foi possível determinar suas características, lendo a biblioteca de tipos. No .NET Framework, o analógico da biblioteca de tipos é composta de metadados e do atributo ODL personalizado analógicas é atributos personalizados. Além disso, lendo a biblioteca de tipos é semelhante a usar a reflexão sobre os tipos.

Para obter mais informações, consulte

- [Destinos de atributos](../windows/attribute-targets-cpp-component-extensions.md)

- [Tipos de parâmetro de atributo](../windows/attribute-parameter-types-cpp-component-extensions.md)

Para obter informações sobre assinatura de assemblies no Visual C++, consulte [Assemblies de nome forte (assinatura de Assembly) (C + + / CLI)](../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md).

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

O exemplo a seguir ilustra alguns recursos importantes de atributos personalizados. Por exemplo, este exemplo mostra um uso comum dos atributos personalizados: Criando uma instância de um servidor totalmente consegue se descrever aos clientes.

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

O `Object^` tipo substitui o tipo de dados variant. O exemplo a seguir define um atributo personalizado que usa uma matriz de `Object^` como parâmetros.

Argumentos de atributo devem ser constantes de tempo de compilação; Na maioria dos casos, eles devem ser literais constantes.

Ver [typeid](../windows/typeid-cpp-component-extensions.md) para obter informações sobre como retornar um valor de System:: Type de um bloco de atributo personalizado.

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

O tempo de execução exige que a parte pública da classe de atributos personalizados deve ser serializável.  Ao criar atributos personalizados, argumentos nomeados do seu atributo personalizado são limitados a constantes de tempo de compilação.  (Considere isso como uma sequência de bits anexado ao seu layout de classe nos metadados.)

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

[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)