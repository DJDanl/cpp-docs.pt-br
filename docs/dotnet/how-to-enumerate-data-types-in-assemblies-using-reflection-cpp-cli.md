---
title: "Como enumerar tipos de dados em assemblies usando reflex&#227;o (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "assemblies [C++]"
  - "assemblies [C++], enumerando tipos de dados em"
  - "tipos de dados [C++], enumerando"
  - "membros públicos [C++]"
  - "tipos públicos [C++]"
  - "reflexão [C++], assemblies externos"
ms.assetid: c3578e6d-bb99-4599-80e1-ab795305f878
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como enumerar tipos de dados em assemblies usando reflex&#227;o (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O código a seguir demonstra a enumeração dos tipos e os membros públicos que usam <xref:System.Reflection>.  
  
 Dado o nome de um assembly, no diretório local ou no GAC, no código abaixo do tentar abrir o assembly e de recuperar descrições.  Se bem\-sucedido, cada tipo é exibido com seus membros públicos.  
  
 Observe que <xref:System.Reflection.Assembly.Load%2A?displayProperty=fullName> requer que nenhuma extensão de arquivo é usada.  Consequentemente, usando “mscorlib.dll” porque um argumento de linha de comando falhará, quando usar apenas o “mscorlib” resultará na exibição dos tipos do.NET Framework.  Se nenhum nome do assembly for fornecido, o código detectará e relatará os tipos no assembly atual \(EXE resultante desse código\).  
  
## Exemplo  
  
```  
// self_reflection.cpp  
// compile with: /clr  
using namespace System;  
using namespace System::Reflection;  
using namespace System::Collections;  
  
public ref class ExampleType {  
public:  
   ExampleType() {}  
   void Func() {}  
};  
  
int main() {  
   String^ delimStr = " ";  
   array<Char>^ delimiter = delimStr->ToCharArray( );  
   array<String^>^ args = Environment::CommandLine->Split( delimiter );  
  
// replace "self_reflection.exe" with an assembly from either the local  
// directory or the GAC  
   Assembly^ a = Assembly::LoadFrom("self_reflection.exe");  
   Console::WriteLine(a);  
  
   int count = 0;  
   array<Type^>^ types = a->GetTypes();  
   IEnumerator^ typeIter = types->GetEnumerator();  
  
   while ( typeIter->MoveNext() ) {  
      Type^ t = dynamic_cast<Type^>(typeIter->Current);  
      Console::WriteLine("   {0}", t->ToString());  
  
      array<MemberInfo^>^ members = t->GetMembers();  
      IEnumerator^ memberIter = members->GetEnumerator();  
      while ( memberIter->MoveNext() ) {  
         MemberInfo^ mi = dynamic_cast<MemberInfo^>(memberIter->Current);  
         Console::Write("      {0}", mi->ToString( ) );  
         if (mi->MemberType == MemberTypes::Constructor)  
            Console::Write("   (constructor)");  
  
         Console::WriteLine();  
      }  
      count++;  
   }  
   Console::WriteLine("{0} types found", count);  
}  
```  
  
## Consulte também  
 [Reflexão](../dotnet/reflection-cpp-cli.md)