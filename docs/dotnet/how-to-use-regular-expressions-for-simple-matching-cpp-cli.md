---
title: "Como usar express&#245;es regulares para correspond&#234;ncia simples (C++/CLI) | Microsoft Docs"
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
  - "Método IsMatch"
  - "expressões regulares [C++], correspondência simples"
  - "procurando, correspondências exatas de subcadeia de caracteres"
  - "cadeias de caracteres [C++], correspondência exata de subcadeia de caracteres"
  - "subcadeias, correspondências simples"
ms.assetid: 4661f6f3-0f6d-48f2-abe4-cb4770bf9bd5
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar express&#245;es regulares para correspond&#234;ncia simples (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código usa expressões regulares para procurar correspondências exatas de subcadeia de caracteres.  A pesquisa é executada pelo método estático de <xref:System.Text.RegularExpressions.Regex.IsMatch%2A> , que usa duas cadeias de caracteres como entrada.  O primeiro é a cadeia de caracteres a ser pesquisada, e o segundo é o padrão a ser pesquisado por.  
  
## Exemplo  
  
```  
// regex_simple.cpp  
// compile with: /clr  
#using <System.dll>  
  
using namespace System;  
using namespace System::Text::RegularExpressions;  
  
int main()  
{  
   array<String^>^ sentence =   
   {  
      "cow over the moon",  
      "Betsy the Cow",  
      "cowering in the corner",  
      "no match here"  
   };  
  
   String^ matchStr = "cow";  
   for (int i=0; i<sentence->Length; i++)  
   {  
      Console::Write( "{0,24}", sentence[i] );  
      if ( Regex::IsMatch( sentence[i], matchStr,  
                     RegexOptions::IgnoreCase ) )  
         Console::WriteLine("  (match for '{0}' found)", matchStr);  
      else  
         Console::WriteLine("");  
   }  
   return 0;  
}  
```  
  
## Consulte também  
 [Expressões regulares do .NET Framework](../Topic/.NET%20Framework%20Regular%20Expressions.md)   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)