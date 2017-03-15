---
title: "Reflex&#227;o (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/13/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - ".NET Framework [C++], reflexão"
  - "tipos de dados [C++], reflexão"
  - "Método GetType"
  - "metadados, reflexão"
  - "reflexão [C++]"
  - "reflexão [C++], sobre reflexão"
  - "palavra-chave typeid [C++]"
ms.assetid: 46b6ff4a-e441-4022-8892-78e69422f230
caps.latest.revision: 24
caps.handback.revision: 22
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Reflex&#227;o (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A reflexão permite que os tipos de dados conhecidos sejam inspecionados em tempo de execução.  A reflexão permite a enumeração dos tipos de dados em um determinado assembly, e os membros de uma classe ou de um tipo de dado valor podem ser descobertos.  Isso é verdadeiro quer o tipo esteve chamado ou referenciado em tempo de compilação.  Isso torna a reflexão um recurso útil para ferramentas de gerenciamento de desenvolvimento e code.  
  
 Observe que o nome do assembly fornecido é o nome forte \(consulte [Assemblies de nome forte](../Topic/Creating%20and%20Using%20Strong-Named%20Assemblies.md)\), que inclui a versão do assembly, cultura, e assinando informações.  Observe também que o nome do namespace no qual o tipo de dados é definido pode ser recuperado, junto com o nome da classe base.  
  
 O modo mais comum de acessar recursos de reflexão é com o método de <xref:System.Object.GetType%2A> .  Esse método é fornecido por [System::Object](https://msdn.microsoft.com/en-us/library/system.object.aspx), que todas as classes com coletadas derivam.  
  
 A reflexão em um arquivo criado com o compilador do Visual C\+\+ é permitida se o arquivo é criado com as opções do compilador de **\/clr:pure** ou de **\/clr:safe** .  Consulte [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md) para maiores informações.  
  
 Tópicos desta seção:  
  
-   [Como implementar uma arquitetura de componente de plug\-in usando a reflexão](../dotnet/how-to-implement-a-plug-in-component-architecture-using-reflection-cpp-cli.md)  
  
-   [Como enumerar tipos de dados em assemblies usando reflexão](../dotnet/how-to-enumerate-data-types-in-assemblies-using-reflection-cpp-cli.md)  
  
 Para obter mais informações, consulte [Namespace de System.Reflection](https://msdn.microsoft.com/en-us/library/system.reflection.aspx)  
  
## Exemplo  
 O método de `GetType` retorna um ponteiro para um objeto da classe de <xref:System.Type> , que descreve o tipo na quando o objeto é baseado. \(O objeto de **Tipo** não contém nenhuma informação de instância específica.\) Um um item é o nome de tipo completo, que pode ser exibido como segue:  
  
 Observe que o nome do tipo inclui o escopo completo no qual o tipo é definido, incluindo o namespace, e que é exibido na sintaxe do .NET, com um ponto como o operador de resolução de escopo.  
  
```  
// vcpp_reflection.cpp  
// compile with: /clr  
using namespace System;  
int main() {  
   String ^ s = "sample string";  
   Console::WriteLine("full type name of '{0}' is '{1}'", s, s->GetType());  
}  
```  
  
  **o nome completo do tipo “da cadeia de caracteres de exemplo” é “System.String”**   
## Exemplo  
 Os tipos de valores podem ser usados com a função de `GetType` além disso, mas devem ser boxed primeiro.  
  
```  
// vcpp_reflection_2.cpp  
// compile with: /clr  
using namespace System;  
int main() {  
   Int32 i = 100;   
   Object ^ o = i;  
   Console::WriteLine("type of i = '{0}'", o->GetType());  
}  
```  
  
  **tipo de i \= “System.Int32”**   
## Exemplo  
 Como com o método de `GetType` , o operador de [typeid](../Topic/typeid%20%20\(C++%20Component%20Extensions\).md) retorna um ponteiro para um objeto de **Tipo** , portanto esse código indica o nome **System.Int32**do tipo.  Exibir nomes de tipo é o recurso o mais básico de reflexão, mas uma técnica é potencialmente mais útil inspecionar ou descobrir os valores válidos para tipos enumerados.  Isso pode ser feito usando a função estática de **Enum::GetNames** , que retorna uma matriz de cadeias de caracteres, cada uma contendo um valor de enumeração no formulário de texto.  O exemplo a seguir recupera uma matriz de cadeias de caracteres que descreve os valores de enumeração do valor para o enum de **Opções** \(CLR\) e os exibe em um loop.  
  
 Se uma quarta opção é adicionada à enumeração de **Opções** , esse código relatará o novo padrão sem recompilação, mesmo se a enumeração é definida em um assembly separado.  
  
```  
// vcpp_reflection_3.cpp  
// compile with: /clr  
using namespace System;  
  
enum class Options {   // not a native enum  
   Option1, Option2, Option3  
};  
  
int main() {  
   array<String^>^ names = Enum::GetNames(Options::typeid);  
  
   Console::WriteLine("there are {0} options in enum '{1}'",   
               names->Length, Options::typeid);  
  
   for (int i = 0 ; i < names->Length ; i++)  
      Console::WriteLine("{0}: {1}", i, names[i]);  
  
   Options o = Options::Option2;  
   Console::WriteLine("value of 'o' is {0}", o);  
}  
```  
  
  **há 3 opções opções no enum “**  
**0: Opção**  
**1: Option2**  
**2: Option3**  
**o valor de “o” é Option2**   
## Exemplo  
 O objeto de `GetType` oferece suporte a vários membros e propriedades que podem ser usados para examinar um tipo.  Este código a seguir recupera e exibe algumas dessas informações:  
  
```  
// vcpp_reflection_4.cpp  
// compile with: /clr  
using namespace System;  
int main() {  
   Console::WriteLine("type information for 'String':");  
   Type ^ t = String::typeid;  
  
   String ^ assemblyName = t->Assembly->FullName;  
   Console::WriteLine("assembly name: {0}", assemblyName);  
  
   String ^ nameSpace = t->Namespace;  
   Console::WriteLine("namespace: {0}", nameSpace);  
  
   String ^ baseType = t->BaseType->FullName;  
   Console::WriteLine("base type: {0}", baseType);  
  
   bool isArray = t->IsArray;  
   Console::WriteLine("is array: {0}", isArray);  
  
   bool isClass = t->IsClass;  
   Console::WriteLine("is class: {0}", isClass);  
}  
```  
  
  **informações de tipo para a “cadeia de caracteres”:**  
**nome do assembly: mscorlib, Version\=1.0.5000.0, Culture\=neutral,**   
**PublicKeyToken\=b77a5c561934e089**  
**namespace: O sistema**  
**tipo de base: System.Object**  
**é a matriz: False**  
**é a classe: True**   
## Exemplo  
 A reflexão também permite a enumeração dos tipos em um assembly e de membros dentro das classes.  Para demonstrar esse recurso, defina uma classe simples:  
  
```  
// vcpp_reflection_5.cpp  
// compile with: /clr /LD  
using namespace System;  
public ref class TestClass {  
   int m_i;  
public:  
   TestClass() {}  
   void SimpleTestMember1() {}  
   String ^ SimpleMember2(String ^ s) { return s; }   
   int TestMember(int i) { return i; }  
   property int Member {  
      int get() { return m_i; }  
      void set(int i) { m_i = i; }  
   }  
};  
```  
  
## Exemplo  
 Se o código anterior é compilado em uma DLL chamado vcpp\_reflection\_6.dll, você pode usar a reflexão para inspecionar o conteúdo desse assembly.  Isso envolve o uso da função de API estático [Assembly::Load](https://msdn.microsoft.com/en-us/library/system.reflection.assembly.load.aspx) de reflexão para carregar o assembly.  Esta função retorna o endereço de um objeto de **Assembly** que pode ser consultado sobre os módulos e os tipos em.  
  
 Uma vez que o sistema de reflexão carrega com êxito o assembly, uma matriz de objetos de **Tipo** é recuperada com a função de [Assembly::GetTypes](https://msdn.microsoft.com/en-us/library/system.reflection.assembly.gettypes.aspx) .  Cada elemento da matriz contém informações sobre um tipo diferente, embora nesse caso, somente uma classe é definida.  Usando um loop, cada **Tipo** nesta matriz é consultado sobre os membros do tipo que usam a função de **Type::GetMembers** .  Esta função retorna uma matriz de objetos de **MethodInfo** , cada objeto que contém informações sobre a função de membro, membro de dados, ou propriedade no tipo.  
  
 Observe que a lista de métodos inclui as funções definidas explicitamente em **TestClass** e as funções herdadas implicitamente da classe de **System::Object** .  Como parte da descrição em .NET em vez de na sintaxe do Visual C\+\+, as propriedades aparecem como o membro de dados subjacentes acessado por funções obter\/cluster.  As funções obter\/conjunto aparecem nessa lista como métodos normais.  A reflexão tem suporte com Common Language Runtime, não pelo compilador do Visual C\+\+.  
  
 Embora você use este código para inspecionar um assembly que você defina, você também pode usar esse código para inspecionar os assemblies do .NET.  Por exemplo, se você alterar TestAssembly ao mscorlib, você verá uma listagem de cada tipo e método definidos em mscorlib.dll.  
  
```  
// vcpp_reflection_6.cpp  
// compile with: /clr  
using namespace System;  
using namespace System::IO;  
using namespace System::Reflection;  
int main() {  
   Assembly ^ a = nullptr;  
   try {  
      // load assembly -- do not use file extension  
      // will look for .dll extension first  
      // then .exe with the filename  
      a = Assembly::Load("vcpp_reflection_5");  
   }  
   catch (FileNotFoundException ^ e) {  
      Console::WriteLine(e->Message);  
      return -1;  
   }  
  
   Console::WriteLine("assembly info:");  
   Console::WriteLine(a->FullName);  
   array<Type^>^ typeArray = a->GetTypes();  
  
   Console::WriteLine("type info ({0} types):", typeArray->Length);  
  
   int totalTypes = 0;  
   int totalMembers = 0;  
   for (int i = 0 ; i < typeArray->Length ; i++) {  
      // retrieve array of member descriptions  
      array<MemberInfo^>^ member = typeArray[i]->GetMembers();  
  
      Console::WriteLine("  members of {0} ({1} members):",   
      typeArray[i]->FullName, member->Length);  
      for (int j = 0 ; j < member->Length ; j++) {  
         Console::Write("       ({0})",   
         member[j]->MemberType.ToString() );  
         Console::Write("{0}  ", member[j]);  
         Console::WriteLine("");  
         totalMembers++;  
      }  
      totalTypes++;  
   }  
   Console::WriteLine("{0} total types, {1} total members",  
   totalTypes, totalMembers);  
}  
```  
  
## Consulte também  
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)