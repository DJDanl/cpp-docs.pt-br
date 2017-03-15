---
title: "Como analisar cadeias de caracteres usando express&#245;es regulares (C++/CLI) | Microsoft Docs"
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
  - "cadeias de caracteres [C++], analisando"
ms.assetid: 5b0c7ca3-9bba-4389-a45c-6d373cff91b0
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como analisar cadeias de caracteres usando express&#245;es regulares (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código a seguir demonstra a análise simples de cadeia de caracteres usando a classe de <xref:System.Text.RegularExpressions.Regex> no namespace de <xref:System.Text.RegularExpressions?displayProperty=fullName> .  Uma cadeia de caracteres que contém vários tipos de delineators do word é construída.  A cadeia de caracteres é analisada com a classe de <xref:System.Text.RegularExpressions.Regex> junto com a classe de <xref:System.Text.RegularExpressions.Match> .  Em seguida, cada palavra da frase são exibidas separadamente.  
  
## Exemplo  
  
```  
// regex_parse.cpp  
// compile with: /clr  
#using <system.dll>  
  
using namespace System;  
using namespace System::Text::RegularExpressions;  
  
int main( )  
{  
   int words = 0;  
   String^ pattern = "[a-zA-Z]*";  
   Console::WriteLine( "pattern : '{0}'", pattern );  
   Regex^ regex = gcnew Regex( pattern );  
  
   String^ line = "one\ttwo three:four,five six  seven";     
   Console::WriteLine( "text : '{0}'", line );  
   for( Match^ match = regex->Match( line );   
        match->Success; match = match->NextMatch( ) )   
   {  
      if( match->Value->Length > 0 )  
      {  
         words++;  
         Console::WriteLine( "{0}", match->Value );  
      }  
   }  
   Console::WriteLine( "Number of Words : {0}", words );  
  
   return 0;  
}  
```  
  
## Consulte também  
 [Expressões regulares do .NET Framework](../Topic/.NET%20Framework%20Regular%20Expressions.md)   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)