---
title: "Problemas de vers&#227;o para tipos de valor aninhados em tipos nativos (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "declarações de tipo __nogc"
  - "Palavra-chave __value, problemas ao aninhar"
ms.assetid: 0a3b1a43-39c6-4b52-be2f-1074690188aa
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Problemas de vers&#227;o para tipos de valor aninhados em tipos nativos (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Considere um componente assinado do assembly de nome forte \(\) usado para criar um assembly do cliente.  O componente contém um tipo de valor que é usado no cliente como o tipo para um membro de uma união nativo, de uma classe, ou matriz.  Se uma futura versão do componente alterar o tamanho ou o layout do tipo de valor, o cliente deve ser recompilado.  
  
 Crie um keyfile com [sn.exe](../Topic/Sn.exe%20\(Strong%20Name%20Tool\).md) \(`sn -k mykey.snk`\).  
  
## Exemplo  
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
  
## Exemplo  
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
  
## Saída  
  
```  
S.i = 5  
S.i = 6  
S.i = 10  
S.i = 11  
```  
  
### Comentários  
 No entanto, se você adicionar outro membro a `struct S` em nested\_value\_types.cpp, \(por exemplo, `double d;`\) e recompile o componente sem recompilar o cliente, o resultado será uma exceção sem\-tratamento \(do tipo <xref:System.IO.FileLoadException?displayProperty=fullName>\).  
  
## Consulte também  
 [Tipos gerenciados](../Topic/Managed%20Types%20\(C++-CLI\).md)