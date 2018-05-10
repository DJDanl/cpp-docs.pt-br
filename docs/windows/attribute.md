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
- attributes [C++], custom
ms.assetid: 8cb3489f-65c4-44ea-b0aa-3c3c6b15741d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9826b689e2b8a640efe66e8625b97b3cec347acf
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="attribute"></a>Atributo
Permite que você crie um atributo personalizado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ attribute(  
   AllowOn,  
   AllowMultiple=boolean,  
   Inherited=boolean  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *AllowOn*  
 Especifica os elementos de linguagem ao qual o atributo personalizado pode ser aplicado. O padrão é **System::AttributeTargets::All** (consulte [System::AttributeTargets](https://msdn.microsoft.com/en-us/library/system.attributetargets.aspx)).  
  
 `AllowMultiple`  
 Especifica se o atributo personalizado pode ser aplicado várias vezes para uma construção. O padrão é **FALSE**.  
  
 `Inherited`  
 Indica se o atributo deve ser herdadas por subclasses. O compilador não fornece especial suporte para essa funcionalidade; é o trabalho dos consumidores de atributo (por exemplo, reflexão) para respeitar essas informações. Se `Inherited` é **TRUE**, o atributo é herdado. Se `AllowMultiple` é **TRUE**, o atributo serão acumulados no membro derivado; se `AllowMultiple` é **FALSE**, o atributo substituirá (ou substituir) na herança. Se `Inherited` é **FALSE**, o atributo não será herdado. O padrão é **TRUE**.  
  
## <a name="remarks"></a>Comentários  
  
> [!NOTE]
>  O `attribute` atributo agora está obsoleta.  Use o atributo common language runtime Attribute diretamente para criar attirbutes definida pelo usuário.  Para obter mais informações, consulte [atributos definidos pelo usuário](../windows/user-defined-attributes-cpp-component-extensions.md).  
  
 Definir um [atributo personalizado](../windows/custom-attributes-cpp.md) colocando o `attribute` atributo em uma definição de classe ou estrutura gerenciada. O nome da classe é o atributo personalizado. Por exemplo:  
  
```  
[ attribute(Parameter) ]  
public ref class MyAttr {};  
```  
  
 define um atributo chamado MyAttr que pode ser aplicado a parâmetros de função. A classe deve ser pública, se o atributo for para ser usado em outros assemblies.  
  
> [!NOTE]
>  Para evitar colisões de namespace, todos os nomes de atributo implicitamente terminam com "Atributo"; Neste exemplo, o nome do atributo e da classe é realmente MyAttrAttribute, mas MyAttr e MyAttrAttribute podem ser usados de maneira intercambiável.  
  
 Construtores públicos da classe definem parâmetros sem nome do atributo. Construtores sobrecarregados permitem várias maneiras de especificar o atributo, por isso, um atributo personalizado que é definida da seguinte maneira:  
  
```  
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
  
 Membros de dados públicos e as propriedades da classe são parâmetros de nome opcional do atributo:  
  
```  
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
  
 Consulte [atributos definidos pelo usuário](../windows/user-defined-attributes-cpp-component-extensions.md) para uma discussão sobre os destinos de atributos.  
  
 O `attribute` atributo tem um `AllowMultiple` parâmetro que especifica se o atributo personalizado é de uso único ou multiuse (pode aparecer mais de uma vez na mesma entidade).  
  
```  
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
  
 Classes de atributos personalizados são derivadas diretamente ou indiretamente de <xref:System.ComponentModel.AttributeCollection.%23ctor%2A>, que faz com que as definições de atributos nos metadados rápida e fácil de identificar. O `attribute` atributo implica a herança de System::Attribute, portanto derivação explícita não é necessária:  
  
```  
[ attribute(Class) ]  
ref class MyAttr  
```  
  
 equivale a  
  
```  
[ attribute(Class) ]  
ref class MyAttr : System::Attribute   // OK, but redundant.  
```  
  
 `attribute` é um alias para <xref:System.AttributeUsageAttribute?displayProperty=fullName> (não AttributeAttribute; essa é uma exceção à regra de nomenclatura de atributo).  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|`ref` **classe**, **estrutura ref**|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="example"></a>Exemplo  
  
```  
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
 O `Inherited` argumento nomeado que especifica se um atributo personalizado aplicado em uma classe base aparecerão em reflexão de uma classe derivada.  
  
```  
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
 [Atributos personalizados](http://msdn.microsoft.com/en-us/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)