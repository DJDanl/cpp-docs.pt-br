---
title: "Como usar express&#245;es regulares para pesquisar e substituir (C++/CLI) | Microsoft Docs"
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
  - "expressões regulares [C++], pesquisar e substituir"
  - "Método replace"
  - "pesquisar e substituir"
ms.assetid: 12fe3e18-fe10-4b25-a221-19dc5eab3821
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar express&#245;es regulares para pesquisar e substituir (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código a seguir demonstra como a classe <xref:System.Text.RegularExpressions.Regex> à expressão regular pode ser usada para executar a pesquisa e a ser substituído.  Isso é feito por meio do método de <xref:System.Text.RegularExpressions.Regex.Replace%2A> .  A versão usada terá duas cadeias de caracteres como entrada: a cadeia de caracteres a serem modificadas, e a cadeia de caracteres a ser inserida no lugar das seções \(se houver\) que correspondem ao padrão fornecido ao objeto de <xref:System.Text.RegularExpressions.Regex> .  
  
 Esse código substitui todos os dígitos em uma cadeia de caracteres com os sublinhados \(\_\) e substitui naquelas com uma cadeia de caracteres vazia, removendo\-os efetivamente o.  O mesmo efeito pode ser mantido em uma única etapa, mas duas etapas são usadas aqui para fins de demonstração.  
  
## Exemplo  
  
```  
// regex_replace.cpp  
// compile with: /clr  
#using <System.dll>  
using namespace System::Text::RegularExpressions;  
using namespace System;  
  
int main()  
{  
   String^ before = "The q43uick bro254wn f0ox ju4mped";  
   Console::WriteLine("original  : {0}", before);  
  
   Regex^ digitRegex = gcnew Regex("(?<digit>[0-9])");  
   String^ after = digitRegex->Replace(before, "_");  
   Console::WriteLine("1st regex : {0}", after);  
  
   Regex^ underbarRegex = gcnew Regex("_");  
   String^ after2 = underbarRegex->Replace(after, "");  
   Console::WriteLine("2nd regex : {0}", after2);  
  
   return 0;  
}  
```  
  
## Consulte também  
 [Expressões regulares do .NET Framework](../Topic/.NET%20Framework%20Regular%20Expressions.md)   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)