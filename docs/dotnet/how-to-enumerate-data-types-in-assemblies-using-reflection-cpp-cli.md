---
title: 'Como: enumerar os tipos de dados usando a reflexão (C + + CLI) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- assemblies [C++], enumerating data types in
- public types [C++]
- reflection [C++], external assemblies
- assemblies [C++]
- data types [C++], enumerating
- public members [C++]
ms.assetid: c3578e6d-bb99-4599-80e1-ab795305f878
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 5a4b85cb5af9d390d92bcca3e0462b0ae5b4d832
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33135073"
---
# <a name="how-to-enumerate-data-types-in-assemblies-using-reflection-ccli"></a>Como enumerar tipos de dados em assemblies usando reflexão (C++/CLI)
O código a seguir demonstra a enumeração de tipos e membros usando públicos <xref:System.Reflection>.  
  
 Considerando o nome de um assembly no diretório local ou no GAC, o código a seguir tenta abrir o assembly e recuperar as descrições. Se for bem-sucedido, cada tipo é exibido com seus membros públicos.  
  
 Observe que <xref:System.Reflection.Assembly.Load%2A?displayProperty=fullName> requer que nenhuma extensão de arquivo é usado. Portanto, usando "mscorlib" como um argumento de linha de comando falhará, enquanto usar apenas "mscorlib" resultará a exibição de tipos do .NET Framework. Se nenhum nome de assembly for fornecido, o código detectará e relatar os tipos de dentro do assembly atual (o EXE resultantes desse código).  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Reflexão (C++/CLI)](../dotnet/reflection-cpp-cli.md)