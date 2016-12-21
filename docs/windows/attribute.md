---
title: "attribute | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "vc-attr.attribute"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "__typeof keyword"
  - "custom attributes, creating"
  - "attribute attribute"
  - "attributes [C++], custom"
ms.assetid: 8cb3489f-65c4-44ea-b0aa-3c3c6b15741d
caps.latest.revision: 18
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# attribute
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Permite que você criar um atributo personalizado.  
  
## Sintaxe  
  
```  
  
      [ attribute(  
   AllowOn,  
   AllowMultiple=boolean,  
   Inherited=boolean  
) ]  
```  
  
#### Parâmetros  
 *AllowOn*  
 Especifica os elementos de linguagem ao qual o atributo personalizado pode ser aplicado.  O padrão é  **System::AttributeTargets::All** \(consulte  [System::AttributeTargets](https://msdn.microsoft.com/en-us/library/system.attributetargets.aspx)\).  
  
 `AllowMultiple`  
 Especifica se o atributo personalizado pode ser aplicado repetidamente para uma construção.  O padrão é  **FALSE**.  
  
 `Inherited`  
 Indica se o atributo deve ser herdadas por subclasses.  O compilador não fornece nenhum suporte especial para essa funcionalidade; ele é o trabalho dos consumidores atributo \(reflexão, por exemplo\) respeitam essas informações.  Se `Inherited` é  **TRUE**, o atributo é herdado.  Se `AllowMultiple` é  **TRUE**, o atributo acumulará no membro derivado; Se `AllowMultiple` é  **FALSE**, o atributo irá substituir \(ou substituir\) na herança.  Se `Inherited` é  **FALSE**, o atributo não será herdado.  O padrão é  **TRUE**.  
  
## Comentários  
  
> [!NOTE]
>  O `attribute` atributo agora está obsoleto.  Use o language runtime atributo comum Attribute diretamente para criar o attirbutes definida pelo usuário.  Para obter mais informações, consulte [User\-Defined Attributes](../windows/user-defined-attributes-cpp-component-extensions.md).  
  
 Você pode definir um  [atributo personalizado](../windows/custom-attributes-cpp.md) , colocando o `attribute` atributo em uma definição de class ou struct gerenciado.  O nome da classe é o atributo personalizado.  Por exemplo:  
  
```  
[ attribute(Parameter) ]  
public ref class MyAttr {};  
```  
  
 define um atributo chamado MyAttr que pode ser aplicada aos parâmetros da função.  A classe deve ser pública, se o atributo for ser usado em outros assemblies.  
  
> [!NOTE]
>  Para evitar colisões de espaço para nome, todos os nomes de atributo implicitamente terminam com "Atributo"; Neste exemplo, o nome da classe e atributo é, na verdade, MyAttrAttribute, mas MyAttr e MyAttrAttribute podem ser usados de forma intercambiável.  
  
 A construtores públicos da classe definem parâmetros de sem nome do atributo.  Construtores sobrecarregados permitem várias maneiras de especificar o atributo, por isso, um atributo personalizado que é definida da seguinte maneira:  
  
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
  
 Membros de dados públicos e as propriedades da classe são parâmetros com nome do atributo opcional:  
  
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
  
 Para obter uma lista dos tipos de parâmetro do atributo possíveis, consulte  [Atributos personalizados do](../windows/custom-attributes-cpp.md).  
  
 Consulte [User\-Defined Attributes](../windows/user-defined-attributes-cpp-component-extensions.md) para uma discussão sobre os destinos de atributo.  
  
 O `attribute` atributo tem um `AllowMultiple` parâmetro que especifica se o atributo personalizado é o único uso ou multiuse \(pode aparecer mais de uma vez na mesma entidade\).  
  
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
  
 Classes de atributo personalizado derivam direta ou indiretamente do <xref:System.ComponentModel.AttributeCollection.%23ctor%2A>, que aumenta as definições de atributos nos metadados rápida e fácil de identificar.  O `attribute` atributo implica a herança de System::Attribute, por derivação explícita não é necessária:  
  
```  
[ attribute(Class) ]  
ref class MyAttr  
```  
  
 Equivale a  
  
```  
[ attribute(Class) ]  
ref class MyAttr : System::Attribute   // OK, but redundant.  
```  
  
 `attribute`é um alias de <xref:System.AttributeUsageAttribute?displayProperty=fullName> \(não AttributeAttribute; Isso é uma exceção à regra de nomenclatura de atributo\).  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|`ref` **classe**,  **ref struct**|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Exemplo  
  
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
  
## Exemplo  
 O `Inherited` argumento nomeado Especifica se um atributo personalizado aplicado em uma classe base será exibido na reflexão de uma classe derivada.  
  
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
  
  **2**   
## Consulte também  
 [Attributes Alphabetical Reference](../windows/attributes-alphabetical-reference.md)   
 [Custom Attributes](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)