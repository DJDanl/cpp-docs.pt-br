---
title: "Como analisar cadeias de caracteres usando o m&#233;todo split (C++/CLI) | Microsoft Docs"
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
  - "exemplos [C++], cadeias de caracteres"
  - "analisando cadeias de caracteres [C++]"
  - "expressões regulares [C++], analisando cadeias de caracteres"
  - "Método Split, analisando cadeias de caracteres"
  - "cadeias de caracteres [C++], analisando"
ms.assetid: d52d2539-5ebb-4716-86b3-07314dd7e4bd
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como analisar cadeias de caracteres usando o m&#233;todo split (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código a seguir demonstra o uso do método de <xref:System.String.Split%2A?displayProperty=fullName> para extrair cada palavra de uma cadeia de caracteres.  Uma cadeia de caracteres que contém vários tipos de delineators do word é construída e analisada chamando <xref:System.String.Split%2A> com uma lista dos delineators.  Em seguida, cada palavra da frase são exibidas separadamente.  
  
## Exemplo  
  
```  
// regex_split.cpp  
// compile with: /clr  
using namespace System;  
  
int main()  
{  
   String^ delimStr = " ,.:\t";  
   Console::WriteLine( "delimiter : '{0}'", delimStr );  
   array<Char>^ delimiter = delimStr->ToCharArray( );  
   array<String^>^ words;  
   String^ line = "one\ttwo three:four,five six seven";  
  
   Console::WriteLine( "text : '{0}'", line );  
   words = line->Split( delimiter );  
   Console::WriteLine( "Number of Words : {0}", words->Length );  
   for (int word=0; word<words->Length; word++)  
      Console::WriteLine( "{0}", words[word] );  
  
   return 0;  
}  
```  
  
## Consulte também  
 [Expressões regulares do .NET Framework](../Topic/.NET%20Framework%20Regular%20Expressions.md)   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)