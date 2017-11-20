---
title: "Como: usar expressões regulares para reorganizar dados (C + + CLI) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- regular expressions [C++], rearranging data
- data [C++], rearranging
ms.assetid: 5f91e777-9471-424e-ba75-dca3d1b49e42
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 62154cf33ba3705c89a5ad5a520b678e3f516498
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-use-regular-expressions-to-rearrange-data-ccli"></a>Como usar expressões regulares para reorganizar dados (C++/CLI)
O exemplo de código a seguir demonstra como o suporte a expressões regulares do .NET Framework pode ser usado para reorganizar ou reformatar dados. O seguinte exemplo de código usa o <xref:System.Text.RegularExpressions.Regex> e <xref:System.Text.RegularExpressions.Match> classes para extrair os nomes e sobrenomes de uma cadeia de caracteres e, em seguida, exibir esses elementos de nome em ordem inversa.  
  
 O <xref:System.Text.RegularExpressions.Regex> classe é usada para construir uma expressão regular que descreve o formato atual dos dados. Os dois nomes devem ser separados por uma vírgula e podem usar qualquer quantidade de espaço em branco em torno da vírgula. O <xref:System.Text.RegularExpressions.Match> método é usado para analisar cada cadeia de caracteres. Se for bem-sucedido, o nome e sobrenome é recuperados do <xref:System.Text.RegularExpressions.Match> do objeto e exibido.  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Expressões regulares do .NET Framework](/dotnet/standard/base-types/regular-expressions)   
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)