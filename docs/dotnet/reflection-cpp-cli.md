---
title: "Reflexão (C + + CLI) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- typeid keyword [C++]
- reflection [C++}, about reflection
- metadata, reflection
- GetType method
- .NET Framework [C++], reflection
- data types [C++], reflection
- reflection [C++}
ms.assetid: 46b6ff4a-e441-4022-8892-78e69422f230
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: fab5bb3c912aeea2598189965d424ba4508cf5c8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="reflection-ccli"></a>Reflexão (C++/CLI)
Reflexão permite que os tipos de dados conhecidos a ser inspecionado em tempo de execução. Reflexão permite a enumeração dos tipos de dados em um determinado assembly e os membros de um determinado tipo de classe ou o valor podem ser descobertos. Isso é verdadeiro independentemente do tipo era conhecido ou referenciado em tempo de compilação. Isso torna a reflexão um recurso útil para desenvolvimento e ferramentas de gerenciamento de código.  
  
 Observe que o nome do assembly fornecido é o nome forte (consulte [Creating and Using Strong-Named Assemblies](/dotnet/framework/app-domains/create-and-use-strong-named-assemblies)), que inclui a versão do assembly, cultura e informações de assinatura. Observe também que o nome do namespace no qual o tipo de dados é definido pode ser recuperado, junto com o nome da classe base.  
  
 A maneira mais comum para acessar recursos de reflexão é por meio de <xref:System.Object.GetType%2A> método. Este método é fornecido por [System::Object](https://msdn.microsoft.com/en-us/library/system.object.aspx), da qual derivam todas as classes de coleta de lixo.  
  
 Reflexão em um .exe criados com o compilador do Visual C++ só será permitido se o .exe é criado com o **/clr: pure** ou **/CLR: safe** opções do compilador. As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015. Consulte [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md) para obter mais informações.  
  
 Tópicos desta seção:  
  
-   [Como implementar uma arquitetura de componente de plug-in usando a reflexão (C++/CLI)](../dotnet/how-to-implement-a-plug-in-component-architecture-using-reflection-cpp-cli.md)  
  
-   [Como enumerar tipos de dados em assemblies usando reflexão (C++/CLI)](../dotnet/how-to-enumerate-data-types-in-assemblies-using-reflection-cpp-cli.md)  
  
 Para obter mais informações, consulte [Namespace System. Reflection](https://msdn.microsoft.com/en-us/library/system.reflection.aspx)  
  
## <a name="example"></a>Exemplo  
 O `GetType` método retorna um ponteiro para um <xref:System.Type> objeto de classe, que descreve o tipo após quando o objeto é baseado. (O **tipo** objeto não contém todas as informações específicas da instância.) Um desses itens é o nome completo do tipo, que pode ser exibido da seguinte maneira:  
  
 Observe que o nome do tipo inclui o escopo completo no qual o tipo é definido, incluindo o namespace, e que ele é exibido na sintaxe do .NET, com um ponto como o operador de resolução do escopo.  
  
```  
// vcpp_reflection.cpp  
// compile with: /clr  
using namespace System;  
int main() {  
   String ^ s = "sample string";  
   Console::WriteLine("full type name of '{0}' is '{1}'", s, s->GetType());  
}  
```  
  
```Output  
full type name of 'sample string' is 'System.String'  
```  
  
## <a name="example"></a>Exemplo  
 Tipos de valor podem ser usados com o `GetType` funcionarão bem, mas deve ser boxed primeiro.  
  
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
  
```Output  
type of i = 'System.Int32'  
```  
  
## <a name="example"></a>Exemplo  
 Assim como acontece com o `GetType` método, o [typeid](../windows/typeid-cpp-component-extensions.md) operador retorna um ponteiro para um **tipo** do objeto, para que esse código indica o nome do tipo **System. Int32**. Exibindo nomes de tipo é o recurso mais básico de reflexão, mas é uma técnica útil potencialmente mais inspecionar ou descobrir os valores válidos para tipos enumerados. Isso pode ser feito usando estático **Enum::GetNames** de função, que retorna uma matriz de cadeias de caracteres, cada uma contendo um valor de enumeração em formato de texto.  O exemplo a seguir recupera uma matriz de cadeias de caracteres que descreve os valores de enumeração do valor para o **opções** enum (CLR) e os exibe em um loop.  
  
 Se uma quarta opção é adicionada a **opções** enumeração, esse código relatará a nova opção sem recompilação, mesmo se a enumeração é definida em um assembly separado.  
  
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
  
```Output  
there are 3 options in enum 'Options'  
0: Option1  
1: Option2  
2: Option3  
value of 'o' is Option2  
```  
  
## <a name="example"></a>Exemplo  
 O `GetType` objeto oferece suporte a um número de membros e propriedades que podem ser usadas para examinar um tipo. Este código recupera e exibe algumas dessas informações:  
  
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
  
```Output  
type information for 'String':  
assembly name: mscorlib, Version=1.0.5000.0, Culture=neutral,   
PublicKeyToken=b77a5c561934e089  
namespace: System  
base type: System.Object  
is array: False  
is class: True  
```  
  
## <a name="example"></a>Exemplo  
 Reflexão também permite a enumeração de tipos em um assembly e os membros de classes. Para demonstrar esse recurso, defina uma classe simple:  
  
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
  
## <a name="example"></a>Exemplo  
 Se o código acima é compilado em uma DLL chamada vcpp_reflection_6.dll, você pode usar reflexão para inspecionar o conteúdo deste assembly. Isso envolve o uso de função de API de reflexão estático [Assembly::Load](https://msdn.microsoft.com/en-us/library/system.reflection.assembly.load.aspx) para carregar o assembly. Essa função retorna o endereço de um **Assembly** objeto que pode ser consultado, em seguida, sobre os módulos e tipos em.  
  
 Depois que o sistema de reflexão carrega com êxito o assembly, uma matriz de **tipo** objetos é recuperado com o [Assembly::GetTypes](https://msdn.microsoft.com/en-us/library/system.reflection.assembly.gettypes.aspx) função. Cada elemento da matriz contém informações sobre um tipo diferente, embora nesse caso, somente uma classe é definida. Usando um loop, cada **tipo** nesta matriz é consultado sobre os membros de tipo usando o **Type::GetMembers** função. Essa função retorna uma matriz de **MethodInfo** objetos, cada objeto que contém informações sobre a função de membro, o membro de dados ou a propriedade no tipo.  
  
 Observe que a lista de métodos inclui as funções explicitamente definidas em **TestClass** e as funções implicitamente herdado da **System::Object** classe. Como parte do sendo descrita no .NET, em vez de na sintaxe do Visual C++, as propriedades aparecem como membro de dados subjacente, acessado pelas funções de get/set. As funções get/set aparecem nessa lista como métodos regulares. Reflexão tem suporte o common language runtime, não pelo compilador do Visual C++.  
  
 Embora esse código é usado para inspecionar um assembly que você definiu, você também pode usar este código para inspecionar os assemblies do .NET. Por exemplo, se você alterar TestAssembly para mscorlib, você verá uma lista de cada tipo e método definido em mscorlib.dll.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)