---
title: "Como usar express&#245;es regulares para reorganizar dados (C++/CLI) | Microsoft Docs"
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
  - "dados [C++], reorganizando"
  - "expressões regulares [C++], reorganizando dados"
ms.assetid: 5f91e777-9471-424e-ba75-dca3d1b49e42
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar express&#245;es regulares para reorganizar dados (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código a seguir demonstra como o suporte à expressão regular do .NET Framework pode ser usado para reorganizar, ou reformata dados.  O exemplo de código usa <xref:System.Text.RegularExpressions.Regex> e as classes de <xref:System.Text.RegularExpressions.Match> para extrair nomes e sobrenomes de uma cadeia de caracteres e exibir nesses nomes os elementos em ordem inversa.  
  
 A classe de <xref:System.Text.RegularExpressions.Regex> é usada para construir uma expressão regular que descreve o formato de dados atual.  Os dois nomes são assumidos para serem separados por uma vírgula e podem usar qualquer quantidade de espaço em branco em torno de vírgula.  O método de <xref:System.Text.RegularExpressions.Match> é usado para analisar cada cadeia de caracteres.  Se tiver êxito, os nomes e sobrenomes são recuperados do objeto de <xref:System.Text.RegularExpressions.Match> e exibidos.  
  
## Exemplo  
  
```  
// regex_reorder.cpp  
// compile with: /clr  
#using <System.dll>  
using namespace System;  
using namespace Text::RegularExpressions;  
  
int main()  
{  
   array<String^>^ name =   
   {  
      "Abolrous, Sam",   
      "Berg,Matt",   
      "Berry , Jo",  
      "www.contoso.com"  
   };  
  
   Regex^ reg = gcnew Regex("(?<last>\\w*)\\s*,\\s*(?<first>\\w*)");  
  
   for ( int i=0; i < name->Length; i++ )  
   {  
      Console::Write( "{0,-20}", name[i] );  
      Match^ m = reg->Match( name[i] );  
      if ( m->Success )  
      {  
         String^ first = m->Groups["first"]->Value;  
         String^ last = m->Groups["last"]->Value;  
         Console::WriteLine("{0} {1}", first, last);  
      }  
      else  
         Console::WriteLine("(invalid)");  
   }  
   return 0;  
}  
```  
  
## Consulte também  
 [Expressões regulares do .NET Framework](../Topic/.NET%20Framework%20Regular%20Expressions.md)   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)