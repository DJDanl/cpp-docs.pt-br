---
title: "User-Defined Attributes  (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "metadata, extending"
  - "custom attributes, extending metadata"
ms.assetid: 98b29048-a3ea-4698-8441-f149cdaec9fb
caps.latest.revision: 27
caps.handback.revision: 25
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# User-Defined Attributes  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os atributos personalizados permitem estender os metadados de uma interface, uma classe ou estrutura, um método, um parâmetro, ou uma enumeração.  
  
## Todos os Tempos de Execução  
 Qualquer tempo de execução da suporte a atributos personalizados.  
  
## Tempo de execução do windows  
 Os atributos de C\+\+\/CX só dão suporte a propriedades, mas não construtores de atributo ou métodos.  
  
### Comentários  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
## Common Language Runtime  
 Os atributos personalizados permitem estender os metadados de um elemento gerenciado.  Para obter mais informações, consulte [Atributos](../Topic/Extending%20Metadata%20Using%20Attributes.md).  
  
### Comentários  
 A sintaxe e informações apresentadas neste tópico é feito substituir as informações apresentadas em [attribute](../windows/attribute.md).  
  
 Você pode definir um atributo personalizado configurando um tipo e fazendo a <xref:System.Attribute> uma classe base para o tipo e opcionalmente aplicando o atributo de <xref:System.AttributeUsageAttribute> .  
  
 Por exemplo, no servidor \(MTS\) 1,0 da transação da Microsoft, comportamento em relação a transações, sincronização, balanceamento de carga, foi especificado e assim por diante por meio de GUIDs personalizado inserido na biblioteca de tipos usando o atributo personalizado de ODL.  Assim, um cliente de um servidor de MTS poderia determinar as características ler a biblioteca de tipos.  No.NET Framework, o analógico da biblioteca de tipos é metadados, e o analógico de atributo personalizado de ODL é atributos personalizados.  Além disso, leia a biblioteca de tipos procedimento é equivalente a usar a reflexão em tipos.  
  
 Para obter mais informações, consulte,  
  
-   [Attribute Targets](../windows/attribute-targets-cpp-component-extensions.md)  
  
-   [Attribute Parameter Types](../windows/attribute-parameter-types-cpp-component-extensions.md)  
  
 Para obter informações sobre como assinar os assemblies no Visual C\+\+, consulte [Assemblies de nome forte \(assinatura de assembly\)](../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md).  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
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
  
 O exemplo a seguir ilustra alguns recursos importantes de atributos personalizados.  Por exemplo, este exemplo mostra um uso comum de atributos personalizados: criando uma instância de um servidor que pode se descrever completamente aos clientes.  
  
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
  
  **Prioridade de serviço \= 0**  
 **\= Acesso gravação de serviço**  
 **Prioridade de serviço \= 3**  
 **\= Acesso gravação de serviço**  
 **Prioridade de serviço \= 1**  
 **Acesso do serviço \= leitura** **Exemplo**  
  
 O tipo de Object^ substitui o tipo de dados variant.  O exemplo a seguir define um atributo personalizado que usa uma matriz de Object^ como parâmetros.  
  
 Os argumentos de atributo devem ser constantes de tempo de compilação; na maioria dos casos, devem ser literais constantes.  
  
 Consulte [typeid](../Topic/typeid%20%20\(C++%20Component%20Extensions\).md) para obter informações sobre como retornar um valor de System::Type de um bloco de atributo personalizado.  
  
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
  
 O tempo de execução requer que a parte pública da classe do atributo personalizado deve ser serializável.  Ao criar atributos personalizados, os argumentos nomeadas do atributo personalizado são limitados às constantes de tempo de compilação.  \(Pense delas como uma sequência de bits anexados ao layout da classe nos metadados.\)  
  
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
  
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)