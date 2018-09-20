---
title: atributo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.attribute
dev_langs:
- C++
helpviewer_keywords:
- __typeof keyword
- custom attributes, creating
- attribute attribute
- attributes [C++/CLI], custom
ms.assetid: 8cb3489f-65c4-44ea-b0aa-3c3c6b15741d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 335b22b015bf244e39d67781eae21b3c43328256
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46379782"
---
# <a name="attribute"></a>Atributo

Permite que você crie um atributo personalizado.

## <a name="syntax"></a>Sintaxe

```cpp
[ attribute(
   AllowOn,
   AllowMultiple=boolean,
   Inherited=boolean
) ]
```

### <a name="parameters"></a>Parâmetros

*AllowOn*<br/>
Especifica os elementos de linguagem ao qual o atributo personalizado pode ser aplicado. O padrão é `System::AttributeTargets::All` (consulte [System::AttributeTargets](https://msdn.microsoft.com/library/system.attributetargets.aspx)).

*AllowMultiple*<br/>
Especifica se o atributo personalizado pode ser aplicado várias vezes para uma construção. Padrão é FALSE.

*Herdado*<br/>
Indica se o atributo deve ser herdadas por subclasses. O compilador não oferece suporte especial para essa funcionalidade; é o trabalho dos consumidores de atributo (`Reflection`, por exemplo) para respeitar essas informações. Se *Inherited* for TRUE, o atributo é herdado. Se *AllowMultiple* for TRUE, o atributo serão acumulados no membro derivado; se *AllowMultiple* é FALSE, o atributo substituirá (ou substituir) na herança. Se *Inherited* é FALSE, o atributo não será herdado. O padrão é TRUE.

## <a name="remarks"></a>Comentários

> [!NOTE]
> O **atributo** atributo foi preterido.  Use o atributo de tempo de execução de linguagem comum `System.Attribute` para diretamente para criar attirbutes definida pelo usuário. Para obter mais informações, consulte [atributos definidos pelo usuário](../windows/user-defined-attributes-cpp-component-extensions.md).

Você define uma [atributo personalizado](../windows/custom-attributes-cpp.md) colocando os **atributo** atributo em uma definição de classe ou struct gerenciado. O nome da classe é o atributo personalizado. Por exemplo:

```cpp
[ attribute(Parameter) ]
public ref class MyAttr {};
```

define um atributo chamado `MyAttr` que pode ser aplicado a parâmetros de função. A classe deve ser pública se for o atributo a ser usado em outros assemblies.

> [!NOTE]
> Para evitar colisões de namespace, todos os nomes de atributo implicitamente terminam com "Attribute"; Neste exemplo, o nome do atributo e classe é na verdade `MyAttrAttribute`, mas `MyAttr` e `MyAttrAttribute` podem ser usados alternadamente.

Construtores de públicos da classe definem parâmetros de não nomeados do atributo. Construtores sobrecarregados permitem várias maneiras de especificar o atributo, portanto, um atributo personalizado que é definida da seguinte maneira:

```cpp
// cpp_attr_ref_attribute.cpp
// compile with: /c /clr
using namespace System;
[ attribute(AttributeTargets::Class) ]   // apply attribute to classes
public ref class MyAttr {
public:
   MyAttr() {}   // Constructor with no parameters
   MyAttr(int arg1) {}   // Constructor with one parameter
};

[MyAttr]
ref class ClassA {};   // Attribute with no parameters

[MyAttr(123)]
ref class ClassB {};   // Attribute with one parameter
```

Os membros de dados públicos e propriedades da classe são os parâmetros nomeados opcionais do atributo:

```cpp
// cpp_attr_ref_attribute_2.cpp
// compile with: /c /clr
using namespace System;
[ attribute(AttributeTargets::Class) ]
ref class MyAttr {
public:
   // Property Priority becomes attribute's named parameter Priority
    property int Priority {
       void set(int value) {}
       int get() { return 0;}
   }
   // Data member Version becomes attribute's named parameter Version
   int Version;
   MyAttr() {}   // constructor with no parameters
   MyAttr(int arg1) {}   // constructor with one parameter
};

[MyAttr(123, Version=2)]
ref class ClassC {};
```

Para obter uma lista dos tipos de parâmetro de atributo possíveis, consulte [atributos personalizados](../windows/custom-attributes-cpp.md).

Ver [atributos definidos pelo usuário](../windows/user-defined-attributes-cpp-component-extensions.md) para uma discussão sobre destinos de atributos.

O **atributo** atributo tem um *AllowMultiple* multiuse (pode aparecer mais de uma vez na mesma entidade) ou parâmetro que especifica se o atributo personalizado é de uso único.

```cpp
// cpp_attr_ref_attribute_3.cpp
// compile with: /c /clr
using namespace System;
[ attribute(AttributeTargets::Class, AllowMultiple = true) ]
ref struct MyAttr {
   MyAttr(){}
};   // MyAttr is a multiuse attribute

[MyAttr, MyAttr()]
ref class ClassA {};
```

Classes de atributos personalizados derivam direta ou indiretamente <xref:System.ComponentModel.AttributeCollection.%23ctor%2A>, que faz com que as definições de atributo nos metadados seja rápida e fácil de identificar. O **atributo** atributo implica a herança de `System::Attribute`, portanto, derivação explícita não é necessária:

```cpp
[ attribute(Class) ]
ref class MyAttr
```

equivale a

```cpp
[ attribute(Class) ]
ref class MyAttr : System::Attribute   // OK, but redundant.
```

**atributo** é um alias para <xref:System.AttributeUsageAttribute?displayProperty=fullName> (não AttributeAttribute; é uma exceção à regra de nomenclatura de atributo).

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**classe ref**, **ref struct**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="example"></a>Exemplo

```cpp
// cpp_attr_ref_attribute_4.cpp
// compile with: /c /clr
using namespace System;
[attribute(AttributeTargets::Class)]
ref struct ABC {
   ABC(Type ^) {}
};

[ABC(String::typeid)]   // typeid operator yields System::Type ^
ref class MyClass {};
```

## <a name="example"></a>Exemplo

O `Inherited` argumento nomeado que especifica se um atributo personalizado aplicado em uma classe base será exibido na reflexão de uma classe derivada.

```cpp
// cpp_attr_ref_attribute_5.cpp
// compile with: /clr
using namespace System;
using namespace System::Reflection;

[attribute( AttributeTargets::Method, Inherited=false )]
ref class BaseOnlyAttribute { };

[attribute( AttributeTargets::Method, Inherited=true )]
ref class DerivedTooAttribute { };

ref struct IBase {
public:
   [BaseOnly, DerivedToo]
   virtual void meth() {}
};

// Reflection on Derived::meth will show DerivedTooAttribute
// but not BaseOnlyAttribute.
ref class Derived : public IBase {
public:
   virtual void meth() override {}
};

int main() {
   IBase ^ pIB = gcnew Derived;

   MemberInfo ^ pMI = pIB->GetType( )->GetMethod( "meth" );
   array<Object ^> ^ pObjs = pMI->GetCustomAttributes( true );
   Console::WriteLine( pObjs->Length ) ;
}
```

```Output
2
```

## <a name="see-also"></a>Consulte também

[Referência alfabética de atributos](../windows/attributes-alphabetical-reference.md)  
