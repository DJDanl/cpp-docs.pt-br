---
title: Problemas de versão para tipos de valor aninhados em tipos nativos (C + + CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- __nogc type declarations
- __value keyword, issues when nesting
ms.assetid: 0a3b1a43-39c6-4b52-be2f-1074690188aa
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 4c4f2598594930f49c1217c937c9142b3f84a47e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="version-issues-for-value-types-nested-in-native-types-ccli"></a>Problemas de versão para tipos de valor aninhados em tipos nativos (C++/CLI)
Considere a possibilidade de um componente de assembly assinado (nome forte) usado para criar um assembly de cliente. O componente contiver um tipo de valor que é usado no cliente como o tipo de um membro de uma união nativo, uma classe ou uma matriz. Se uma versão futura do componente altera o tamanho ou o layout do tipo de valor, o cliente deverá ser recompilado.  
  
 Criar um arquivo de chave com [sn.exe](/dotnet/framework/tools/sn-exe-strong-name-tool) (`sn -k mykey.snk`).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir é o componente.  
  
```  
// nested_value_types.cpp  
// compile with: /clr /LD  
using namespace System::Reflection;  
[assembly:AssemblyVersion("1.0.0.*"),   
assembly:AssemblyKeyFile("mykey.snk")];  
  
public value struct S {  
   int i;  
   void Test() {  
      System::Console::WriteLine("S.i = {0}", i);  
   }  
};  
```  
  
## <a name="example"></a>Exemplo  
 Este exemplo é o cliente:  
  
```  
// nested_value_types_2.cpp  
// compile with: /clr  
#using <nested_value_types.dll>  
  
struct S2 {  
   S MyS1, MyS2;  
};  
  
int main() {  
   S2 MyS2a, MyS2b;  
   MyS2a.MyS1.i = 5;  
   MyS2a.MyS2.i = 6;  
   MyS2b.MyS1.i = 10;  
   MyS2b.MyS2.i = 11;  
  
   MyS2a.MyS1.Test();  
   MyS2a.MyS2.Test();  
   MyS2b.MyS1.Test();  
   MyS2b.MyS2.Test();  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
S.i = 5  
S.i = 6  
S.i = 10  
S.i = 11  
```  
  
### <a name="comments"></a>Comentários  
 No entanto, se você adicionar outro membro para `struct S` em nested_value_types.cpp, (por exemplo, `double d;`) e recompile o componente sem recompilar o cliente, o resultado é uma exceção sem tratamento (do tipo <xref:System.IO.FileLoadException?displayProperty=fullName>).  
  
## <a name="see-also"></a>Consulte também  
 [Tipos gerenciados (C++/CLI)](../dotnet/managed-types-cpp-cli.md)