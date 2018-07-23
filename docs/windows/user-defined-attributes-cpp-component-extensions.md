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
ms.openlocfilehash: 22f8dfa7e78568f100b0c58c881b9e84cb47a149
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33891760"
---
# <a name="user-defined-attributes--c-component-extensions"></a>Atributos Definidos pelo Usuário (Extensões de Componentes C++)
Atributos personalizados permitem estender os metadados de uma interface, classe ou estrutura, parâmetro, método ou enumeração.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 Suportam a tempos de execução de todos os atributos personalizados.  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 C + + atributos CX oferecem suporte apenas as propriedades, mas não atributo construtores ou métodos.  
  
### <a name="remarks"></a>Comentários  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
## <a name="common-language-runtime"></a>Common Language Runtime  
 Atributos personalizados permitem estender os metadados de um elemento gerenciado. Para obter mais informações, consulte [Atributos](/dotnet/standard/attributes/index).  
  
### <a name="remarks"></a>Comentários  
 As informações e a sintaxe apresentados neste tópico destina-se para substituir as informações apresentadas no [atributo](../windows/attribute.md).  
  
 Você pode definir um atributo personalizado, definindo um tipo e fazendo <xref:System.Attribute> uma classe base para o tipo e, opcionalmente, aplicando o <xref:System.AttributeUsageAttribute> atributo.  
  
 Por exemplo, no Microsoft Transaction Server (MTS) 1.0, comportamento em relação a transações, sincronização, o balanceamento de carga, e assim por diante foi especificado por meio de GUIDs personalizados inseridos para a biblioteca de tipo usando o atributo personalizado ODL. Portanto, um cliente de um servidor do MTS foi possível determinar as características de seus lendo a biblioteca de tipos. No .NET Framework, o analógico da biblioteca de tipos é metadados e analógico do atributo personalizado ODL é atributos personalizados. Além disso, a biblioteca de tipos de leitura equivale a usando a reflexão sobre os tipos.  
  
 Para obter mais informações, consulte  
  
-   [Destinos de atributos](../windows/attribute-targets-cpp-component-extensions.md)  
  
-   [Tipos de parâmetro de atributo](../windows/attribute-parameter-types-cpp-component-extensions.md)  
  
 Para obter informações sobre assinatura de assemblies no Visual C++, consulte [Assemblies com nome forte (assinatura de Assembly) (C + + CLI)](../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md).  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
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
  
 **Exemplo**  
  
 O exemplo a seguir ilustra alguns recursos importantes de atributos personalizados. Por exemplo, este exemplo mostra um uso comum dos atributos personalizados: Criando um servidor que pode descrever próprio totalmente aos clientes.  
  
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
  
 **Saída**  
  
```Output  
Service Priority = 0  
  
Service Access = Write  
  
Service Priority = 3  
  
Service Access = Write  
  
Service Priority = 1  
  
Service Access = Read  
```  
  
 **Exemplo**  
  
 O objeto ^ tipo substitui o tipo de dados variant. O exemplo a seguir define um atributo personalizado que usa uma matriz de objetos ^ como parâmetros.  
  
 Argumentos de atributo devem ser constantes de tempo de compilação; Na maioria dos casos, eles devem ser literais constantes.  
  
 Consulte [typeid](../windows/typeid-cpp-component-extensions.md) para obter informações sobre como retornar um valor de System::Type de um bloco de atributo personalizado.  
  
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
  
 **Exemplo**  
  
 O tempo de execução exige que a parte pública da classe de atributo personalizado deve ser serializável.  Ao criar atributos personalizados, argumentos nomeados do seu atributo personalizado são limitados às constantes de tempo de compilação.  (Pense nisso como uma sequência de bits anexado ao seu layout de classe nos metadados.)  
  
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